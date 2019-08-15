#include <golos/plugins/chain/plugin.hpp>
#include <golos/chain/database_exceptions.hpp>
#include <golos/chain/comment_object.hpp>
#include <golos/protocol/protocol.hpp>
#include <golos/protocol/types.hpp>

#include <fc/io/json.hpp>
#include <fc/string.hpp>

#include <iostream>
#include <future>

namespace golos { namespace plugins { namespace chain {

    namespace bfs = boost::filesystem;
    namespace bpo = boost::program_options;
    using fc::flat_map;
    using protocol::block_id_type;

    class plugin::impl final {
    public:
        uint64_t shared_memory_size = 0;
        bfs::path shared_memory_dir;
        bool replay = false;
        bool replay_if_corrupted = true;
        bool force_replay = false;
        bool resync = false;
        bool readonly = false;
        bool check_locks = false;
        bool validate_invariants = false;
        uint32_t flush_interval = 0;
        flat_map<uint32_t, block_id_type> loaded_checkpoints;

        uint32_t allow_future_time = 5;

        uint64_t read_wait_micro;
        uint32_t max_read_wait_retries;

        uint64_t write_wait_micro;
        uint32_t max_write_wait_retries;

        size_t inc_shared_memory_size;
        size_t min_free_shared_memory_size;

        uint32_t clear_votes_before_block = 0;
        uint32_t clear_votes_older_n_blocks = 0xFFFFFFFF;
        bool enable_plugins_on_push_transaction;

        uint32_t block_num_check_free_size = 0;

        bool skip_virtual_ops = false;

        golos::chain::database db;

        bool single_write_thread = false;

        golos::chain::database::store_metadata_modes store_account_metadata;
        std::vector<std::string> accounts_to_store_metadata;
        bool store_memo_in_savings_withdraws = true;

        impl() {
            // get default settings
            read_wait_micro = db.read_wait_micro();
            max_read_wait_retries = db.max_read_wait_retries();

            write_wait_micro = db.write_wait_micro();
            max_write_wait_retries = db.max_write_wait_retries();
        }

        // HELPERS
        boost::asio::io_service& io_service() {
            return appbase::app().get_io_service();
        }

        void check_time_in_block(const protocol::signed_block& block);
        bool accept_block(const protocol::signed_block& block, bool currently_syncing, uint32_t skip);
        void accept_transaction(const protocol::signed_transaction& trx);
        void wipe_db(const bfs::path& data_dir, bool wipe_block_log);
        void replay_db(const bfs::path& data_dir, bool force_replay);

        void on_block (const protocol::signed_block& b);
    };


    void plugin::impl::on_block(const protocol::signed_block& b) {
        auto n = b.block_num();
        bool del_any = n < clear_votes_before_block;
        const auto now = db.head_block_time();    // don't make one constant from now and ttl because of overflow
        const auto ttl = uint64_t(clear_votes_older_n_blocks) * STEEMIT_BLOCK_INTERVAL;

        const auto& idx = db.get_index<golos::chain::comment_vote_index>().indices().get<golos::chain::by_vote_last_update>();
        auto itr = idx.begin();
        while (itr != idx.end() && itr->num_changes < 0 && (del_any || now - itr->last_update > fc::seconds(ttl))) {
            const auto& vote = *itr;
            ++itr;
            db.remove(vote);
        }
    }

    void plugin::impl::check_time_in_block(const protocol::signed_block& block) {
        time_point_sec now = fc::time_point::now();

        uint64_t max_accept_time = now.sec_since_epoch();
        max_accept_time += allow_future_time;
        GOLOS_CHECK_VALUE(block.timestamp.sec_since_epoch() <= max_accept_time, 
                "Block timestamp is too far in the future",
                ("timestamp", block.timestamp.sec_since_epoch())
                ("max_accept_time", max_accept_time));
    }

    bool plugin::impl::accept_block(const protocol::signed_block& block, bool currently_syncing, uint32_t skip) {
        if (currently_syncing && block.block_num() % 10000 == 0) {
            ilog("Syncing Blockchain --- Got block: #${n} time: ${t} producer: ${p}",
                ("t", block.timestamp)("n", block.block_num())("p", block.witness));
        }

        check_time_in_block(block);

        skip = db.validate_block(block, skip);

        if (single_write_thread) {
            std::promise<bool> promise;
            auto result = promise.get_future();

            io_service().post([&]{
                try {
                    promise.set_value(db.push_block(block, skip));
                } catch (...) {
                    promise.set_exception(std::current_exception());
                }
            });
            return result.get(); // if an exception was, it will be thrown
        } else {
            return db.push_block(block, skip);
        }
    }

    void plugin::impl::wipe_db(const bfs::path& data_dir, bool wipe_block_log) {
        if (wipe_block_log) {
            ilog("Wiping blockchain with block log.");
        } else {
            ilog("Wiping blockchain.");
        }

        db.wipe(data_dir, shared_memory_dir, wipe_block_log);
        db.open(data_dir, shared_memory_dir, STEEMIT_INIT_SUPPLY, shared_memory_size, chainbase::database::read_write/*, validate_invariants*/);
    };

    void plugin::impl::replay_db(const bfs::path& data_dir, bool force_replay) {
        auto head_block_log = db.get_block_log().head();
        force_replay |= head_block_log && db.revision() >= head_block_log->block_num();

        if (force_replay) {
            wipe_db(data_dir, false);
        }

        auto from_block_num = force_replay ? 1 : db.head_block_num() + 1;

        ilog("Replaying blockchain from block num ${from}.", ("from", from_block_num));
        db.reindex(data_dir, shared_memory_dir, from_block_num, shared_memory_size);
    };

    void plugin::impl::accept_transaction(const protocol::signed_transaction& trx) {
        uint32_t skip = db.validate_transaction(trx, db.skip_apply_transaction);

        if (single_write_thread) {
            std::promise<bool> promise;
            auto wait = promise.get_future();

            io_service().post([&]{
                try {
                    db.push_transaction(trx, skip);
                    promise.set_value(true);
                } catch (...) {
                    promise.set_exception(std::current_exception());
                }
            });
            wait.get(); // if an exception was, it will be thrown
        } else {
            db.push_transaction(trx, skip);
        }
    }

    plugin::plugin() {
    }

    plugin::~plugin() {
    }

    golos::chain::database& plugin::db() {
        return my->db;
    }

    const golos::chain::database& plugin::db() const {
        return my->db;
    }

    void plugin::set_program_options(bpo::options_description& cli, bpo::options_description& cfg) {
        cfg.add_options()
            (
                "shared-file-dir", bpo::value<bfs::path>()->default_value("blockchain"),
                "the location of the chain shared memory files (absolute path or relative to application data dir)"
            ) (
                "shared-file-size", bpo::value<std::string>()->default_value("2G"),
                "Start size of the shared memory file. Default: 2G"
            ) (
                "inc-shared-file-size", bpo::value<std::string>()->default_value("2G"),
                "Increasing size on reaching limit of free space in shared memory file (see min-free-shared-file-size). Default: 2G"
            ) (
                "min-free-shared-file-size", bpo::value<std::string>()->default_value("500M"),
                "Minimum free space in shared memory file (see inc-shared-file-size). Default: 500M"
            ) (
                "block-num-check-free-size", bpo::value<uint32_t>()->default_value(1000),
                "Check free space in shared memory each N blocks. Default: 1000 (each 3000 seconds)."
            ) (
                "checkpoint", bpo::value<std::vector<std::string>>()->composing(),
                "Pairs of [BLOCK_NUM,BLOCK_ID] that should be enforced as checkpoints."
            ) (
                "flush-state-interval", bpo::value<uint32_t>(),
                "flush shared memory changes to disk every N blocks"
            ) (
                "read-wait-micro", bpo::value<uint64_t>(),
                "maximum microseconds for trying to get read lock"
            ) (
                "max-read-wait-retries", bpo::value<uint32_t>(),
                "maximum number of retries to get read lock"
            ) (
                "write-wait-micro", bpo::value<uint64_t>(),
                "maximum microseconds for trying to get write lock"
            ) (
                "max-write-wait-retries", bpo::value<uint32_t>(),
                "maximum number of retries to get write lock"
            ) (
                "single-write-thread", bpo::value<bool>()->default_value(false),
                "push blocks and transactions from one thread"
            ) (
                "clear-votes-before-block", bpo::value<uint32_t>()->default_value(0),
                "remove votes before defined block, should speedup initial synchronization"
            ) (
                "clear-votes-older-n-blocks", bpo::value<uint32_t>()->default_value(0xFFFFFFFF),
                "if set, remove votes older than specified number of blocks. "
                "-1 = do not remove; 0 = remove after cashout; any other value N - remove votes older than N blocks. "
                "note: votes don't removed before post cashout"
            ) (
                "skip-virtual-ops", bpo::value<bool>()->default_value(false),
                "virtual operations will not be passed to the plugins, helps to save some memory"
            ) (
                "enable-plugins-on-push-transaction", bpo::value<bool>()->default_value(true),
                "enable calling of plugins for operations on push_transaction"
            ) (
                "replay-if-corrupted", bpo::bool_switch()->default_value(true),
                "replay all blocks if shared memory is corrupted"
            ) (
                "store-account-metadata", bpo::value<bool>(),
                "store account metadata for all accounts if true, for no one if else, otherwise for specified in store-account-metadata-list"
            ) (
                "store-account-metadata-list", bpo::value<std::string>(),
                "names of accounts to store metadata"
            ) (
                "store-memo-in-savings-withdraws", bpo::value<bool>()->default_value(true),
                "store memo for all savings withdraws"
            ) (//TODO delete after HF21
                "serialize-state", bpo::value<std::string>()->default_value(''),
                "The location of the file to serialize state to (abs path or relative to application data dir). "
                "If set then app will exit after serialization."
            ) (//TODO delete after HF21
                "serialize-delay-sec", bpo::value<long>()->default_value(5*60),
                "The delay in seconds before the state is serialized, which will be used for CyberWay genesis."
            );
        //  Do not use bool_switch() in cfg!
        cli.add_options()
            (
                "replay-blockchain", bpo::bool_switch()->default_value(false),
                "clear chain database and replay all blocks"
            ) (
                "force-replay-blockchain", bpo::bool_switch()->default_value(false),
                "force clear chain database and replay all blocks"
            ) (
                "resync-blockchain", bpo::bool_switch()->default_value(false),
                "clear chain database and block log"
            ) (
                "check-locks", bpo::bool_switch()->default_value(false),
                "Check correctness of chainbase locking"
            ) (
                "validate-database-invariants", bpo::bool_switch()->default_value(false),
                "Validate all supply invariants check out"
            );
    }

    void plugin::plugin_initialize(const bpo::variables_map& options) {
        my.reset(new impl());

        my->db.applied_block.connect([&](const protocol::signed_block& b) {
            my->on_block(b);
        });

        auto sfd = options.at("shared-file-dir").as<bfs::path>();
        if (sfd.is_relative()) {
            my->shared_memory_dir = appbase::app().data_dir() / sfd;
        } else {
            my->shared_memory_dir = sfd;
        }

        if (options.count("read-wait-micro")) {
            my->read_wait_micro = options.at("read-wait-micro").as<uint64_t>();
        }

        if (options.count("max-read-wait-retries")) {
            my->max_read_wait_retries = options.at("max-read-wait-retries").as<uint32_t>();
        }

        if (options.count("write-wait-micro")) {
            my->write_wait_micro = options.at("write-wait-micro").as<uint64_t>();
        }

        if (options.count("max-write-wait-retries")) {
            my->max_write_wait_retries = options.at("max-write-wait-retries").as<uint32_t>();
        }

        my->single_write_thread = options.at("single-write-thread").as<bool>();

        my->enable_plugins_on_push_transaction = options.at("enable-plugins-on-push-transaction").as<bool>();

        my->shared_memory_size = fc::parse_size(options.at("shared-file-size").as<std::string>());
        my->inc_shared_memory_size = fc::parse_size(options.at("inc-shared-file-size").as<std::string>());
        my->min_free_shared_memory_size = fc::parse_size(options.at("min-free-shared-file-size").as<std::string>());
        my->clear_votes_before_block = options.at("clear-votes-before-block").as<uint32_t>();
        my->clear_votes_older_n_blocks = options.at("clear-votes-older-n-blocks").as<uint32_t>();
        my->skip_virtual_ops = options.at("skip-virtual-ops").as<bool>();

        if (options.count("block-num-check-free-size")) {
            my->block_num_check_free_size = options.at("block-num-check-free-size").as<uint32_t>();
        }

        my->replay = options.at("replay-blockchain").as<bool>();
        my->replay_if_corrupted = options.at("replay-if-corrupted").as<bool>();
        my->force_replay = options.at("force-replay-blockchain").as<bool>();
        my->resync = options.at("resync-blockchain").as<bool>();
        my->check_locks = options.at("check-locks").as<bool>();
        my->validate_invariants = options.at("validate-database-invariants").as<bool>();
        if (options.count("flush-state-interval")) {
            my->flush_interval = options.at("flush-state-interval").as<uint32_t>();
        } else {
            my->flush_interval = 10000;
        }

        if (options.count("checkpoint")) {
            auto cps = options.at("checkpoint").as<std::vector<std::string>>();
            my->loaded_checkpoints.reserve(cps.size());
            for (const auto& cp : cps) {
                auto item = fc::json::from_string(cp).as<std::pair<uint32_t, protocol::block_id_type>>();
                my->loaded_checkpoints[item.first] = item.second;
            }
        }

        my->store_account_metadata = golos::chain::database::store_metadata_for_all;

        if (options.count("store-account-metadata-list")) {
            my->store_account_metadata = golos::chain::database::store_metadata_for_listed;
            std::string str_accs = options["store-account-metadata-list"].as<std::string>();
            my->accounts_to_store_metadata = fc::json::from_string(str_accs).as<std::vector<std::string>>();
        }

        if (options.count("store-account-metadata")) {
            if (!options.at("store-account-metadata").as<bool>()) {
                my->store_account_metadata = golos::chain::database::store_metadata_for_nobody;
                wlog(
                    "Account metadata will be not stored for any item of store-account-metadata-list"
                    " because store-account-metadata is false");
            }
        }

        my->store_memo_in_savings_withdraws = options.at("store-memo-in-savings-withdraws").as<bool>();
    }

    void plugin::plugin_startup() {
        if (skip_startup) return;

        ilog("Starting chain with shared_file_size: ${n} bytes", ("n", my->shared_memory_size));

        auto data_dir = appbase::app().data_dir() / "blockchain";

        if (my->resync) {
            wlog("resync requested: deleting block log and shared memory");
            my->db.wipe(data_dir, my->shared_memory_dir, true);
        }

        my->db.set_flush_interval(my->flush_interval);
        my->db.add_checkpoints(my->loaded_checkpoints);
        my->db.set_require_locking(my->check_locks);

        my->db.set_read_wait_micro(my->read_wait_micro);
        my->db.set_max_read_wait_retries(my->max_read_wait_retries);
        my->db.set_write_wait_micro(my->write_wait_micro);
        my->db.set_max_write_wait_retries(my->max_write_wait_retries);

        my->db.set_inc_shared_memory_size(my->inc_shared_memory_size);
        my->db.set_min_free_shared_memory_size(my->min_free_shared_memory_size);


        my->db.set_store_account_metadata(my->store_account_metadata);

        my->db.set_accounts_to_store_metadata(my->accounts_to_store_metadata);

        my->db.set_store_memo_in_savings_withdraws(my->store_memo_in_savings_withdraws);

        if (my->skip_virtual_ops) {
            my->db.set_skip_virtual_ops();
        }

        if (my->block_num_check_free_size) {
            my->db.set_block_num_check_free_size(my->block_num_check_free_size);
        }

        my->db.enable_plugins_on_push_transaction(my->enable_plugins_on_push_transaction);

        try {
            ilog("Opening shared memory from ${path}", ("path", my->shared_memory_dir.generic_string()));
            my->db.open(data_dir, my->shared_memory_dir, STEEMIT_INIT_SUPPLY, my->shared_memory_size, chainbase::database::read_write/*, my->validate_invariants*/);
            auto head_block_log = my->db.get_block_log().head();
            my->replay |= head_block_log && my->db.revision() != head_block_log->block_num();

            if (my->replay) {
                my->replay_db(data_dir, my->force_replay);
            }
        } catch (const golos::chain::database_revision_exception&) {
            if (my->replay_if_corrupted) {
                wlog("Error opening database, attempting to replay blockchain.");
                my->force_replay |= my->db.revision() >= my->db.head_block_num();
                try {
                    my->replay_db(data_dir, my->force_replay);
                } catch (const golos::chain::block_log_exception&) {
                    wlog("Error opening block log. Having to resync from network...");
                    my->wipe_db(data_dir, true);
                }
            } else {
                wlog("Error opening database, quiting. If should replay, set replay-if-corrupted in config.ini to true.");
                std::exit(0); // TODO Migrate to appbase::app().quit()
                return;
            }
        } catch (...) {
            if (my->replay_if_corrupted) {
                wlog("Error opening database, attempting to replay blockchain.");
                try {
                    my->replay_db(data_dir, true);
                } catch (const golos::chain::block_log_exception&) {
                    wlog("Error opening block log. Having to resync from network...");
                    my->wipe_db(data_dir, true);
                }
            } else {
                wlog("Error opening database, quiting. If should replay, set replay-if-corrupted in config.ini to true.");
                std::exit(0); // TODO Migrate to appbase::app().quit()
                return;
            }
        }

        ilog("Started on blockchain with ${n} blocks", ("n", my->db.head_block_num()));
        on_sync();
    }

    void plugin::plugin_shutdown() {
        ilog("closing chain database");
        my->db.close();
        ilog("database closed successfully");
    }

    bool plugin::accept_block(const protocol::signed_block& block, bool currently_syncing, uint32_t skip) {
        return my->accept_block(block, currently_syncing, skip);
    }

    void plugin::accept_transaction(const protocol::signed_transaction& trx) {
        my->accept_transaction(trx);
    }

    bool plugin::block_is_on_preferred_chain(const protocol::block_id_type& block_id) {
        // If it's not known, it's not preferred.
        if (!db().is_known_block(block_id)) {
            return false;
        }

        // Extract the block number from block_id, and fetch that block number's ID from the database.
        // If the database's block ID matches block_id, then block_id is on the preferred chain. Otherwise, it's on a fork.
        return db().get_block_id_for_num(protocol::block_header::num_from_id(block_id)) == block_id;
    }

    void plugin::check_time_in_block(const protocol::signed_block& block) {
        my->check_time_in_block(block);
    }

} } } // golos::plugins::chain
