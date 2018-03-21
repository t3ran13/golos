#ifdef STEEMIT_BUILD_TESTNET


#include <boost/test/unit_test.hpp>

#include <golos/protocol/exceptions.hpp>

#include <golos/chain/block_summary_object.hpp>
#include <golos/chain/database.hpp>
#include <golos/chain/hardfork.hpp>
#include <golos/chain/history_object.hpp>
#include <golos/chain/steem_objects.hpp>

#include <golos/plugins/debug_node/plugin.hpp>

#include <fc/crypto/digest.hpp>

#include "../common/database_fixture.hpp"

#include <cmath>

#include <golos/plugins/block_info/plugin.hpp>
#include "../common/database_fixture.hpp"

using namespace golos::chain;
using namespace golos::protocol;

BOOST_FIXTURE_TEST_SUITE(reflect, database_fixture)

    BOOST_AUTO_TEST_CASE(block_info) {

        try {
            initialize();
            open_database();
            startup();

            golos::plugins::block_info::block_info v1, v2;
			std::string tmp_hex = "98c615784ccb5fe5936fbc0cbe9dfdb408d92f0f";
	        v1.block_id =  golos::chain::block_id_type(tmp_hex);
	        v1.block_size = rand();
	        v1.average_block_size = rand();
	        v1.aslot = rand();
	        v1.last_irreversible_block_num = rand();
	        v1.num_pow_witnesses = rand();

	        std::cout << "block_size = " << v1.block_size << std::endl;
	        std::cout << "average_block_size = " << v1.average_block_size << std::endl;
	        std::cout << "aslot = " << v1.aslot << std::endl;
	        std::cout << "last_irreversible_block_num = " << v1.last_irreversible_block_num << std::endl;
	        std::cout << "num_pow_witnesses = " << v1.num_pow_witnesses << std::endl;


	        auto data = fc::raw::pack(v1);

	        std::fstream stream_ex;
	        stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);

	        fc::path file("logs");

	        stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);

	        stream_ex.write(data.data(), data.size());
	        stream_ex.close();
	        
	        stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
	        
	        fc::raw::unpack(stream_ex, v2);
	        stream_ex.close();

	        std::cout << "block_size = " << v2.block_size << std::endl;
	        std::cout << "average_block_size = " << v2.average_block_size << std::endl;
	        std::cout << "aslot = " << v2.aslot << std::endl;
	        std::cout << "last_irreversible_block_num = " << v2.last_irreversible_block_num << std::endl;
	        std::cout << "num_pow_witnesses = " << v2.num_pow_witnesses << std::endl;        
        
        }
        FC_LOG_AND_RETHROW()
    }

BOOST_AUTO_TEST_SUITE_END()
#endif