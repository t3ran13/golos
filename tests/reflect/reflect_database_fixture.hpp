#ifndef REFLECT_DATABASE_FIXTURE_HPP
#define REFLECT_DATABASE_FIXTURE_HPP

#include <appbase/application.hpp>
#include <golos/chain/database.hpp>

#include <fc/io/json.hpp>
#include <fc/smart_ref_impl.hpp>

#include <golos/plugins/debug_node/plugin.hpp>
#include <golos/plugins/account_history/plugin.hpp>
// #include "values_random_generator.hpp"


#include <graphene/utilities/key_conversion.hpp>

#include <iostream>

#define INITIAL_TEST_SUPPLY (10000000000ll)


namespace golos {
namespace chain {

using namespace golos::protocol;

struct reflect_database_fixture {
    // the reason we use an app is to exercise the indexes of built-in
    //   plugins
    chain::database db;
    signed_transaction trx;
    // fc::ecc::private_key init_account_priv_key = STEEMIT_INIT_PRIVATE_KEY;
    // string debug_key = golos::utilities::key_to_wif(init_account_priv_key);
    // public_key_type init_account_pub_key = init_account_priv_key.get_public_key();
    uint32_t default_skip = 0 | database::skip_undo_history_check |
                            database::skip_authority_check;

    optional<fc::temp_directory> data_dir;
    bool skip_key_index_test = false;

    reflect_database_fixture();

    virtual ~reflect_database_fixture();

    void initialize();
    void startup(bool generate_hardfork = true);

    void open_database();
    void close_database();

};

}
}
#endif