#include <golos/plugins/elastic_search/elastic_search_plugin.hpp>
#include <golos/plugins/elastic_search/elastic_search_objects.hpp>
#include <golos/chain/operation_notification.hpp>

#include <golos/plugins/json_rpc/plugin.hpp>
#include <golos/plugins/chain/plugin.hpp>
#include <golos/protocol/block.hpp>


namespace golos {
namespace plugins {
namespace elastic_search {

    using namespace golos::chain;

    class elastic_search_plugin::elastic_search_plugin_impl {
    public:
        elastic_search_plugin_impl(elastic_search_plugin &plugin)
                : _my(plugin),
                  _db(appbase::app().get_plugin<golos::plugins::chain::plugin>().db()) {
        }

        ~elastic_search_plugin_impl() = default;

        void update_account_history(const operation_notification & op_notif);

        golos::chain::database &database() const {
            return _db;
        }

        bool _elasticsearch_visitor = false;

        uint32_t _elasticsearch_bulk_replay = 10000;
        uint32_t _elasticsearch_bulk_sync = 100;

        elastic_search_plugin &_my;

    private:

        golos::chain::database &_db;

        void add_elasticsearch(const account_name_type acct_id, const operation_history_object& oho, const signed_block& b);
        void createBulkLine(account_transaction_history_object ath, operation_history_struct os, int op_type, block_struct bs, visitor_struct vs);
        void sendBulk(std::string _node_url, bool _elasticsearch_logs);
    };


    void elastic_search_plugin::elastic_search_plugin_impl::update_account_history(const operation_notification & op_notif)
    {
        const operation& oper = op_notif.op;

        //_db.post_apply_operation
        golos::chain::database& db = database();
        operation_history_object oho;

        db.create<operation_history_object>([&](operation_history_object &h) {
            h.op            = op_notif.op;
            h.block         = op_notif.block;
            h.trx_in_block  = op_notif.trx_in_block;
            h.op_in_trx     = op_notif.op_in_trx;
            h.virtual_op    = op_notif.virtual_op;
        });

        // get the set of accounts this operation applies to
        flat_set<account_name_type> impacted;
        vector<authority> other;

        /*
        operation_get_required_authorities( op.op, impacted, impacted, other ); // fee_payer is added here

        if( op.op.which() == operation::tag< account_create_operation >::value )
            impacted.insert( op.result.get<object_id_type>() );
        else
            graphene::app::operation_get_impacted_accounts( op.op, impacted );

        for( auto& a : other )
            for( auto& item : a.account_auths )
                impacted.insert( item.first );

        for( auto& account_id : impacted )
        {
            add_elasticsearch( account_id, oho, b );
        }
        */
    }

    void elastic_search_plugin::elastic_search_plugin_impl::add_elasticsearch(
            const account_name_type account_id, const operation_history_object& oho, const signed_block& b)
    {
        golos::chain::database& db = database();
        const auto &stats_obj = account_id(db).statistics(db);

        // add new entry
        const auto &ath = db.create<account_transaction_history_object>([&](account_transaction_history_object &obj) {
            obj.account = account_id;
            obj.sequence = stats_obj.total_ops + 1;
        });

        /*// keep stats growing as no op will be removed
        db.modify(stats_obj, [&](account_statistics_object &obj) {
            obj.most_recent_op = ath.id;
            obj.total_ops = ath.sequence;
        });*/

        // operation_type
        int op_type = oho.op.which();

        // operation history data
        operation_history_struct os;
        os.trx_in_block = oho.trx_in_block;
        os.op_in_trx = oho.op_in_trx;
        os.virtual_op = oho.virtual_op;
        os.op = fc::json::to_string(oho.op);

        // visitor data
        visitor_struct vs;
        if(_elasticsearch_visitor) {
            operation_visitor o_v;
            oho.op.visit(o_v);

            vs.transfer_data.amount = o_v.transfer_amount;
            vs.transfer_data.from = o_v.transfer_from;
            vs.transfer_data.to = o_v.transfer_to;
        }

        // block data
        std::string trx_id = "";
        if(!b.transactions.empty() && oho.trx_in_block < b.transactions.size()) {
            trx_id = b.transactions[oho.trx_in_block].id().str();
        }
        block_struct bs;
        bs.block_num = b.block_num();
        bs.block_time = b.timestamp;
        bs.trx_id = trx_id;

        // check if we are in replay or in sync and change number of bulk documents accordingly
        uint32_t limit_documents = 0;
        if((fc::time_point::now() - b.timestamp) < fc::seconds(30))
            limit_documents = _elasticsearch_bulk_sync;
        else
            limit_documents = _elasticsearch_bulk_replay;

        createBulkLine(ath, os, op_type, bs, vs); // we have everything, creating bulk line

        /*if (curl && bulk.size() >= limit_documents) { // we are in bulk time, ready to add data to elasticsearech
            sendBulk(_elasticsearch_node_url, _elasticsearch_logs);
        }*/
    }

    void elastic_search_plugin::elastic_search_plugin_impl::createBulkLine(
            account_transaction_history_object ath, operation_history_struct os, int op_type, block_struct bs, visitor_struct vs)
    {

    }

    void elastic_search_plugin::elastic_search_plugin_impl::sendBulk(std::string _elasticsearch_node_url, bool _elasticsearch_logs)
    {

    }

    // Plugin
    elastic_search_plugin::elastic_search_plugin() {
    }

    elastic_search_plugin::~elastic_search_plugin() {
    }

    void elastic_search_plugin::set_program_options(
            boost::program_options::options_description &cli,
            boost::program_options::options_description &cfg) {
        cli.add_options()
                ("elasticsearch-node-url",
                 boost::program_options::value<std::string>(), "Elastic Search database node url");
        cfg.add(cli);
    }

    void elastic_search_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
        try {
            ilog("elastic_search plugin: plugin_initialize() begin");

            _my->database().post_apply_operation.connect( [&](const operation_notification& b){ _my->update_account_history(b); } );
            //_my->database().applied_block.connect( [&]( const signed_block& b){ _my->update_account_history(b); } );

            if (options.count("elasticsearch-node-url")) {
            }

            ilog("elastic_search plugin: plugin_initialize() end");
        } FC_CAPTURE_AND_RETHROW()
    }

    void elastic_search_plugin::plugin_startup() {
        ilog("elastic_search plugin: plugin_startup() begin");

        ilog("elastic_search plugin: plugin_startup() end");
    }

    void elastic_search_plugin::plugin_shutdown() {
        ilog("elastic_search plugin: plugin_shutdown() begin");

        ilog("elastic_search plugin: plugin_shutdown() end");
    }

 }}} // namespace golos::plugins::mongo_db
