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

#include <graphene/utilities/git_revision.hpp>

#define RANDOM_MAX_STRING_SIZE 100
#define RANDOM_MAX_SET_SIZE 100
#define RANDOM_MAX_VECTOR_SIZE 100
#define RANDOM_DOUBLE_LOWER_BOUND 0.0
#define RANDOM_DOUBLE_UPPER_BOUND 1000000.0


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

std::string get_random_string__() {
	std::string s;
    int len = rand() % RANDOM_MAX_STRING_SIZE + 1;
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

void set_random_value(fc::flat_set <std::string> & x) {
	fc::flat_set <std::string> tmp_set;
	srand( time( NULL ) );
	int count = rand() % RANDOM_MAX_SET_SIZE + 1;
	for (auto i = 0; i < count; i++) {
		auto tmp_s = get_random_string__();
		tmp_set.insert( tmp_s );
	}
	x = std::move(tmp_set);
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
void set_random_value( chainbase::object_id<T> & x)  {
	set_random_value( x._id );
}

void set_random_value( std::vector< golos::protocol::beneficiary_route_type > & x)  {
	int32_t count;
	set_random_value(count);
	count %= RANDOM_MAX_VECTOR_SIZE; 

	for (auto i = 0; i < count; i++) {
		golos::protocol::beneficiary_route_type tmp;
		set_random_value ( tmp.account );
		set_random_value ( tmp.weight );
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
