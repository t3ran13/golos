#pragma once
#include "generators.hpp"

void set_random_value ( fc::variant_object & x) {
}

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

void set_random_value (long long unsigned int & x) {
    srand(time(NULL));
    x = rand();
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

// TODO. BUT there is non-empty data in x, so it's ok for now. 
void set_random_value(golos::protocol::public_key_type & x) {

}

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

template < class T >
void set_random_value(std::set <T> & x) {
    srand( time( NULL ) );
    int count = rand() % RANDOM_MAX_SET_SIZE + 1;

    for (auto i = 0; i < count; i++) {
        T tmp;
        set_random_value( tmp );

        x.insert( tmp );
    }
}

template < class T, class U >
void set_random_value( std::pair <T, U> & x) {
    T first;
    U second;

    set_random_value( first );
    set_random_value( second );

    std::pair<T, U> tmp{first, second};
    x = std::move(tmp);
}


template < class T >
void set_random_value(std::vector <T> & x) {
    srand( time( NULL ) );
    int count = rand() % RANDOM_MAX_SET_SIZE + 1;

    for (auto i = 0; i < count; i++) {
        T tmp;
        set_random_value( tmp );

        x.push_back( tmp );
    }
}

template < class T , class T1>
void set_random_value(std::map <T, T1> & x) {
    srand( time( NULL ) );
    int count = rand() % RANDOM_MAX_SET_SIZE + 1;

    for (auto i = 0; i < count; i++) {
        T key;
        T1 val;

        set_random_value( key );
        set_random_value( val );

        x[key] = val;
    }
}

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

template <class T>
void set_random_value(fc::safe<T> & x) { // aka share_type
    T n;
    set_random_value( n );
    fc::safe<T> tmp( n );
    x = std::move( tmp );
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

void set_random_value(fc::ripemd160 & x) {
    fc::ripemd160 tmp;
    x = std::move( tmp.hash( get_random_hex_string__() ) );
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

void set_random_value( golos::plugins::database_api::order_history_item & x ) {
    set_random_value( x.time );
    set_random_value( x.type ); // buy or sell
    set_random_value( x.sbd_quantity );
    set_random_value( x.steem_quantity );
    set_random_value( x.real_price );
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

template<typename T, size_t N>
void set_random_value( fc::array<T, N> & x ) {
    for (size_t i = 0; i < N; i++) {
        T tmp;
        set_random_value( tmp );
        x.data[i] = tmp;
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
    set_random_value( x.ref_block_num );
    set_random_value( x.ref_block_prefix );
    set_random_value( x.expiration );
    // vector<operation> operations; TODO

    set_random_value( x.extensions );
}

void set_random_value( golos::chain::signed_block & x ) {
    set_random_value( x.transactions );
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


void set_random_value( golos::plugins::market_history::order & x ) {
    set_random_value( x.price );
    set_random_value( x.steem );
    set_random_value( x.sbd );
}

// TODO: FIGURE OUT HOW TO WRITE THIS CASE BETTER 
void set_random_value( fc::variant & x ) {
    uint32_t n;
    set_random_value( n );
    x = std::move ( fc::variant(n) );
}



void set_random_value( fc::sha512 & x ) {
    auto hx = get_random_hex_string__();
    x = std::move ( fc::sha512( hx ) );
}

void set_random_value( std::map<golos::protocol::public_key_type, std::string> & x ) {
    int32_t n;
    n = rand() % RANDOM_MAX_VECTOR_SIZE + 1;
    
    for (auto i = 0; i < n; i++) {
        golos::protocol::public_key_type key;
        std::string val;

        set_random_value( key );
        set_random_value( val );

        x[key] = val;
    }
}

void set_random_value( golos::wallet::plain_keys & x ) {
    set_random_value( x.checksum );
    set_random_value( x.keys );
}

void set_random_value( golos::network::item_id & x ) {
    set_random_value( x.item_type );
    set_random_value( x.item_hash );
}

void set_random_value( golos::network::peer_connection::timestamped_item_id & x ) {
    set_random_value( x.item );
    set_random_value( x.timestamp );
}

void set_random_value( fc::ip::address  & x ) {
    auto ip_str = get_random_ip_address_str__();
    fc::ip::address tmp( ip_str );

    x = std::move( tmp );
}

void set_random_value( fc::ip::endpoint & x ) {
    uint16_t port;
    set_random_value( port );
    fc::ip::address address;
    set_random_value( address );
    fc::ip::endpoint tmp( address, port );

    x = std::move( tmp );
}

void set_random_value( fc::exception & x ) {
}

template <class T, class T1>
void set_random_value( fc::enum_type<T, T1> & x) {
}


void set_random_value( fc::microseconds & x ) {
    int64_t c;
    set_random_value( c );
    fc::microseconds tmp( c );
    x = std::move( tmp );
}

void set_random_value( golos::chain::account_keys & x) {
    set_random_value( x.owner_key );
    set_random_value( x.active_key );
    set_random_value( x.posting_key );
    set_random_value( x.memo_key );
}

void set_random_value( golos::chain::account_balances & x) {
    set_random_value( x.assets );
}

void set_random_value( golos::chain::snapshot_summary & x) {
    set_random_value( x.balance );
    set_random_value( x.sbd_balance );
    set_random_value( x.total_vesting_shares );
    set_random_value( x.total_vesting_fund_steem );
    set_random_value( x.accounts_count );
}

// void set_random_value( golos::chain::immutable_chain_parameters & x) {
//     set_random_value( x.min_committee_member_count );
//     set_random_value( x.min_witness_count );
//     set_random_value( x.num_special_accounts );
//     set_random_value( x.num_special_assets );
// }


void set_random_value( golos::protocol::signed_block_header & x) {
    set_random_value( x.witness_signature );
    set_random_value( x.timestamp );
    set_random_value( x.witness );
    set_random_value( x.transaction_merkle_root );
    set_random_value( x.extensions );
}

void set_random_value( golos::protocol::pow2_input & x) {
    set_random_value( x.worker_account );
    set_random_value( x.prev_block );
    set_random_value( x.nonce );
}

void set_random_value( golos::protocol::pow2 & x) {
    set_random_value( x.input );
    set_random_value( x.pow_summary );
}


void set_random_value( fc::equihash::proof & x) {
    set_random_value( x.n );
    set_random_value( x.k );
    set_random_value( x.seed );
    set_random_value( x.inputs );
}


void set_random_value( golos::protocol::pow & x) {
    set_random_value( x.worker );
    set_random_value( x.input );
    set_random_value( x.signature );
    set_random_value( x.work );

}


void set_random_value( fc::bloom_parameters::optimal_parameters_t & x) {
    set_random_value( x.number_of_hashes );
    set_random_value( x.table_size );
}


void set_random_value( fc::http::header & x) {
    set_random_value( x.key );
    set_random_value( x.val );
}


void set_random_value( fc::json_console_appender::j_config & x) {
    set_random_value( x.format );
    set_random_value( x.flush );
}

std::string get_random_path_string__() {
    int32_t n = rand() % 10 + 1;
    std::string data ("/");
    for (int i = 0; i < n; i++) {
        data += get_random_string__() + "/";
    }
    return data;
}

void set_random_value( fc::path  & x) {
    fc::path tmp( get_random_path_string__() );
    x = std::move( tmp );
}

void set_random_value(golos::plugins::database_api::extended_limit_order & x) {
    set_random_value( x.id );

    set_random_value( x.created );
    set_random_value( x.expiration );
    set_random_value( x.seller );
    set_random_value( x.orderid );
    set_random_value( x.for_sale ); 
    set_random_value( x.sell_price );   
    set_random_value( x.real_price );
    set_random_value( x.rewarded ); 
}

void set_random_value(char & x) {
    int sz = 2;
    auto s = get_random_string__(sz);
    x = s[0];
}

void set_random_value( golos::network::address_info & x ) {
    set_random_value( x.remote_endpoint );
    set_random_value( x.last_seen_time );
    set_random_value( x.latency );
    set_random_value( x.node_id );
    set_random_value( x.direction );
    set_random_value( x.firewalled );
}


void set_random_value(golos::network::current_connection_data & x ) {
    set_random_value( x.connection_duration );
    set_random_value( x.remote_endpoint );
    set_random_value( x.node_id );
    set_random_value( x.clock_offset );
    set_random_value( x.round_trip_delay );
    set_random_value( x.connection_direction );
    set_random_value( x.firewalled );
    set_random_value( x.user_data );
}


void set_random_value(golos::chain::account_summary & x ) {
    set_random_value( x.id );
    set_random_value( x.name );
    set_random_value( x.keys );
    set_random_value( x.posting_rewards );
    set_random_value( x.curation_rewards );
    set_random_value( x.balances );
    set_random_value( x.json_metadata );
    set_random_value( x.proxy );
    set_random_value( x.post_count );
    set_random_value( x.recovery_account );
    set_random_value( x.reputation );
}

void set_random_value(
    fc::static_variant<
        golos::void_t,
        golos::protocol::version,
        golos::protocol::hardfork_version_vote>
    & x) {
}
void set_random_value(fc::static_variant<golos::void_t> & x) {

}

void set_random_value(fc::static_variant<golos::protocol::comment_payout_beneficiaries> & x) {

}

void set_random_value(fc::rpc::error_object & x) {
    set_random_value( x.code );
    set_random_value( x.message );
    set_random_value( x.data );
}

void set_random_value( fc::log_level & x) {

}

void set_random_value(fc::appender_config & x) {

}

void set_random_value(fc::logger_config & x) {

}

void set_random_value(fc::logging_config & x) {

}

// boost::interprocess::vector<char, allocator<char>> AKA  buffer_type;
void set_random_value( golos::chain::buffer_type & x) {
    std::vector < char > v;
    set_random_value(v);

    for (size_t i = 0; i < v.size(); i++) {
        x.push_back( v[i] );
    }
}

