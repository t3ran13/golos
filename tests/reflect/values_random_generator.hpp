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


#include <graphene/utilities/git_revision.hpp>

#define RANDOM_STRING_SIZE 100


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

void set_random_value(std::string & s) {
    int len = rand() % RANDOM_STRING_SIZE;
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
}

void set_random_value(std::vector<char> & s) {
    int len = rand() % RANDOM_STRING_SIZE;
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
}


void set_random_value(protocol::account_name_type & x) {

}




