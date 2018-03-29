#pragma once
#include <cstdlib>
#include <algorithm>
#include <string>

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

#include <graphene/utilities/git_revision.hpp>

#define RANDOM_MAX_STRING_SIZE 100
#define RANDOM_MAX_SET_SIZE 100
#define RANDOM_MAX_VECTOR_SIZE 100
#define RANDOM_DOUBLE_LOWER_BOUND 0.0
#define RANDOM_DOUBLE_UPPER_BOUND 1000000.0

namespace bip = boost::interprocess;


void set_random_value (double & x) {
    double lower_bound = RANDOM_DOUBLE_LOWER_BOUND;
    double upper_bound = RANDOM_DOUBLE_UPPER_BOUND;
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;

    x = unif(re);
}

void set_random_value (float & x) {
    float lower_bound = RANDOM_DOUBLE_LOWER_BOUND;
    float upper_bound = RANDOM_DOUBLE_UPPER_BOUND;
    std::uniform_real_distribution<float> unif(lower_bound,upper_bound);
    std::default_random_engine re;

    x = unif(re);
}

void set_random_value (bool & x) {
    srand(time(NULL));
    x = rand() % 2;
}

void set_random_value (int8_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (int16_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (int32_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value( std::vector<int32_t> & x ) {
    srand(time(NULL));
    int32_t n = rand();

    for (auto i = 0; i < n; i++) {
        x.push_back( rand() );
    }
}

void set_random_value (int64_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (uint8_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (uint16_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (uint32_t & x) {
    srand(time(NULL));
    x = rand();
}

void set_random_value (uint64_t & x) {
    srand(time(NULL));
    x = rand();
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

void set_random_value(std::string & s) {
    s = get_random_string__();
}

void set_random_value(std::vector<char> & s) {
    auto tmp_s = get_random_string__();
    auto len = tmp_s.size();
    for (auto i = 0; i < len; i++) {
        s.push_back(tmp_s[i]);
    }
}

void set_random_value(fc::fixed_string<> & x) {
    fc::fixed_string<> tmp_s( get_random_string__() );
    x = std::move(tmp_s);
}	

void set_random_value(golos::protocol::public_key_type & x) {
    auto tmp_s = get_random_string__();
    std::vector<char> v;
    auto len = tmp_s.size();
    for (auto i = 0; i < len; i++) {
        v.push_back( tmp_s[i] );
    }

    auto base58str = fc::to_base58(v);

    golos::protocol::public_key_type tmp_key(base58str);

    x = std::move( tmp_key );
}

// std::string get_random_iso_str() {
// 	srand( time( NULL ) );
// 	uint32_t seconds = rand() % (rand() + rand()	);
// 	fc::time_point_sec tmp_time_point_sec(seconds);
// 	return tmp_time_point_sec.to_iso_string();
// }

void set_random_value(fc::time_point & x) {
    srand( time( NULL ) );
    fc::microseconds ms ( rand() );

    fc::time_point t(ms);
    x = std::move(t);
}

template < class T >
void set_random_value(fc::flat_set <T> & x) {
    srand( time( NULL ) );
    int count = rand() % RANDOM_MAX_SET_SIZE + 1;

    for (auto i = 0; i < count; i++) {
        T tmp;
        set_random_value( tmp );

        x.insert( tmp );
    }
}


// void set_random_value(golos::plugins::private_message::message_id_type & x) {
// 	set_random_value( x._id );
// }

void set_random_value(fc::time_point_sec & x) {
    srand( time( NULL ) );
    fc::time_point_sec tmp( rand() );
    x = std::move( tmp );
}

void set_random_value(golos::plugins::private_message::message_body & x) {
    set_random_value( x.thread_start );
    set_random_value( x.subject );
    set_random_value( x.body );
    set_random_value( x.json_meta );
    set_random_value( x.cc );

}

void set_random_value(fc::uint128_t & x) {
    srand( time( NULL ) );
    uint64_t lo_ = rand();
    uint64_t hi_ = rand();
    fc::uint128_t tmp( hi_, lo_ );
    x = std::move( tmp );
}

void set_random_value(fc::safe<int64_t> & x) { // aka share_type
    srand( time( NULL ) );
    uint64_t n = rand();
    fc::safe<uint64_t> tmp( n );
    x = std::move( tmp );
}

void set_random_value( std::vector<golos::protocol::share_type> & x) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::protocol::share_type tmp;
        set_random_value( tmp );

        x.push_back( tmp );
    }

}


void set_random_value(golos::protocol::asset & x) {
    set_random_value( x.amount );
}

void set_random_value(golos::plugins::social_network::category_object::id_type & x) {
    set_random_value( x._id );
}

void set_random_value(golos::plugins::social_network::vote_state & x) {
    set_random_value( x.voter );
    set_random_value( x.weight );
    set_random_value( x.rshares );
    set_random_value( x.percent );
    set_random_value( x.reputation );
    set_random_value( x.time );
}

void set_random_value(std::vector<golos::plugins::social_network::vote_state> & x) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 

    for (auto i = 0; i < count; i++) {
        golos::plugins::social_network::vote_state tmp;
        set_random_value( tmp );
        x.push_back( tmp );
    }
}

void set_random_value(std::vector<std::string> & x) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 
    for (auto i = 0; i < count; i++) {
        x.push_back( get_random_string__() );
    }
}

void set_random_value(std::vector<golos::protocol::account_name_type> & x) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 
    for (auto i = 0; i < count; i++) {
        fc::fixed_string<> tmp_s( get_random_string__() );
        x.push_back( tmp_s );
    }
}

template <class T>
void set_random_value(fc::optional<T> & x) {
    T tmp_obj;
    set_random_value( tmp_obj );
    fc::optional<T> tmp_optional( tmp_obj );
    x = std::move( tmp_optional );
}

template<typename T>
void set_random_value( chainbase::object_id<T> & x) {
    set_random_value( x._id );
}

void set_random_value( golos::protocol::beneficiary_route_type & x ) {
    set_random_value( x.account );
    set_random_value( x.weight );
}

void set_random_value( std::vector < golos::protocol::beneficiary_route_type > & x ) {
    srand(time(NULL));
    int32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;

    for (auto i = 0; i < n; i++) {
        golos::protocol::beneficiary_route_type tmp;
        set_random_value( tmp );

        x.push_back( tmp );
    }
}


void set_random_value(std::set <std::string> & x) {
    srand( time( NULL ) );
    int count = rand() % RANDOM_MAX_SET_SIZE + 1;
    for (auto i = 0; i < count; i++) {
        auto tmp_s = get_random_string__();
        x.insert( tmp_s );
    }
}

void set_random_value(fc::fixed_string<fc::sha256> & x) {
    fc::fixed_string<fc::sha256> tmp_s( get_random_string__() );
    x = std::move( tmp_s );
}

void set_random_value(golos::protocol::version & x) {
    set_random_value( x.v_num );
}

void set_random_value(golos::protocol::hardfork_version & x) {
    set_random_value( x.v_num );
}

void set_random_value(golos::plugins::database_api::tag_count_object & x) {
    set_random_value( x.tag );
    set_random_value( x.count );
}

void set_random_value(std::vector< golos::plugins::database_api::tag_count_object > & x) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 

    for (auto i = 0; i < count; i++) {
        golos::plugins::database_api::tag_count_object tmp;

        set_random_value( tmp.tag );
        set_random_value( tmp.count );

        x.push_back( tmp );
    }    
}


void set_random_value(fc::ripemd160 & x) {
    fc::ripemd160 tmp;
    x = std::move( tmp.hash( get_random_hex_string__() ) );
}

void set_random_value(std::vector<golos::protocol::transaction_id_type> & x) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 

    for (auto i = 0; i < count; i++) {
        golos::protocol::transaction_id_type tmp;

        set_random_value( tmp );

        x.push_back( tmp );
    }    
}

// TODO: figure out how to work with fc::static_variant
void set_random_value(golos::protocol::operation & x) {

}

void set_random_value(golos::protocol::authority::account_authority_map & x ) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 

    for (auto i = 0; i < count; i++) {
        golos::protocol::account_name_type  key;
        golos::protocol::weight_type  val;

        set_random_value( key );
        set_random_value( val );
        
        x[key] = val;        
    }
}

// typedef bip::flat_map<public_key_type, weight_type, std::less<public_key_type>, key_pair_allocator_type>  AKA
void set_random_value(golos::protocol::authority::key_authority_map & x ) {
    int32_t count;
    set_random_value(count);
    count %= RANDOM_MAX_VECTOR_SIZE; 

    for (auto i = 0; i < count; i++) {
        golos::protocol::public_key_type  key;
        golos::protocol::weight_type  val;

        set_random_value( key );
        set_random_value( val );
        
        x[key] = val;        
    }
}

void set_random_value(golos::protocol::authority & x) {
    set_random_value( x.weight_threshold ); 
    set_random_value( x.account_auths );
    set_random_value( x.key_auths );
}

void set_random_value(golos::plugins::database_api::applied_operation & x) {
    set_random_value( x.block );
    set_random_value( x.trx_in_block );
    set_random_value( x.op_in_trx );
    set_random_value( x.virtual_op );
    set_random_value( x.timestamp );
    set_random_value( x.op );
}

void set_random_value(golos::plugins::database_api::account_api_object & x) {

    set_random_value( x.id );
    set_random_value( x.name );
    set_random_value( x.owner );
    set_random_value( x.active );
    set_random_value( x.posting );
    set_random_value( x.memo_key );
    set_random_value( x.json_metadata );
    set_random_value( x.proxy );
    set_random_value( x.last_owner_update );
    set_random_value( x.last_account_update );

    set_random_value( x.created );

    set_random_value( x.mined );
    set_random_value( x.owner_challenged );
    set_random_value( x.active_challenged );

    set_random_value( x.last_owner_proved );
    set_random_value( x.last_active_proved );
    set_random_value( x.recovery_account );
    set_random_value( x.last_account_recovery );
    set_random_value( x.comment_count );
    set_random_value( x.lifetime_vote_count );
    set_random_value( x.post_count );

    set_random_value( x.can_vote );
    set_random_value( x.voting_power );
    set_random_value( x.last_vote_time );


    set_random_value( x.balance );
    set_random_value( x.savings_balance );

    set_random_value( x.sbd_balance );
    set_random_value( x.sbd_seconds );
    set_random_value( x.sbd_seconds_last_update );
    set_random_value( x.sbd_last_interest_payment );


    set_random_value( x.savings_sbd_balance );
    set_random_value( x.savings_sbd_seconds );
    set_random_value( x.savings_sbd_seconds_last_update );
    set_random_value( x.savings_sbd_last_interest_payment );


    set_random_value( x.savings_withdraw_requests );
    set_random_value( x.curation_rewards );
    set_random_value( x.posting_rewards );


    set_random_value( x.vesting_shares );
    set_random_value( x.delegated_vesting_shares );
    set_random_value( x.received_vesting_shares );
    set_random_value( x.vesting_withdraw_rate );
    set_random_value( x.next_vesting_withdrawal );
    set_random_value( x.withdrawn );
    set_random_value( x.to_withdraw );
    set_random_value( x.withdraw_routes );


    set_random_value( x.proxied_vsf_votes );
    set_random_value( x.witnesses_voted_for );
    set_random_value( x.average_bandwidth );
    set_random_value( x.lifetime_bandwidth );
    set_random_value( x.last_bandwidth_update );


    set_random_value( x.average_market_bandwidth );
    set_random_value( x.last_market_bandwidth_update );
    set_random_value( x.last_post );
    set_random_value( x.last_root_post );
    set_random_value( x.post_bandwidth );


    set_random_value( x.new_average_bandwidth );
    set_random_value( x.new_average_market_bandwidth );
}

void set_random_value( std::map<uint64_t, golos::plugins::database_api::applied_operation > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        uint32_t key = rand();
        golos::plugins::database_api::applied_operation tmp;
        set_random_value( tmp );

        x[key] = tmp;
    }
}


void set_random_value( std::vector < std::pair < std::string, uint32_t > > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        std::string key = get_random_string__();
        uint32_t val = rand();
        std::pair < std::string, uint32_t > tmp {key, val};

        x.push_back( tmp );
    }
}


void set_random_value( std::vector<std::pair<golos::protocol::account_name_type, uint32_t> > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::protocol::account_name_type key;
        set_random_value( key );
        uint32_t val = rand();
        std::pair < std::string, uint32_t > tmp {key, val};

        x.push_back( tmp );
    }
}


void set_random_value( std::map<std::string, std::vector<std::string> > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        auto key = get_random_string__();
        std::vector<std::string> val;
        
        set_random_value( val );

        x[key] = val;
    }
}


void set_random_value( golos::plugins::database_api::extended_limit_order & x ) {
    set_random_value( x.real_price );
    set_random_value( x.rewarded );
}


void set_random_value( std::vector < golos::plugins::database_api::extended_limit_order > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::plugins::database_api::extended_limit_order tmp;
        set_random_value( tmp );
        x.push_back( tmp );
    }
}

void set_random_value( golos::plugins::database_api::order_history_item & x ) {
    set_random_value( x.time );
    set_random_value( x.type ); // buy or sell
    set_random_value( x.sbd_quantity );
    set_random_value( x.steem_quantity );
    set_random_value( x.real_price );
}


void set_random_value( std::vector <golos::plugins::database_api::order_history_item> & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::plugins::database_api::order_history_item tmp;
        set_random_value( tmp );
        x.push_back( tmp );
    }
}


void set_random_value( golos::plugins::database_api::candle_stick & x ) {
    set_random_value( x.open_time );
    set_random_value( x.period );
    set_random_value( x.high );
    set_random_value( x.low );
    set_random_value( x.open );
    set_random_value( x.close );
    set_random_value( x.steem_volume );
    set_random_value( x.dollar_volume );
}


void set_random_value( std::vector < golos::plugins::database_api::candle_stick > & x ) {
    srand( time( NULL ) );
    uint32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::plugins::database_api::candle_stick tmp;
        set_random_value( tmp );
        x.push_back( tmp );
    }
}


void set_random_value( golos::protocol::chain_properties  & x ) {  // IS NOT NEEDED TO BE FILLED WITH RANDOM VALUES

}


void set_random_value( golos::protocol::price & x ) {
    set_random_value( x.base );
    set_random_value( x.quote );
}



void set_random_value( fc::sha256 & x ) {
    fc::sha256 tmp( get_random_hex_string__() );
    x = std::move( tmp );
}


void set_random_value( std::deque<golos::protocol::price> & x ) {
    srand(time(NULL));
    int32_t n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;

    for (auto i = 0; i < n; i++) {
        golos::protocol::price tmp;
        set_random_value( tmp );

        x.push_front( tmp );
    }
}

void set_random_value( golos::plugins::social_network::comment_api_object & x ) {
    set_random_value( x.id );
    set_random_value( x.category );
    set_random_value( x.parent_author );
    set_random_value( x.parent_permlink );
    set_random_value( x.author );
    set_random_value( x.permlink );

    set_random_value( x.title );
    set_random_value( x.body );
    set_random_value( x.json_metadata );
    set_random_value( x.last_update );
    set_random_value( x.created );
    set_random_value( x.active );
    set_random_value( x.last_payout );

    set_random_value( x.depth );
    set_random_value( x.children );

    set_random_value( x.children_rshares2 );

    set_random_value( x.net_rshares );
    set_random_value( x.abs_rshares );
    set_random_value( x.vote_rshares );

    set_random_value( x.children_abs_rshares );
    set_random_value( x.cashout_time );
    set_random_value( x.max_cashout_time );
    set_random_value( x.total_vote_weight );

    set_random_value( x.reward_weight );

    set_random_value( x.total_payout_value );
    set_random_value( x.curator_payout_value );

    set_random_value( x.author_rewards );

    set_random_value( x.net_votes );

    // set_random_value( x.mode );

    set_random_value( x.root_comment );

    set_random_value( x.max_accepted_payout );
    set_random_value( x.percent_steem_dollars );
    set_random_value( x.allow_replies );
    set_random_value( x.allow_votes );
    set_random_value( x.allow_curation_rewards );

    set_random_value( x.beneficiaries );
}


void set_random_value( golos::plugins::follow::comment_feed_entry & x ) {
    set_random_value( x.comment );
    set_random_value( x.reblog_by );
    set_random_value( x.reblog_on );
    set_random_value( x.entry_id );
}


void set_random_value( golos::plugins::block_info::block_info & x ) {
    set_random_value( x.block_id );
    set_random_value( x.block_size ) ;
    set_random_value( x.average_block_size );
    set_random_value( x.aslot );
    set_random_value( x.last_irreversible_block_num );
    set_random_value( x.num_pow_witnesses );
}


void set_random_value( fc::ecc::compact_signature & x ) {
    // fc::array<unsigned char, 65> arr;
    for (size_t i = 0; i < 65; i++) {
        unsigned char tmp;
        set_random_value( tmp );
        x.data[i] = tmp;
    }
}

void set_random_value( std::vector < fc::ecc::compact_signature > & x ) {
    int32_t n;
    n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;

    for (auto i = 0; i < n; i++) {
        fc::ecc::compact_signature tmp;

        set_random_value( tmp );

        x.push_back( tmp );
    } 
}


void set_random_value( golos::protocol::transaction & x ) {
    set_random_value( x.ref_block_num );
    set_random_value( x.ref_block_prefix );
    set_random_value( x.expiration );
    // vector<operation> operations; TODO
    set_random_value( x.extensions );
    
}

void set_random_value( golos::protocol::signed_transaction & x ) {
    set_random_value( x.signatures );

    set_random_value( x.signatures );
    set_random_value( x.ref_block_num );
    set_random_value( x.ref_block_prefix );
    set_random_value( x.expiration );
    // vector<operation> operations; TODO
    set_random_value( x.extensions ); 

}

void set_random_value( std::vector <golos::protocol::signed_transaction> & x ) {
    int32_t n;
    n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;

    for (auto i = 0; i < n; i++) {
        golos::protocol::signed_transaction tmp;
        set_random_value( tmp );
    }
}



void set_random_value( golos::chain::signed_block & x ) {
    set_random_value( x.transactions );
    // signature_type witness_signature;
    set_random_value( x.witness_signature );
    set_random_value( x.timestamp ); 
    set_random_value( x.witness );
    set_random_value( x.transaction_merkle_root );
    set_random_value( x.extensions );
}


void set_random_value( golos::plugins::block_info::block_with_info & x ) {
    set_random_value( x.block );
    set_random_value( x.info );
}




