#pragma once

#include <steemit/application/plugin.hpp>
#include <steemit/chain/database.hpp>

#include <steemit/account_by_key/account_by_key_api.hpp>

namespace steemit {
    namespace account_by_key {

#define ACCOUNT_BY_KEY_PLUGIN_NAME "account_by_key"

        namespace detail { class account_by_key_plugin_impl; }

        class account_by_key_plugin : public steemit::application::plugin {
        public:
            account_by_key_plugin(steemit::application::application *app);

            std::string plugin_name() const override {
                return ACCOUNT_BY_KEY_PLUGIN_NAME;
            }

            virtual void plugin_set_program_options(
                    boost::program_options::options_description &cli,
                    boost::program_options::options_description &cfg) override;

            virtual void plugin_initialize(const boost::program_options::variables_map &options) override;

            virtual void plugin_startup() override;

            void update_key_lookup(const account_authority_object &a);

            friend class detail::account_by_key_plugin_impl;

            std::unique_ptr<detail::account_by_key_plugin_impl> my;
        };

    }
} // steemit::account_by_key