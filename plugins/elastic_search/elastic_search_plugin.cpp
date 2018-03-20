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
