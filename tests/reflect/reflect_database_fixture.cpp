#include <golos/plugins/chain/plugin.hpp>
#include <golos/plugins/p2p/p2p_plugin.hpp>
#include <golos/plugins/webserver/webserver_plugin.hpp>
#include <golos/plugins/network_broadcast_api/network_broadcast_api_plugin.hpp>
#include <golos/plugins/witness/witness.hpp>
#include <golos/plugins/database_api/plugin.hpp>
#include <golos/plugins/market_history/market_history_plugin.hpp>
#include <golos/plugins/test_api/test_api_plugin.hpp>
#include <golos/plugins/social_network/social_network.hpp>
#include <golos/plugins/account_history/plugin.hpp>
#include <golos/plugins/blockchain_statistics/plugin.hpp>
#include <golos/plugins/account_by_key/account_by_key_plugin.hpp>
#include <golos/plugins/private_message/private_message_plugin.hpp>
#include <golos/plugins/auth_util/plugin.hpp>
#include <golos/plugins/debug_node/plugin.hpp>
#include <golos/plugins/raw_block/plugin.hpp>
#include <golos/plugins/block_info/plugin.hpp>
#include <golos/plugins/test_api/test_api_plugin.hpp>

#include <golos/protocol/types.hpp>
#include <fc/crypto/base58.hpp>
#include <golos/plugins/social_network/api_object/discussion_index.hpp>
#include <golos/plugins/social_network/api_object/discussion_query.hpp>
#include <golos/plugins/social_network/api_object/category_index.hpp>
#include <golos/plugins/social_network/api_object/tag_index.hpp>
#include <golos/plugins/social_network/languages/language_object.hpp>
#include <golos/plugins/social_network/languages/language_visitor.hpp>
#include <random>
#include <golos/plugins/follow/follow_operations.hpp>
#include <golos/plugins/follow/plugin.hpp>
#include <golos/plugins/market_history/market_history_objects.hpp>
#include <golos/protocol/protocol.hpp>
#include <golos/wallet/remote_node_api.hpp>
#include <golos/wallet/wallet.hpp>




#include <boost/test/unit_test.hpp>
#include <boost/program_options.hpp>

#include <golos/time/time.hpp>
#include <graphene/utilities/tempdir.hpp>

#include <golos/chain/steem_objects.hpp>
#include <golos/chain/history_object.hpp>

#include <fc/crypto/digest.hpp>
#include <fc/smart_ref_impl.hpp>


#include <golos/chain/index.hpp>
#include <golos/chain/operation_notification.hpp>
#include <golos/chain/steem_objects.hpp>
#include <golos/chain/account_object.hpp>
#include "reflect_database_fixture.hpp"



namespace golos {
namespace chain {

uint32_t STEEMIT_TESTING_GENESIS_TIMESTAMP = 1431700000;
using std::cout;
using std::cerr;
using namespace golos::plugins;
using golos::plugins::json_rpc::msg_pack;


reflect_database_fixture::~reflect_database_fixture() {
    close_database();
}

void reflect_database_fixture::initialize() {
    int argc = boost::unit_test::framework::master_test_suite().argc;
    char **argv = boost::unit_test::framework::master_test_suite().argv;
    for (int i = 1; i < argc; i++) {
        const std::string arg = argv[i];
        if (arg == "--record-assert-trip") {
            fc::enable_record_assert_trip = true;
        }
        if (arg == "--show-test-names") {
            std::cout << "running test "
                      << boost::unit_test::framework::current_test_case().p_name
                      << std::endl;
        }
    }

    ch_plugin = &appbase::app().register_plugin<golos::plugins::chain::plugin>();
    // ah_plugin = &appbase::app().register_plugin<account_history::plugin>();
    // db_plugin = &appbase::app().register_plugin<debug_node::plugin>();

    appbase::app().initialize<
            golos::plugins::chain::plugin
            // golos::plugins::chain::plugin,
            // account_history::plugin,
            // debug_node::plugin
    >( argc, argv );

    // auto & db = ch_plugin->db();
    db = & appbase::app().get_plugin<golos::plugins::chain::plugin>().db();

    add_plugin_index < golos::plugins::market_history::bucket_index > (*db);
    add_plugin_index < golos::plugins::market_history::order_history_index > (*db);
    add_plugin_index < golos::plugins::private_message::message_index>(*db);
    add_plugin_index < golos::plugins::social_network::tags::tag_index>(*db);
    add_plugin_index < golos::plugins::social_network::tags::tag_stats_index>(*db);
    add_plugin_index < golos::plugins::social_network::tags::peer_stats_index>(*db);
    add_plugin_index < golos::plugins::social_network::tags::author_tag_stats_index>(*db);
    add_plugin_index < golos::plugins::social_network::languages::language_index>(*db);
    add_plugin_index < golos::plugins::social_network::languages::language_stats_index>(*db);
    add_plugin_index < golos::plugins::social_network::languages::peer_stats_index>(*db);
    add_plugin_index < golos::plugins::social_network::languages::author_language_stats_index>(*db);
    add_plugin_index < golos::plugins::follow::follow_index>(*db);
    add_plugin_index < golos::plugins::follow::feed_index>(*db);
    add_plugin_index < golos::plugins::follow::blog_index>(*db);
    add_plugin_index < golos::plugins::follow::reputation_index>(*db);
    add_plugin_index < golos::plugins::follow::follow_count_index>(*db);
    add_plugin_index < golos::plugins::follow::blog_author_stats_index>(*db);
    add_plugin_index < golos::plugins::account_by_key::key_lookup_index>(*db);

    BOOST_REQUIRE( db );
}

void reflect_database_fixture::open_database() {
    if (!data_dir) {
        data_dir = fc::temp_directory(golos::utilities::temp_directory_path());
        db->_log_hardforks = false;
        db->open(data_dir->path(), data_dir->path(), INITIAL_TEST_SUPPLY,
                1024 * 1024 *
                8, chainbase::database::read_write); // 8 MB file for testing
    }
}

void reflect_database_fixture::close_database() {
    if (data_dir) {
        db->wipe(data_dir->path(), data_dir->path(), true);
    }
}

}
} // golos::chain
