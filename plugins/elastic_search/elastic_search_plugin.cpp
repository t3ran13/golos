#include <golos/plugins/elastic_search/elastic_search_plugin.hpp>

#include <golos/plugins/json_rpc/plugin.hpp>
#include <golos/plugins/chain/plugin.hpp>
#include <golos/protocol/block.hpp>

#include <curl/curl.h>


namespace golos {
namespace plugins {
namespace elastic_search {

    class elastic_search_plugin::elastic_search_plugin_impl {
    public:
        elastic_search_plugin_impl(elastic_search_plugin &plugin)
                : _my(plugin),
                  _db(appbase::app().get_plugin<golos::plugins::chain::plugin>().db()) {

            curl = curl_easy_init();
        }

        ~elastic_search_plugin_impl() = default;

        golos::chain::database &database() const {
            return _db;
        }

        elastic_search_plugin &_my;

        std::string _elasticsearch_node_url = "http://localhost:9200/";

    private:

        CURL *curl; // curl handler
        golos::chain::database &_db;
    };


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
                 boost::program_options::value<std::string>(),
                         "Elastic Search database node url");
        cfg.add(cli);
    }

    void elastic_search_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
        try {
            ilog("elastic_search plugin: plugin_initialize() begin");

            if (options.count("elasticsearch-node-url")) {
                _my->_elasticsearch_node_url = options["elasticsearch-node-url"].as<std::string>();
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
