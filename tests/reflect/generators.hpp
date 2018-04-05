#pragma once

#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>

#include <fc/static_variant.hpp>

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

#include <golos/network/config.hpp>
#include <golos/network/core_messages.hpp>
#include <golos/network/exceptions.hpp>
#include <golos/network/message.hpp>
#include <golos/network/message_oriented_connection.hpp>
#include <golos/network/node.hpp>
#include <golos/network/peer_connection.hpp>
#include <golos/network/peer_database.hpp>
#include <golos/network/stcp_socket.hpp>

#include <golos/protocol/config.hpp>

#include <golos/chain/snapshot_state.hpp>
// ERRORs |
//        V
// #include <golos/chain/immutable_chain_parameters.hpp>
#include <fc/bloom_filter.hpp>
#include <fc/network/http/connection.hpp>
#include <fc/rpc/bstate.hpp>
#include <fc/log/console_appender.hpp>
#include <fc/log/json_console_appender.hpp>
#include <fc/log/gelf_appender.hpp>
#include <fc/log/file_appender.hpp>
#include <fc/log/logger.hpp>
#include <fc/log/logger_config.hpp>

// #include "../../thirdparty/fc/include/fc/static_variant.hpp"
#include <fc/variant.hpp>


#include <graphene/utilities/git_revision.hpp>

#define RANDOM_MAX_STRING_SIZE 100
#define RANDOM_MAX_SET_SIZE 100
#define RANDOM_MAX_VECTOR_SIZE 100
#define RANDOM_DOUBLE_LOWER_BOUND 0.0
#define RANDOM_DOUBLE_UPPER_BOUND 1000000.0

namespace bip = boost::interprocess;
// mt19937 rnd = mt19937(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count());

std::string get_random_ip_address_str__() {
    std::string s;
    for (int i = 0; i < 4; i++) {
        auto n = rand() % 128;
        s += std::to_string( n );
        if (i < 3) {
            s += ".";
        }
    }
    return s;
}

std::string get_random_hex_string__() {
    std::string s;
    srand(time(NULL));
    int len = rand() % RANDOM_MAX_STRING_SIZE + 1;
    s.resize(len);
    static const char alphanum[] =
        "0123456789"
        "ABCDEF";
    int alphanum_size = sizeof(alphanum);

    for (int i = 0; i < len; ++i) {
        auto x = rand() % (alphanum_size - 1);
        s[i] = alphanum[x];
    }

    s[len] = 0;
    return s;
}

std::string get_random_string__(int32_t sz = -1) {
    srand(time(NULL));
    std::string s;
    int len;

    if (sz == -1) {
        len = rand() % RANDOM_MAX_STRING_SIZE + 1;
    }
    else {
        len = sz;
    }

    s.resize(len);
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int alphanum_size = sizeof(alphanum);

    for (int i = 0; i < len; ++i) {
        auto x = rand() % (alphanum_size - 1);
        s[i] = alphanum[x];
    }

    s[len] = 0;
    return s;
}

std::string get_random_base58_string__(int32_t sz = -1) {
    srand(time(NULL));
    std::string s;
    int len;

    if (sz == -1) {
        len = rand() % RANDOM_MAX_STRING_SIZE + 1;
    }
    else {
        len = sz;
    }

    s.resize(len);
    std::string alphanum = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    int alphanum_size = alphanum.size() ;

    for (int i = 0; i < len; ++i) {
        auto x = rand() % (alphanum_size - 1);
        s[i] = alphanum[x];
    }

    s[len] = 0;
    return s;
}
// template < class X, class... T >
// void set_random_value( const fc::static_variant< X, T... args>  & x) {

// }

// void set_random_value( const fc::static_variant<golos::void_t> & x);

// void set_random_value( const fc::static_variant<golos::void_t> & x) {

// }

// TODO: figure out what to do with fc::variant_object
template <class T>
void set_random_value ( fc::safe<T> & x );
void set_random_value ( golos::protocol::beneficiary_route_type & x );
void set_random_value ( golos::protocol::asset & x );
void set_random_value ( double & x );
void set_random_value ( float & x );
void set_random_value ( bool & x );
void set_random_value ( int8_t & x );
void set_random_value ( int8_t & x );
void set_random_value ( int16_t & x );
void set_random_value ( int32_t & x );
void set_random_value ( int64_t & x );
void set_random_value ( uint8_t & x ) ;
void set_random_value ( uint16_t & x ) ;
void set_random_value ( uint32_t & x ) ;
void set_random_value (uint64_t & x) ;
void set_random_value (long long unsigned int & x) ;
void set_random_value(std::string & s);
void set_random_value(std::vector<char> & s);
void set_random_value(fc::fixed_string<> & x);
void set_random_value(golos::protocol::public_key_type & x);
void set_random_value(fc::time_point & x);
template < class T >
void set_random_value(fc::flat_set <T> & x) ;
template < class T >
void set_random_value(std::set <T> & x);
template < class T, class U >
void set_random_value( std::pair <T, U> & x);
template < class T >
void set_random_value(  std::vector <T> & x) ;
template < class T , class T1>
void set_random_value( std::map <T, T1> & x) ;
void set_random_value( fc::time_point_sec & x) ;
void set_random_value( golos::plugins::private_message::message_body & x) ;
void set_random_value( fc::uint128_t & x);
template <class T>
void set_random_value( fc::safe<T> & x);
void set_random_value( golos::protocol::asset & x);
void set_random_value( golos::plugins::social_network::category_object::id_type & x);
void set_random_value( golos::plugins::social_network::vote_state & x);
template <class T>
void set_random_value ( fc::optional<T> & x);
template<typename T>
void set_random_value ( chainbase::object_id<T> & x);
void set_random_value ( golos::protocol::beneficiary_route_type & x );
void set_random_value ( std::set <std::string> & x);
void set_random_value ( fc::fixed_string<fc::sha256> & x);
void set_random_value ( golos::protocol::version & x);

void set_random_value ( golos::protocol::hardfork_version & x);
void set_random_value ( golos::plugins::database_api::tag_count_object & x);
void set_random_value ( fc::ripemd160 & x);
void set_random_value ( golos::protocol::authority::account_authority_map & x );
void set_random_value ( golos::protocol::authority::key_authority_map & x ) ;
void set_random_value ( golos::protocol::authority & x);
void set_random_value ( golos::plugins::database_api::applied_operation & x) ;
void set_random_value ( std::map<uint64_t, golos::plugins::database_api::applied_operation > & x ) ;
void set_random_value ( golos::plugins::database_api::account_api_object & x) ;
void set_random_value ( golos::plugins::database_api::order_history_item & x );
void set_random_value ( golos::plugins::database_api::candle_stick & x );
void set_random_value ( golos::protocol::chain_properties & x ) ;
void set_random_value ( golos::protocol::price & x ) ;
void set_random_value ( fc::sha256 & x ) ;
void set_random_value ( std::deque<golos::protocol::price> & x ) ;
void set_random_value ( golos::plugins::social_network::comment_api_object & x ) ;
void set_random_value ( golos::plugins::follow::comment_feed_entry & x );
void set_random_value ( golos::plugins::block_info::block_info & x );
template<typename T, size_t N>
void set_random_value ( fc::array<T, N> & x );
void set_random_value ( golos::protocol::transaction & x ) ;
void set_random_value ( golos::protocol::signed_transaction & x );
void set_random_value ( golos::chain::signed_block & x ) ;
void set_random_value ( golos::plugins::block_info::block_with_info & x );
void set_random_value ( golos::plugins::market_history::order & x ) ;
void set_random_value ( fc::variant & x ) ;
void set_random_value ( fc::sha512 & x ) ;
void set_random_value ( std::map<golos::protocol::public_key_type, std::string> & x ) ;
void set_random_value ( golos::wallet::plain_keys & x );
void set_random_value ( golos::network::item_id & x );
void set_random_value ( golos::network::peer_connection::timestamped_item_id & x );
void set_random_value ( fc::ip::address  & x ) ;
void set_random_value ( fc::ip::endpoint & x ) ;
template <class T, class T1>
void set_random_value ( fc::enum_type<T, T1> & x);
void set_random_value ( fc::microseconds & x ) ;
void set_random_value ( golos::chain::account_keys & x) ;
void set_random_value ( golos::chain::account_balances & x) ;
void set_random_value ( golos::chain::snapshot_summary & x) ;
void set_random_value ( golos::protocol::signed_block_header & x) ;
void set_random_value ( golos::protocol::pow2_input & x) ;
void set_random_value ( golos::protocol::pow2 & x) ;
void set_random_value ( fc::equihash::proof & x) ;
void set_random_value ( golos::protocol::pow & x) ;
void set_random_value ( fc::bloom_parameters::optimal_parameters_t & x) ;
void set_random_value ( fc::http::header & x) ;
void set_random_value ( fc::json_console_appender::j_config & x) ;
std::string get_random_path_string__() ;
void set_random_value ( fc::path  & x);
void set_random_value ( golos::plugins::database_api::extended_limit_order & x);
void set_random_value ( fc::exception & x);
void set_random_value ( char & x); 
void set_random_value ( golos::network::address_info & x);
void set_random_value ( golos::network::current_connection_data & x );
void set_random_value ( golos::chain::account_summary & x );
void set_random_value (
    fc::static_variant<
        golos::void_t,
        golos::protocol::version,
        golos::protocol::hardfork_version_vote>& x
);
void set_random_value ( golos::protocol::operation & x);
void set_random_value ( fc::static_variant<golos::void_t> & x);
void set_random_value ( fc::static_variant<golos::protocol::comment_payout_beneficiaries> & x);
void set_random_value ( fc::rpc::error_object & x);
void set_random_value ( fc::log_level & x);
void set_random_value ( fc::appender_config & x);
void set_random_value ( fc::logger_config & x);
void set_random_value ( fc::logging_config & x);
void set_random_value ( fc::variant_object & x);

void set_random_value( golos::chain::buffer_type & x);
