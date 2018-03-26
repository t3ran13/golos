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
#include "values_random_generator.hpp"

#include <cmath>

#include <golos/plugins/block_info/plugin.hpp>
#include "../common/database_fixture.hpp"

using namespace golos::chain;
using namespace golos::protocol;
#define REFLECT_TESTS_OUTPUT_FILE "reflect_tests_output_file.txt"




BOOST_FIXTURE_TEST_SUITE(reflect, database_fixture)


    BOOST_AUTO_TEST_CASE(golos_plugins_test_api_test_api_a_t) {
        try {
            golos::plugins::test_api::test_api_a_t v1, v2;

            set_random_value(v1.value);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_test_api_test_api_b_t) {
        try {
            golos::plugins::test_api::test_api_b_t v1, v2;

            set_random_value(v1.value);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_private_message_private_message_operation) {
        try {
            golos::plugins::private_message::private_message_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.from_memo_key);
            set_random_value(v1.to_memo_key);
            set_random_value(v1.sent_time);
            set_random_value(v1.checksum);
            set_random_value(v1.encrypted_message);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_private_message_message_body) {
        try {
            golos::plugins::private_message::message_body v1, v2;

            set_random_value(v1.thread_start);
            set_random_value(v1.subject);
            set_random_value(v1.body);
            set_random_value(v1.json_meta);
            set_random_value(v1.cc);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_private_message_message_object) {
        try {
            golos::plugins::private_message::message_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.from_memo_key);
            set_random_value(v1.to_memo_key);
            set_random_value(v1.sent_time);
            set_random_value(v1.receive_time);
            set_random_value(v1.checksum);
            set_random_value(v1.encrypted_message);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_private_message_message_api_obj) {
        try {
            golos::plugins::private_message::message_api_obj v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.from_memo_key);
            set_random_value(v1.to_memo_key);
            set_random_value(v1.sent_time);
            set_random_value(v1.receive_time);
            set_random_value(v1.checksum);
            set_random_value(v1.encrypted_message);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_private_message_extended_message_object) {
        try {
            golos::plugins::private_message::extended_message_object v1, v2;

            set_random_value(v1.message);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_blockchain_statistics_bucket_object) {
        try {
            golos::plugins::blockchain_statistics::bucket_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.open);
            set_random_value(v1.seconds);
            set_random_value(v1.blocks);
            set_random_value(v1.bandwidth);
            set_random_value(v1.operations);
            set_random_value(v1.transactions);
            set_random_value(v1.transfers);
            set_random_value(v1.steem_transferred);
            set_random_value(v1.sbd_transferred);
            set_random_value(v1.sbd_paid_as_interest);
            set_random_value(v1.paid_accounts_created);
            set_random_value(v1.mined_accounts_created);
            set_random_value(v1.root_comments);
            set_random_value(v1.root_comment_edits);
            set_random_value(v1.root_comments_deleted);
            set_random_value(v1.replies);
            set_random_value(v1.reply_edits);
            set_random_value(v1.replies_deleted);
            set_random_value(v1.new_root_votes);
            set_random_value(v1.changed_root_votes);
            set_random_value(v1.new_reply_votes);
            set_random_value(v1.changed_reply_votes);
            set_random_value(v1.payouts);
            set_random_value(v1.sbd_paid_to_authors);
            set_random_value(v1.vests_paid_to_authors);
            set_random_value(v1.vests_paid_to_curators);
            set_random_value(v1.liquidity_rewards_paid);
            set_random_value(v1.transfers_to_vesting);
            set_random_value(v1.steem_vested);
            set_random_value(v1.new_vesting_withdrawal_requests);
            set_random_value(v1.modified_vesting_withdrawal_requests);
            set_random_value(v1.vesting_withdraw_rate_delta);
            set_random_value(v1.vesting_withdrawals_processed);
            set_random_value(v1.finished_vesting_withdrawals);
            set_random_value(v1.vests_withdrawn);
            set_random_value(v1.vests_transferred);
            set_random_value(v1.sbd_conversion_requests_created);
            set_random_value(v1.sbd_to_be_converted);
            set_random_value(v1.sbd_conversion_requests_filled);
            set_random_value(v1.steem_converted);
            set_random_value(v1.limit_orders_created);
            set_random_value(v1.limit_orders_filled);
            set_random_value(v1.limit_orders_cancelled);
            set_random_value(v1.total_pow);
            set_random_value(v1.estimated_hashpower);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tag_api_object) {
        try {
            golos::plugins::social_network::tag_api_object v1, v2;

            set_random_value(v1.name);
            set_random_value(v1.total_children_rshares2);
            set_random_value(v1.total_payouts);
            set_random_value(v1.net_votes);
            set_random_value(v1.top_posts);
            set_random_value(v1.comments);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_category_api_object) {
        try {
            golos::plugins::social_network::category_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.abs_rshares);
            set_random_value(v1.total_payouts);
            set_random_value(v1.discussions);
            set_random_value(v1.last_update);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_vote_state) {
        try {
            golos::plugins::social_network::vote_state v1, v2;

            set_random_value(v1.voter);
            set_random_value(v1.weight);
            set_random_value(v1.rshares);
            set_random_value(v1.percent);
            set_random_value(v1.reputation);
            set_random_value(v1.time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_account_vote) {
        try {
            golos::plugins::social_network::account_vote v1, v2;

            set_random_value(v1.authorperm);
            set_random_value(v1.weight);
            set_random_value(v1.rshares);
            set_random_value(v1.percent);
            set_random_value(v1.time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_discussion) {
        try {
            golos::plugins::social_network::discussion v1, v2;

            set_random_value(v1.url);
            set_random_value(v1.root_title);
            set_random_value(v1.pending_payout_value);
            set_random_value(v1.total_pending_payout_value);
            set_random_value(v1.active_votes);
            set_random_value(v1.replies);
            set_random_value(v1.author_reputation);
            set_random_value(v1.promoted);
            set_random_value(v1.body_length);
            set_random_value(v1.reblogged_by);
            set_random_value(v1.first_reblogged_by);
            set_random_value(v1.first_reblogged_on);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_discussion_index) {
        try {
            golos::plugins::social_network::discussion_index v1, v2;

            set_random_value(v1.category);
            set_random_value(v1.trending);
            set_random_value(v1.trending30);
            set_random_value(v1.updated);
            set_random_value(v1.created);
            set_random_value(v1.responses);
            set_random_value(v1.active);
            set_random_value(v1.votes);
            set_random_value(v1.maturing);
            set_random_value(v1.best);
            set_random_value(v1.hot);
            set_random_value(v1.promoted);
            set_random_value(v1.cashout);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tag_index) {
        try {
            golos::plugins::social_network::tag_index v1, v2;

            set_random_value(v1.trending);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_comment_api_object) {
        try {
            golos::plugins::social_network::comment_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.category);
            set_random_value(v1.parent_author);
            set_random_value(v1.parent_permlink);
            set_random_value(v1.title);
            set_random_value(v1.body);
            set_random_value(v1.json_metadata);
            set_random_value(v1.last_update);
            set_random_value(v1.created);
            set_random_value(v1.active);
            set_random_value(v1.last_payout);
            set_random_value(v1.depth);
            set_random_value(v1.children);
            set_random_value(v1.children_rshares2);
            set_random_value(v1.net_rshares);
            set_random_value(v1.abs_rshares);
            set_random_value(v1.vote_rshares);
            set_random_value(v1.children_abs_rshares);
            set_random_value(v1.cashout_time);
            set_random_value(v1.max_cashout_time);
            set_random_value(v1.total_vote_weight);
            set_random_value(v1.reward_weight);
            set_random_value(v1.total_payout_value);
            set_random_value(v1.curator_payout_value);
            set_random_value(v1.author_rewards);
            set_random_value(v1.net_votes);
            set_random_value(v1.root_comment);
            set_random_value(v1.max_accepted_payout);
            set_random_value(v1.percent_steem_dollars);
            set_random_value(v1.allow_replies);
            set_random_value(v1.allow_votes);
            set_random_value(v1.allow_curation_rewards);
            set_random_value(v1.beneficiaries);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_discussion_query) {
        try {
            golos::plugins::social_network::discussion_query v1, v2;

            set_random_value(v1.select_tags);
            set_random_value(v1.filter_tags);
            set_random_value(v1.select_authors);
            set_random_value(v1.truncate_body);
            set_random_value(v1.start_author);
            set_random_value(v1.start_permlink);
            set_random_value(v1.parent_author);
            set_random_value(v1.parent_permlink);
            set_random_value(v1.limit);
            set_random_value(v1.select_languages);
            set_random_value(v1.filter_languages);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_category_index) {
        try {
            golos::plugins::social_network::category_index v1, v2;

            set_random_value(v1.active);
            set_random_value(v1.recent);
            set_random_value(v1.best);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_languages_comment_metadata) {
        try {
            golos::plugins::social_network::languages::comment_metadata v1, v2;

            set_random_value(v1.language);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_languages_language_object) {
        try {
            golos::plugins::social_network::languages::language_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.created);
            set_random_value(v1.active);
            set_random_value(v1.cashout);
            set_random_value(v1.net_rshares);
            set_random_value(v1.net_votes);
            set_random_value(v1.hot);
            set_random_value(v1.trending);
            set_random_value(v1.promoted_balance);
            set_random_value(v1.children);
            set_random_value(v1.children_rshares2);
            set_random_value(v1.author);
            set_random_value(v1.parent);
            set_random_value(v1.comment);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_languages_language_stats_object) {
        try {
            golos::plugins::social_network::languages::language_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.language);
            set_random_value(v1.total_children_rshares2);
            set_random_value(v1.total_payout);
            set_random_value(v1.net_votes);
            set_random_value(v1.top_posts);
            set_random_value(v1.comments);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_languages_peer_stats_object) {
        try {
            golos::plugins::social_network::languages::peer_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.voter);
            set_random_value(v1.peer);
            set_random_value(v1.direct_positive_votes);
            set_random_value(v1.direct_votes);
            set_random_value(v1.indirect_positive_votes);
            set_random_value(v1.indirect_votes);
            set_random_value(v1.rank);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_languages_author_language_stats_object) {
        try {
            golos::plugins::social_network::languages::author_language_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.author);
            set_random_value(v1.language);
            set_random_value(v1.total_posts);
            set_random_value(v1.total_rewards);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_get_languages_r) {
        try {
            golos::plugins::social_network::get_languages_r v1, v2;

            set_random_value(v1.languages);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tags_tag_object) {
        try {
            golos::plugins::social_network::tags::tag_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.created);
            set_random_value(v1.active);
            set_random_value(v1.cashout);
            set_random_value(v1.net_rshares);
            set_random_value(v1.net_votes);
            set_random_value(v1.hot);
            set_random_value(v1.promoted_balance);
            set_random_value(v1.children);
            set_random_value(v1.children_rshares2);
            set_random_value(v1.author);
            set_random_value(v1.parent);
            set_random_value(v1.comment);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tags_tag_stats_object) {
        try {
            golos::plugins::social_network::tags::tag_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.tag);
            set_random_value(v1.total_children_rshares2);
            set_random_value(v1.total_payout);
            set_random_value(v1.net_votes);
            set_random_value(v1.top_posts);
            set_random_value(v1.comments);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tags_peer_stats_object) {
        try {
            golos::plugins::social_network::tags::peer_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.voter);
            set_random_value(v1.peer);
            set_random_value(v1.direct_positive_votes);
            set_random_value(v1.direct_votes);
            set_random_value(v1.indirect_positive_votes);
            set_random_value(v1.indirect_votes);
            set_random_value(v1.rank);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tags_comment_metadata) {
        try {
            golos::plugins::social_network::tags::comment_metadata v1, v2;

            set_random_value(v1.tags);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_social_network_tags_author_tag_stats_object) {
        try {
            golos::plugins::social_network::tags::author_tag_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.author);
            set_random_value(v1.tag);
            set_random_value(v1.total_posts);
            set_random_value(v1.total_rewards);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_scheduled_hardfork) {
        try {
            golos::plugins::database_api::scheduled_hardfork v1, v2;

            set_random_value(v1.hf_version);
            set_random_value(v1.live_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_withdraw_route) {
        try {
            golos::plugins::database_api::withdraw_route v1, v2;

            set_random_value(v1.from_account);
            set_random_value(v1.to_account);
            set_random_value(v1.percent);
            set_random_value(v1.auto_vest);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_withdraw_route_type) {
        try {
            golos::plugins::database_api::withdraw_route_type v1, v2;

            set_random_value(v1.incoming);
            set_random_value(v1.outgoing);
            set_random_value(v1.all);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_tag_count_object) {
        try {
            golos::plugins::database_api::tag_count_object v1, v2;

            set_random_value(v1.tag);
            set_random_value(v1.count);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_get_tags_used_by_author) {
        try {
            golos::plugins::database_api::get_tags_used_by_author v1, v2;

            set_random_value(v1.tags);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_signed_block_api_object) {
        try {
            golos::plugins::database_api::signed_block_api_object v1, v2;

            set_random_value(v1.block_id);
            set_random_value(v1.signing_key);
            set_random_value(v1.transaction_ids);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_operation_api_object) {
        try {
            golos::plugins::database_api::operation_api_object v1, v2;

            set_random_value(v1.trx_id);
            set_random_value(v1.block);
            set_random_value(v1.trx_in_block);
            set_random_value(v1.op_in_trx);
            set_random_value(v1.virtual_op);
            set_random_value(v1.timestamp);
            set_random_value(v1.op);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_applied_operation) {
        try {
            golos::plugins::database_api::applied_operation v1, v2;

            set_random_value(v1.trx_id);
            set_random_value(v1.block);
            set_random_value(v1.trx_in_block);
            set_random_value(v1.op_in_trx);
            set_random_value(v1.virtual_op);
            set_random_value(v1.timestamp);
            set_random_value(v1.op);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_extended_account) {
        try {
            golos::plugins::database_api::extended_account v1, v2;

            set_random_value(v1.vesting_balance);
            set_random_value(v1.reputation);
            set_random_value(v1.transfer_history);
            set_random_value(v1.market_history);
            set_random_value(v1.post_history);
            set_random_value(v1.vote_history);
            set_random_value(v1.other_history);
            set_random_value(v1.witness_votes);
            set_random_value(v1.tags_usage);
            set_random_value(v1.guest_bloggers);
            set_random_value(v1.open_orders);
            set_random_value(v1.comments);
            set_random_value(v1.feed);
            set_random_value(v1.blog);
            set_random_value(v1.recent_replies);
            set_random_value(v1.blog_category);
            set_random_value(v1.recommended);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_state) {
        try {
            golos::plugins::database_api::state v1, v2;

            set_random_value(v1.current_route);
            set_random_value(v1.props);
            set_random_value(v1.category_idx);
            set_random_value(v1.tag_idx);
            set_random_value(v1.categories);
            set_random_value(v1.tags);
            set_random_value(v1.content);
            set_random_value(v1.accounts);
            set_random_value(v1.pow_queue);
            set_random_value(v1.witnesses);
            set_random_value(v1.discussion_idx);
            set_random_value(v1.witness_schedule);
            set_random_value(v1.feed_price);
            set_random_value(v1.error);
            set_random_value(v1.market_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_extended_limit_order) {
        try {
            golos::plugins::database_api::extended_limit_order v1, v2;

            set_random_value(v1.real_price);
            set_random_value(v1.rewarded);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_order_history_item) {
        try {
            golos::plugins::database_api::order_history_item v1, v2;

            set_random_value(v1.time);
            set_random_value(v1.type);
            set_random_value(v1.sbd_quantity);
            set_random_value(v1.steem_quantity);
            set_random_value(v1.real_price);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_market) {
        try {
            golos::plugins::database_api::market v1, v2;

            set_random_value(v1.bids);
            set_random_value(v1.asks);
            set_random_value(v1.history);
            set_random_value(v1.price_history);
            set_random_value(v1.available_candlesticks);
            set_random_value(v1.available_zoom);
            set_random_value(v1.current_candlestick);
            set_random_value(v1.current_zoom);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_candle_stick) {
        try {
            golos::plugins::database_api::candle_stick v1, v2;

            set_random_value(v1.open_time);
            set_random_value(v1.period);
            set_random_value(v1.high);
            set_random_value(v1.low);
            set_random_value(v1.open);
            set_random_value(v1.close);
            set_random_value(v1.steem_volume);
            set_random_value(v1.dollar_volume);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_witness_api_object) {
        try {
            golos::plugins::database_api::witness_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.owner);
            set_random_value(v1.created);
            set_random_value(v1.url);
            set_random_value(v1.votes);
            set_random_value(v1.virtual_last_update);
            set_random_value(v1.virtual_position);
            set_random_value(v1.virtual_scheduled_time);
            set_random_value(v1.total_missed);
            set_random_value(v1.last_aslot);
            set_random_value(v1.last_confirmed_block_num);
            set_random_value(v1.pow_worker);
            set_random_value(v1.signing_key);
            set_random_value(v1.props);
            set_random_value(v1.sbd_exchange_rate);
            set_random_value(v1.last_sbd_exchange_update);
            set_random_value(v1.last_work);
            set_random_value(v1.running_version);
            set_random_value(v1.hardfork_version_vote);
            set_random_value(v1.hardfork_time_vote);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_account_recovery_request_api_object) {
        try {
            golos::plugins::database_api::account_recovery_request_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account_to_recover);
            set_random_value(v1.new_owner_authority);
            set_random_value(v1.expires);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_feed_history_api_object) {
        try {
            golos::plugins::database_api::feed_history_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.current_median_history);
            set_random_value(v1.price_history);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_owner_authority_history_api_object) {
        try {
            golos::plugins::database_api::owner_authority_history_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.previous_owner_authority);
            set_random_value(v1.last_valid_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_account_api_object) {
        try {
            golos::plugins::database_api::account_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.posting);
            set_random_value(v1.memo_key);
            set_random_value(v1.json_metadata);
            set_random_value(v1.proxy);
            set_random_value(v1.last_owner_update);
            set_random_value(v1.last_account_update);
            set_random_value(v1.created);
            set_random_value(v1.mined);
            set_random_value(v1.owner_challenged);
            set_random_value(v1.active_challenged);
            set_random_value(v1.last_owner_proved);
            set_random_value(v1.last_active_proved);
            set_random_value(v1.recovery_account);
            set_random_value(v1.last_account_recovery);
            set_random_value(v1.reset_account);
            set_random_value(v1.comment_count);
            set_random_value(v1.lifetime_vote_count);
            set_random_value(v1.post_count);
            set_random_value(v1.can_vote);
            set_random_value(v1.voting_power);
            set_random_value(v1.last_vote_time);
            set_random_value(v1.balance);
            set_random_value(v1.savings_balance);
            set_random_value(v1.sbd_balance);
            set_random_value(v1.sbd_seconds);
            set_random_value(v1.sbd_seconds_last_update);
            set_random_value(v1.sbd_last_interest_payment);
            set_random_value(v1.savings_sbd_balance);
            set_random_value(v1.savings_sbd_seconds);
            set_random_value(v1.savings_sbd_seconds_last_update);
            set_random_value(v1.savings_sbd_last_interest_payment);
            set_random_value(v1.savings_withdraw_requests);
            set_random_value(v1.vesting_shares);
            set_random_value(v1.delegated_vesting_shares);
            set_random_value(v1.received_vesting_shares);
            set_random_value(v1.vesting_withdraw_rate);
            set_random_value(v1.next_vesting_withdrawal);
            set_random_value(v1.withdrawn);
            set_random_value(v1.to_withdraw);
            set_random_value(v1.withdraw_routes);
            set_random_value(v1.curation_rewards);
            set_random_value(v1.posting_rewards);
            set_random_value(v1.proxied_vsf_votes);
            set_random_value(v1.witnesses_voted_for);
            set_random_value(v1.average_bandwidth);
            set_random_value(v1.lifetime_bandwidth);
            set_random_value(v1.last_bandwidth_update);
            set_random_value(v1.average_market_bandwidth);
            set_random_value(v1.last_market_bandwidth_update);
            set_random_value(v1.last_post);
            set_random_value(v1.last_root_post);
            set_random_value(v1.post_bandwidth);
            set_random_value(v1.new_average_bandwidth);
            set_random_value(v1.new_average_market_bandwidth);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_database_api_savings_withdraw_api_object) {
        try {
            golos::plugins::database_api::savings_withdraw_api_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.memo);
            set_random_value(v1.request_id);
            set_random_value(v1.amount);
            set_random_value(v1.complete);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_raw_block_get_raw_block_r) {
        try {
            golos::plugins::raw_block::get_raw_block_r v1, v2;

            set_random_value(v1.block_id);
            set_random_value(v1.previous);
            set_random_value(v1.timestamp);
            set_random_value(v1.raw_block);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_object) {
        try {
            golos::plugins::follow::follow_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.follower);
            set_random_value(v1.following);
            set_random_value(v1.what);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_feed_object) {
        try {
            golos::plugins::follow::feed_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.first_reblogged_by);
            set_random_value(v1.first_reblogged_on);
            set_random_value(v1.reblogged_by);
            set_random_value(v1.comment);
            set_random_value(v1.reblogs);
            set_random_value(v1.account_feed_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_blog_object) {
        try {
            golos::plugins::follow::blog_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.comment);
            set_random_value(v1.reblogged_on);
            set_random_value(v1.blog_feed_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_reputation_object) {
        try {
            golos::plugins::follow::reputation_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.reputation);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_count_object) {
        try {
            golos::plugins::follow::follow_count_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.follower_count);
            set_random_value(v1.following_count);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_blog_author_stats_object) {
        try {
            golos::plugins::follow::blog_author_stats_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.blogger);
            set_random_value(v1.guest);
            set_random_value(v1.count);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_operation) {
        try {
            golos::plugins::follow::follow_operation v1, v2;

            set_random_value(v1.follower);
            set_random_value(v1.following);
            set_random_value(v1.what);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_reblog_operation) {
        try {
            golos::plugins::follow::reblog_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.author);
            set_random_value(v1.permlink);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_type) {
        try {
            golos::plugins::follow::follow_type v1, v2;

            set_random_value(v1.undefined);
            set_random_value(v1.blog);
            set_random_value(v1.ignore);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_feed_entry) {
        try {
            golos::plugins::follow::feed_entry v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.reblog_by);
            set_random_value(v1.reblog_on);
            set_random_value(v1.entry_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_comment_feed_entry) {
        try {
            golos::plugins::follow::comment_feed_entry v1, v2;

            set_random_value(v1.comment);
            set_random_value(v1.reblog_by);
            set_random_value(v1.reblog_on);
            set_random_value(v1.entry_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_blog_entry) {
        try {
            golos::plugins::follow::blog_entry v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.blog);
            set_random_value(v1.reblog_on);
            set_random_value(v1.entry_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_comment_blog_entry) {
        try {
            golos::plugins::follow::comment_blog_entry v1, v2;

            set_random_value(v1.comment);
            set_random_value(v1.blog);
            set_random_value(v1.reblog_on);
            set_random_value(v1.entry_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_account_reputation) {
        try {
            golos::plugins::follow::account_reputation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.reputation);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_api_object) {
        try {
            golos::plugins::follow::follow_api_object v1, v2;

            set_random_value(v1.follower);
            set_random_value(v1.following);
            set_random_value(v1.what);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_reblog_count) {
        try {
            golos::plugins::follow::reblog_count v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.count);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_follow_follow_count_api_obj) {
        try {
            golos::plugins::follow::follow_count_api_obj v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.follower_count);
            set_random_value(v1.following_count);
            set_random_value(v1.limit);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_block_info_block_info) {
        try {
            golos::plugins::block_info::block_info v1, v2;

            set_random_value(v1.block_id);
            set_random_value(v1.block_size);
            set_random_value(v1.average_block_size);
            set_random_value(v1.aslot);
            set_random_value(v1.last_irreversible_block_num);
            set_random_value(v1.num_pow_witnesses);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_block_info_block_with_info) {
        try {
            golos::plugins::block_info::block_with_info v1, v2;

            set_random_value(v1.block);
            set_random_value(v1.info);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_network_broadcast_api_broadcast_transaction_synchronous_t) {
        try {
            golos::plugins::network_broadcast_api::broadcast_transaction_synchronous_t v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.block_num);
            set_random_value(v1.trx_num);
            set_random_value(v1.expired);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_account_by_key_key_lookup_object) {
        try {
            golos::plugins::account_by_key::key_lookup_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.key);
            set_random_value(v1.account);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_market_ticker) {
        try {
            golos::plugins::market_history::market_ticker v1, v2;

            set_random_value(v1.latest);
            set_random_value(v1.lowest_ask);
            set_random_value(v1.highest_bid);
            set_random_value(v1.percent_change);
            set_random_value(v1.steem_volume);
            set_random_value(v1.sbd_volume);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_market_volume) {
        try {
            golos::plugins::market_history::market_volume v1, v2;

            set_random_value(v1.steem_volume);
            set_random_value(v1.sbd_volume);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_order) {
        try {
            golos::plugins::market_history::order v1, v2;

            set_random_value(v1.price);
            set_random_value(v1.steem);
            set_random_value(v1.sbd);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_order_book) {
        try {
            golos::plugins::market_history::order_book v1, v2;

            set_random_value(v1.bids);
            set_random_value(v1.asks);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_market_trade) {
        try {
            golos::plugins::market_history::market_trade v1, v2;

            set_random_value(v1.date);
            set_random_value(v1.current_pays);
            set_random_value(v1.open_pays);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_limit_order) {
        try {
            golos::plugins::market_history::limit_order v1, v2;

            set_random_value(v1.real_price);
            set_random_value(v1.rewarded);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_bucket_object) {
        try {
            golos::plugins::market_history::bucket_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.open);
            set_random_value(v1.seconds);
            set_random_value(v1.high_steem);
            set_random_value(v1.high_sbd);
            set_random_value(v1.low_steem);
            set_random_value(v1.low_sbd);
            set_random_value(v1.open_steem);
            set_random_value(v1.open_sbd);
            set_random_value(v1.close_steem);
            set_random_value(v1.close_sbd);
            set_random_value(v1.steem_volume);
            set_random_value(v1.sbd_volume);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_market_history_order_history_object) {
        try {
            golos::plugins::market_history::order_history_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.time);
            set_random_value(v1.op);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_json_rpc_api_method_signature) {
        try {
            golos::plugins::json_rpc::api_method_signature v1, v2;

            set_random_value(v1.args);
            set_random_value(v1.ret);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_json_rpc_void_type) {
        try {
            golos::plugins::json_rpc::void_type v1, v2;


            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_json_rpc_json_rpc_error) {
        try {
            golos::plugins::json_rpc::json_rpc_error v1, v2;

            set_random_value(v1.code);
            set_random_value(v1.message);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugins_json_rpc_json_rpc_response) {
        try {
            golos::plugins::json_rpc::json_rpc_response v1, v2;

            set_random_value(v1.jsonrpc);
            set_random_value(v1.result);
            set_random_value(v1.error);
            set_random_value(v1.id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_wallet_wallet_data) {
        try {
            golos::wallet::wallet_data v1, v2;

            set_random_value(v1.cipher_keys);
            set_random_value(v1.ws_server);
            set_random_value(v1.ws_user);
            set_random_value(v1.ws_password);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_wallet_brain_key_info) {
        try {
            golos::wallet::brain_key_info v1, v2;

            set_random_value(v1.brain_priv_key);
            set_random_value(v1.wif_priv_key);
            set_random_value(v1.pub_key);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_wallet_plain_keys) {
        try {
            golos::wallet::plain_keys v1, v2;

            set_random_value(v1.checksum);
            set_random_value(v1.keys);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_wallet_authority_type) {
        try {
            golos::wallet::authority_type v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.posting);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_wallet_memo_data) {
        try {
            golos::wallet::memo_data v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.nonce);
            set_random_value(v1.check);
            set_random_value(v1.encrypted);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_connection_our_connection_state) {
        try {
            golos::network::peer_connection::our_connection_state v1, v2;

            set_random_value(v1.disconnected);
            set_random_value(v1.just_connected);
            set_random_value(v1.connection_accepted);
            set_random_value(v1.connection_rejected);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_connection_their_connection_state) {
        try {
            golos::network::peer_connection::their_connection_state v1, v2;

            set_random_value(v1.disconnected);
            set_random_value(v1.just_connected);
            set_random_value(v1.connection_accepted);
            set_random_value(v1.connection_rejected);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_connection_connection_negotiation_status) {
        try {
            golos::network::peer_connection::connection_negotiation_status v1, v2;

            set_random_value(v1.disconnected);
            set_random_value(v1.connecting);
            set_random_value(v1.connected);
            set_random_value(v1.accepting);
            set_random_value(v1.accepted);
            set_random_value(v1.hello_sent);
            set_random_value(v1.peer_connection_accepted);
            set_random_value(v1.peer_connection_rejected);
            set_random_value(v1.negotiation_complete);
            set_random_value(v1.closing);
            set_random_value(v1.closed);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_connection_timestamped_item_id) {
        try {
            golos::network::peer_connection::timestamped_item_id v1, v2;

            set_random_value(v1.item);
            set_random_value(v1.timestamp);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_potential_peer_last_connection_disposition) {
        try {
            golos::network::potential_peer_last_connection_disposition v1, v2;

            set_random_value(v1.never_attempted_to_connect);
            set_random_value(v1.last_connection_failed);
            set_random_value(v1.last_connection_rejected);
            set_random_value(v1.last_connection_handshaking_failed);
            set_random_value(v1.last_connection_succeeded);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_potential_peer_record) {
        try {
            golos::network::potential_peer_record v1, v2;

            set_random_value(v1.endpoint);
            set_random_value(v1.last_seen_time);
            set_random_value(v1.last_connection_disposition);
            set_random_value(v1.last_connection_attempt_time);
            set_random_value(v1.number_of_successful_connection_attempts);
            set_random_value(v1.number_of_failed_connection_attempts);
            set_random_value(v1.last_error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_core_message_type_enum) {
        try {
            golos::network::core_message_type_enum v1, v2;

            set_random_value(v1.trx_message_type);
            set_random_value(v1.block_message_type);
            set_random_value(v1.core_message_type_first);
            set_random_value(v1.item_ids_inventory_message_type);
            set_random_value(v1.blockchain_item_ids_inventory_message_type);
            set_random_value(v1.fetch_blockchain_item_ids_message_type);
            set_random_value(v1.fetch_items_message_type);
            set_random_value(v1.item_not_available_message_type);
            set_random_value(v1.hello_message_type);
            set_random_value(v1.connection_accepted_message_type);
            set_random_value(v1.connection_rejected_message_type);
            set_random_value(v1.address_request_message_type);
            set_random_value(v1.address_message_type);
            set_random_value(v1.closing_connection_message_type);
            set_random_value(v1.current_time_request_message_type);
            set_random_value(v1.current_time_reply_message_type);
            set_random_value(v1.check_firewall_message_type);
            set_random_value(v1.check_firewall_reply_message_type);
            set_random_value(v1.get_current_connections_request_message_type);
            set_random_value(v1.get_current_connections_reply_message_type);
            set_random_value(v1.core_message_type_last);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_trx_message) {
        try {
            golos::network::trx_message v1, v2;

            set_random_value(v1.trx);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_block_message) {
        try {
            golos::network::block_message v1, v2;

            set_random_value(v1.block);
            set_random_value(v1.block_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_item_id) {
        try {
            golos::network::item_id v1, v2;

            set_random_value(v1.item_type);
            set_random_value(v1.item_hash);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_item_ids_inventory_message) {
        try {
            golos::network::item_ids_inventory_message v1, v2;

            set_random_value(v1.item_type);
            set_random_value(v1.item_hashes_available);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_blockchain_item_ids_inventory_message) {
        try {
            golos::network::blockchain_item_ids_inventory_message v1, v2;

            set_random_value(v1.total_remaining_item_count);
            set_random_value(v1.item_type);
            set_random_value(v1.item_hashes_available);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_fetch_blockchain_item_ids_message) {
        try {
            golos::network::fetch_blockchain_item_ids_message v1, v2;

            set_random_value(v1.item_type);
            set_random_value(v1.blockchain_synopsis);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_fetch_items_message) {
        try {
            golos::network::fetch_items_message v1, v2;

            set_random_value(v1.item_type);
            set_random_value(v1.items_to_fetch);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_item_not_available_message) {
        try {
            golos::network::item_not_available_message v1, v2;

            set_random_value(v1.requested_item);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_hello_message) {
        try {
            golos::network::hello_message v1, v2;

            set_random_value(v1.user_agent);
            set_random_value(v1.core_protocol_version);
            set_random_value(v1.inbound_address);
            set_random_value(v1.inbound_port);
            set_random_value(v1.outbound_port);
            set_random_value(v1.node_public_key);
            set_random_value(v1.signed_shared_secret);
            set_random_value(v1.user_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_rejection_reason_code) {
        try {
            golos::network::rejection_reason_code v1, v2;

            set_random_value(v1.unspecified);
            set_random_value(v1.different_chain);
            set_random_value(v1.already_connected);
            set_random_value(v1.connected_to_self);
            set_random_value(v1.not_accepting_connections);
            set_random_value(v1.blocked);
            set_random_value(v1.invalid_hello_message);
            set_random_value(v1.client_too_old);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_connection_rejected_message) {
        try {
            golos::network::connection_rejected_message v1, v2;

            set_random_value(v1.user_agent);
            set_random_value(v1.core_protocol_version);
            set_random_value(v1.remote_endpoint);
            set_random_value(v1.reason_code);
            set_random_value(v1.reason_string);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_address_info) {
        try {
            golos::network::address_info v1, v2;

            set_random_value(v1.remote_endpoint);
            set_random_value(v1.last_seen_time);
            set_random_value(v1.latency);
            set_random_value(v1.node_id);
            set_random_value(v1.direction);
            set_random_value(v1.firewalled);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_address_message) {
        try {
            golos::network::address_message v1, v2;

            set_random_value(v1.addresses);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_closing_connection_message) {
        try {
            golos::network::closing_connection_message v1, v2;

            set_random_value(v1.reason_for_closing);
            set_random_value(v1.closing_due_to_error);
            set_random_value(v1.error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_connection_direction) {
        try {
            golos::network::peer_connection_direction v1, v2;

            set_random_value(v1.unknown);
            set_random_value(v1.inbound);
            set_random_value(v1.outbound);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_firewalled_state) {
        try {
            golos::network::firewalled_state v1, v2;

            set_random_value(v1.unknown);
            set_random_value(v1.firewalled);
            set_random_value(v1.not_firewalled);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_current_time_request_message) {
        try {
            golos::network::current_time_request_message v1, v2;

            set_random_value(v1.request_sent_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_current_time_reply_message) {
        try {
            golos::network::current_time_reply_message v1, v2;

            set_random_value(v1.request_sent_time);
            set_random_value(v1.request_received_time);
            set_random_value(v1.reply_transmitted_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_firewall_check_result) {
        try {
            golos::network::firewall_check_result v1, v2;

            set_random_value(v1.unable_to_check);
            set_random_value(v1.unable_to_connect);
            set_random_value(v1.connection_successful);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_check_firewall_message) {
        try {
            golos::network::check_firewall_message v1, v2;

            set_random_value(v1.node_id);
            set_random_value(v1.endpoint_to_check);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_check_firewall_reply_message) {
        try {
            golos::network::check_firewall_reply_message v1, v2;

            set_random_value(v1.node_id);
            set_random_value(v1.endpoint_checked);
            set_random_value(v1.result);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_current_connection_data) {
        try {
            golos::network::current_connection_data v1, v2;

            set_random_value(v1.connection_duration);
            set_random_value(v1.remote_endpoint);
            set_random_value(v1.node_id);
            set_random_value(v1.clock_offset);
            set_random_value(v1.round_trip_delay);
            set_random_value(v1.connection_direction);
            set_random_value(v1.firewalled);
            set_random_value(v1.user_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_get_current_connections_reply_message) {
        try {
            golos::network::get_current_connections_reply_message v1, v2;

            set_random_value(v1.upload_rate_one_minute);
            set_random_value(v1.download_rate_one_minute);
            set_random_value(v1.upload_rate_fifteen_minutes);
            set_random_value(v1.download_rate_fifteen_minutes);
            set_random_value(v1.upload_rate_one_hour);
            set_random_value(v1.download_rate_one_hour);
            set_random_value(v1.current_connections);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_message_header) {
        try {
            golos::network::message_header v1, v2;

            set_random_value(v1.size);
            set_random_value(v1.msg_type);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_message) {
        try {
            golos::network::message v1, v2;

            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_message_propagation_data) {
        try {
            golos::network::message_propagation_data v1, v2;

            set_random_value(v1.received_time);
            set_random_value(v1.validated_time);
            set_random_value(v1.originating_peer);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_peer_status) {
        try {
            golos::network::peer_status v1, v2;

            set_random_value(v1.version);
            set_random_value(v1.host);
            set_random_value(v1.info);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_network_detail_node_configuration) {
        try {
            golos::network::detail::node_configuration v1, v2;

            set_random_value(v1.listen_endpoint);
            set_random_value(v1.accept_incoming_connections);
            set_random_value(v1.wait_if_endpoint_is_busy);
            set_random_value(v1.private_key);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_witness_object_witness_schedule_type) {
        try {
            golos::chain::witness_object::witness_schedule_type v1, v2;

            set_random_value(v1.top19);
            set_random_value(v1.timeshare);
            set_random_value(v1.miner);
            set_random_value(v1.none);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_witness_object) {
        try {
            golos::chain::witness_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.owner);
            set_random_value(v1.created);
            set_random_value(v1.url);
            set_random_value(v1.votes);
            set_random_value(v1.schedule);
            set_random_value(v1.virtual_last_update);
            set_random_value(v1.virtual_position);
            set_random_value(v1.virtual_scheduled_time);
            set_random_value(v1.total_missed);
            set_random_value(v1.last_aslot);
            set_random_value(v1.last_confirmed_block_num);
            set_random_value(v1.pow_worker);
            set_random_value(v1.signing_key);
            set_random_value(v1.props);
            set_random_value(v1.sbd_exchange_rate);
            set_random_value(v1.last_sbd_exchange_update);
            set_random_value(v1.last_work);
            set_random_value(v1.running_version);
            set_random_value(v1.hardfork_version_vote);
            set_random_value(v1.hardfork_time_vote);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_witness_vote_object) {
        try {
            golos::chain::witness_vote_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.witness);
            set_random_value(v1.account);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_witness_schedule_object) {
        try {
            golos::chain::witness_schedule_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.current_virtual_time);
            set_random_value(v1.next_shuffle_block_num);
            set_random_value(v1.current_shuffled_witnesses);
            set_random_value(v1.num_scheduled_witnesses);
            set_random_value(v1.top19_weight);
            set_random_value(v1.timeshare_weight);
            set_random_value(v1.miner_weight);
            set_random_value(v1.witness_pay_normalization_factor);
            set_random_value(v1.median_props);
            set_random_value(v1.majority_version);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_keys) {
        try {
            golos::chain::account_keys v1, v2;

            set_random_value(v1.owner_key);
            set_random_value(v1.active_key);
            set_random_value(v1.posting_key);
            set_random_value(v1.memo_key);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_balances) {
        try {
            golos::chain::account_balances v1, v2;

            set_random_value(v1.assets);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_snapshot_summary) {
        try {
            golos::chain::snapshot_summary v1, v2;

            set_random_value(v1.balance);
            set_random_value(v1.sbd_balance);
            set_random_value(v1.total_vesting_shares);
            set_random_value(v1.total_vesting_fund_steem);
            set_random_value(v1.accounts_count);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_summary) {
        try {
            golos::chain::account_summary v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.posting_rewards);
            set_random_value(v1.curation_rewards);
            set_random_value(v1.keys);
            set_random_value(v1.balances);
            set_random_value(v1.json_metadata);
            set_random_value(v1.proxy);
            set_random_value(v1.post_count);
            set_random_value(v1.recovery_account);
            set_random_value(v1.reputation);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_snapshot_state) {
        try {
            golos::chain::snapshot_state v1, v2;

            set_random_value(v1.timestamp);
            set_random_value(v1.head_block_num);
            set_random_value(v1.head_block_id);
            set_random_value(v1.chain_id);
            set_random_value(v1.summary);
            set_random_value(v1.accounts);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_immutable_chain_parameters) {
        try {
            golos::chain::immutable_chain_parameters v1, v2;

            set_random_value(v1.min_committee_member_count);
            set_random_value(v1.min_witness_count);
            set_random_value(v1.num_special_accounts);
            set_random_value(v1.num_special_assets);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_transaction_object) {
        try {
            golos::chain::transaction_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.packed_trx);
            set_random_value(v1.trx_id);
            set_random_value(v1.expiration);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_block_summary_object) {
        try {
            golos::chain::block_summary_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.block_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_comment_mode) {
        try {
            golos::chain::comment_mode v1, v2;

            set_random_value(v1.first_payout);
            set_random_value(v1.second_payout);
            set_random_value(v1.archived);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_comment_object) {
        try {
            golos::chain::comment_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.category);
            set_random_value(v1.parent_author);
            set_random_value(v1.parent_permlink);
            set_random_value(v1.title);
            set_random_value(v1.body);
            set_random_value(v1.json_metadata);
            set_random_value(v1.last_update);
            set_random_value(v1.created);
            set_random_value(v1.active);
            set_random_value(v1.last_payout);
            set_random_value(v1.depth);
            set_random_value(v1.children);
            set_random_value(v1.children_rshares2);
            set_random_value(v1.net_rshares);
            set_random_value(v1.abs_rshares);
            set_random_value(v1.vote_rshares);
            set_random_value(v1.children_abs_rshares);
            set_random_value(v1.cashout_time);
            set_random_value(v1.max_cashout_time);
            set_random_value(v1.total_vote_weight);
            set_random_value(v1.reward_weight);
            set_random_value(v1.total_payout_value);
            set_random_value(v1.curator_payout_value);
            set_random_value(v1.beneficiary_payout_value);
            set_random_value(v1.author_rewards);
            set_random_value(v1.net_votes);
            set_random_value(v1.root_comment);
            set_random_value(v1.mode);
            set_random_value(v1.max_accepted_payout);
            set_random_value(v1.percent_steem_dollars);
            set_random_value(v1.allow_replies);
            set_random_value(v1.allow_votes);
            set_random_value(v1.allow_curation_rewards);
            set_random_value(v1.beneficiaries);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_comment_vote_object) {
        try {
            golos::chain::comment_vote_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.voter);
            set_random_value(v1.comment);
            set_random_value(v1.weight);
            set_random_value(v1.rshares);
            set_random_value(v1.vote_percent);
            set_random_value(v1.last_update);
            set_random_value(v1.num_changes);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_category_object) {
        try {
            golos::chain::category_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.abs_rshares);
            set_random_value(v1.total_payouts);
            set_random_value(v1.discussions);
            set_random_value(v1.last_update);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_object) {
        try {
            golos::chain::account_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.name);
            set_random_value(v1.memo_key);
            set_random_value(v1.json_metadata);
            set_random_value(v1.proxy);
            set_random_value(v1.last_account_update);
            set_random_value(v1.created);
            set_random_value(v1.mined);
            set_random_value(v1.owner_challenged);
            set_random_value(v1.active_challenged);
            set_random_value(v1.last_owner_proved);
            set_random_value(v1.last_active_proved);
            set_random_value(v1.recovery_account);
            set_random_value(v1.last_account_recovery);
            set_random_value(v1.reset_account);
            set_random_value(v1.comment_count);
            set_random_value(v1.lifetime_vote_count);
            set_random_value(v1.post_count);
            set_random_value(v1.can_vote);
            set_random_value(v1.voting_power);
            set_random_value(v1.last_vote_time);
            set_random_value(v1.balance);
            set_random_value(v1.savings_balance);
            set_random_value(v1.sbd_balance);
            set_random_value(v1.sbd_seconds);
            set_random_value(v1.sbd_seconds_last_update);
            set_random_value(v1.sbd_last_interest_payment);
            set_random_value(v1.savings_sbd_balance);
            set_random_value(v1.savings_sbd_seconds);
            set_random_value(v1.savings_sbd_seconds_last_update);
            set_random_value(v1.savings_sbd_last_interest_payment);
            set_random_value(v1.savings_withdraw_requests);
            set_random_value(v1.vesting_shares);
            set_random_value(v1.vesting_withdraw_rate);
            set_random_value(v1.next_vesting_withdrawal);
            set_random_value(v1.withdrawn);
            set_random_value(v1.to_withdraw);
            set_random_value(v1.withdraw_routes);
            set_random_value(v1.curation_rewards);
            set_random_value(v1.posting_rewards);
            set_random_value(v1.proxied_vsf_votes);
            set_random_value(v1.witnesses_voted_for);
            set_random_value(v1.last_post);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_authority_object) {
        try {
            golos::chain::account_authority_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.posting);
            set_random_value(v1.last_owner_update);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_bandwidth_object) {
        try {
            golos::chain::account_bandwidth_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.type);
            set_random_value(v1.average_bandwidth);
            set_random_value(v1.lifetime_bandwidth);
            set_random_value(v1.last_bandwidth_update);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_owner_authority_history_object) {
        try {
            golos::chain::owner_authority_history_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.previous_owner_authority);
            set_random_value(v1.last_valid_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_recovery_request_object) {
        try {
            golos::chain::account_recovery_request_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account_to_recover);
            set_random_value(v1.new_owner_authority);
            set_random_value(v1.expires);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_change_recovery_account_request_object) {
        try {
            golos::chain::change_recovery_account_request_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account_to_recover);
            set_random_value(v1.recovery_account);
            set_random_value(v1.effective_on);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_operation_object) {
        try {
            golos::chain::operation_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.trx_id);
            set_random_value(v1.block);
            set_random_value(v1.trx_in_block);
            set_random_value(v1.op_in_trx);
            set_random_value(v1.virtual_op);
            set_random_value(v1.timestamp);
            set_random_value(v1.serialized_op);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_account_history_object) {
        try {
            golos::chain::account_history_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.sequence);
            set_random_value(v1.op);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_hardfork_property_object) {
        try {
            golos::chain::hardfork_property_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.processed_hardforks);
            set_random_value(v1.last_hardfork);
            set_random_value(v1.current_hardfork_version);
            set_random_value(v1.next_hardfork);
            set_random_value(v1.next_hardfork_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_dynamic_global_property_object) {
        try {
            golos::chain::dynamic_global_property_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.head_block_number);
            set_random_value(v1.head_block_id);
            set_random_value(v1.time);
            set_random_value(v1.current_witness);
            set_random_value(v1.total_pow);
            set_random_value(v1.num_pow_witnesses);
            set_random_value(v1.virtual_supply);
            set_random_value(v1.current_supply);
            set_random_value(v1.confidential_supply);
            set_random_value(v1.current_sbd_supply);
            set_random_value(v1.confidential_sbd_supply);
            set_random_value(v1.total_vesting_fund_steem);
            set_random_value(v1.total_vesting_shares);
            set_random_value(v1.total_reward_fund_steem);
            set_random_value(v1.total_reward_shares2);
            set_random_value(v1.sbd_interest_rate);
            set_random_value(v1.sbd_print_rate);
            set_random_value(v1.average_block_size);
            set_random_value(v1.maximum_block_size);
            set_random_value(v1.current_aslot);
            set_random_value(v1.recent_slots_filled);
            set_random_value(v1.participation_count);
            set_random_value(v1.last_irreversible_block_num);
            set_random_value(v1.max_virtual_bandwidth);
            set_random_value(v1.current_reserve_ratio);
            set_random_value(v1.vote_regeneration_per_day);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_shared_authority) {
        try {
            golos::chain::shared_authority v1, v2;

            set_random_value(v1.weight_threshold);
            set_random_value(v1.account_auths);
            set_random_value(v1.key_auths);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_object_type) {
        try {
            golos::chain::object_type v1, v2;

            set_random_value(v1.dynamic_global_property_object_type);
            set_random_value(v1.account_object_type);
            set_random_value(v1.account_authority_object_type);
            set_random_value(v1.account_bandwidth_object_type);
            set_random_value(v1.witness_object_type);
            set_random_value(v1.transaction_object_type);
            set_random_value(v1.block_summary_object_type);
            set_random_value(v1.witness_schedule_object_type);
            set_random_value(v1.comment_object_type);
            set_random_value(v1.category_object_type);
            set_random_value(v1.comment_vote_object_type);
            set_random_value(v1.witness_vote_object_type);
            set_random_value(v1.limit_order_object_type);
            set_random_value(v1.feed_history_object_type);
            set_random_value(v1.convert_request_object_type);
            set_random_value(v1.liquidity_reward_balance_object_type);
            set_random_value(v1.operation_object_type);
            set_random_value(v1.account_history_object_type);
            set_random_value(v1.hardfork_property_object_type);
            set_random_value(v1.withdraw_vesting_route_object_type);
            set_random_value(v1.owner_authority_history_object_type);
            set_random_value(v1.account_recovery_request_object_type);
            set_random_value(v1.change_recovery_account_request_object_type);
            set_random_value(v1.escrow_object_type);
            set_random_value(v1.savings_withdraw_object_type);
            set_random_value(v1.decline_voting_rights_request_object_type);
            set_random_value(v1.block_stats_object_type);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_bandwidth_type) {
        try {
            golos::chain::bandwidth_type v1, v2;

            set_random_value(v1.post);
            set_random_value(v1.forum);
            set_random_value(v1.market);
            set_random_value(v1.old_forum);
            set_random_value(v1.old_market);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_limit_order_object) {
        try {
            golos::chain::limit_order_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.created);
            set_random_value(v1.expiration);
            set_random_value(v1.seller);
            set_random_value(v1.orderid);
            set_random_value(v1.for_sale);
            set_random_value(v1.sell_price);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_feed_history_object) {
        try {
            golos::chain::feed_history_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.current_median_history);
            set_random_value(v1.price_history);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_convert_request_object) {
        try {
            golos::chain::convert_request_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.owner);
            set_random_value(v1.requestid);
            set_random_value(v1.amount);
            set_random_value(v1.conversion_date);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_liquidity_reward_balance_object) {
        try {
            golos::chain::liquidity_reward_balance_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.owner);
            set_random_value(v1.steem_volume);
            set_random_value(v1.sbd_volume);
            set_random_value(v1.weight);
            set_random_value(v1.last_update);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_withdraw_vesting_route_object) {
        try {
            golos::chain::withdraw_vesting_route_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.from_account);
            set_random_value(v1.to_account);
            set_random_value(v1.percent);
            set_random_value(v1.auto_vest);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_savings_withdraw_object) {
        try {
            golos::chain::savings_withdraw_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.memo);
            set_random_value(v1.request_id);
            set_random_value(v1.amount);
            set_random_value(v1.complete);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_escrow_object) {
        try {
            golos::chain::escrow_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.escrow_id);
            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.agent);
            set_random_value(v1.ratification_deadline);
            set_random_value(v1.escrow_expiration);
            set_random_value(v1.sbd_balance);
            set_random_value(v1.steem_balance);
            set_random_value(v1.pending_fee);
            set_random_value(v1.to_approved);
            set_random_value(v1.agent_approved);
            set_random_value(v1.disputed);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_decline_voting_rights_request_object) {
        try {
            golos::chain::decline_voting_rights_request_object v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.account);
            set_random_value(v1.effective_date);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_object_schema_repr) {
        try {
            golos::chain::object_schema_repr v1, v2;

            set_random_value(v1.space_type);
            set_random_value(v1.type);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_operation_schema_repr) {
        try {
            golos::chain::operation_schema_repr v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.type);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_chain_db_schema) {
        try {
            golos::chain::db_schema v1, v2;

            set_random_value(v1.types);
            set_random_value(v1.object_types);
            set_random_value(v1.operation_type);
            set_random_value(v1.custom_operation_types);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_public_key_type) {
        try {
            golos::protocol::public_key_type v1, v2;

            set_random_value(v1.key_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_public_key_type_binary_key) {
        try {
            golos::protocol::public_key_type::binary_key v1, v2;

            set_random_value(v1.data);
            set_random_value(v1.check);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_extended_public_key_type) {
        try {
            golos::protocol::extended_public_key_type v1, v2;

            set_random_value(v1.key_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_extended_public_key_type_binary_key) {
        try {
            golos::protocol::extended_public_key_type::binary_key v1, v2;

            set_random_value(v1.check);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_extended_private_key_type) {
        try {
            golos::protocol::extended_private_key_type v1, v2;

            set_random_value(v1.key_data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_extended_private_key_type_binary_key) {
        try {
            golos::protocol::extended_private_key_type::binary_key v1, v2;

            set_random_value(v1.check);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_void_t) {
        try {
            golos::void_t v1, v2;


            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_block_header) {
        try {
            golos::protocol::block_header v1, v2;

            set_random_value(v1.previous);
            set_random_value(v1.timestamp);
            set_random_value(v1.witness);
            set_random_value(v1.transaction_merkle_root);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_signed_block_header) {
        try {
            golos::protocol::signed_block_header v1, v2;

            set_random_value(v1.witness_signature);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_signed_block) {
        try {
            golos::protocol::signed_block v1, v2;

            set_random_value(v1.transactions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_version) {
        try {
            golos::protocol::version v1, v2;

            set_random_value(v1.v_num);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_hardfork_version) {
        try {
            golos::protocol::hardfork_version v1, v2;


            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_hardfork_version_vote) {
        try {
            golos::protocol::hardfork_version_vote v1, v2;

            set_random_value(v1.hf_version);
            set_random_value(v1.hf_time);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_transaction) {
        try {
            golos::protocol::transaction v1, v2;

            set_random_value(v1.ref_block_num);
            set_random_value(v1.ref_block_prefix);
            set_random_value(v1.expiration);
            set_random_value(v1.operations);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_signed_transaction) {
        try {
            golos::protocol::signed_transaction v1, v2;

            set_random_value(v1.signatures);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_annotated_signed_transaction) {
        try {
            golos::protocol::annotated_signed_transaction v1, v2;

            set_random_value(v1.transaction_id);
            set_random_value(v1.block_num);
            set_random_value(v1.transaction_num);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_asset) {
        try {
            golos::protocol::asset v1, v2;

            set_random_value(v1.amount);
            set_random_value(v1.symbol);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_price) {
        try {
            golos::protocol::price v1, v2;

            set_random_value(v1.base);
            set_random_value(v1.quote);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_transfer_to_savings_operation) {
        try {
            golos::protocol::transfer_to_savings_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.amount);
            set_random_value(v1.memo);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_transfer_from_savings_operation) {
        try {
            golos::protocol::transfer_from_savings_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.request_id);
            set_random_value(v1.to);
            set_random_value(v1.amount);
            set_random_value(v1.memo);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_cancel_transfer_from_savings_operation) {
        try {
            golos::protocol::cancel_transfer_from_savings_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.request_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_reset_account_operation) {
        try {
            golos::protocol::reset_account_operation v1, v2;

            set_random_value(v1.reset_account);
            set_random_value(v1.account_to_reset);
            set_random_value(v1.new_owner_authority);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_set_reset_account_operation) {
        try {
            golos::protocol::set_reset_account_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.current_reset_account);
            set_random_value(v1.reset_account);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_report_over_production_operation) {
        try {
            golos::protocol::report_over_production_operation v1, v2;

            set_random_value(v1.reporter);
            set_random_value(v1.first_block);
            set_random_value(v1.second_block);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_convert_operation) {
        try {
            golos::protocol::convert_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.requestid);
            set_random_value(v1.amount);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_feed_publish_operation) {
        try {
            golos::protocol::feed_publish_operation v1, v2;

            set_random_value(v1.publisher);
            set_random_value(v1.exchange_rate);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_pow) {
        try {
            golos::protocol::pow v1, v2;

            set_random_value(v1.worker);
            set_random_value(v1.input);
            set_random_value(v1.signature);
            set_random_value(v1.work);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_pow2) {
        try {
            golos::protocol::pow2 v1, v2;

            set_random_value(v1.input);
            set_random_value(v1.pow_summary);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_pow2_input) {
        try {
            golos::protocol::pow2_input v1, v2;

            set_random_value(v1.worker_account);
            set_random_value(v1.prev_block);
            set_random_value(v1.nonce);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_equihash_pow) {
        try {
            golos::protocol::equihash_pow v1, v2;

            set_random_value(v1.input);
            set_random_value(v1.proof);
            set_random_value(v1.prev_block);
            set_random_value(v1.pow_summary);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_chain_properties) {
        try {
            golos::protocol::chain_properties v1, v2;

            set_random_value(v1.account_creation_fee);
            set_random_value(v1.maximum_block_size);
            set_random_value(v1.sbd_interest_rate);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_pow_operation) {
        try {
            golos::protocol::pow_operation v1, v2;

            set_random_value(v1.worker_account);
            set_random_value(v1.block_id);
            set_random_value(v1.nonce);
            set_random_value(v1.work);
            set_random_value(v1.props);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_pow2_operation) {
        try {
            golos::protocol::pow2_operation v1, v2;

            set_random_value(v1.work);
            set_random_value(v1.new_owner_key);
            set_random_value(v1.props);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_account_create_operation) {
        try {
            golos::protocol::account_create_operation v1, v2;

            set_random_value(v1.fee);
            set_random_value(v1.creator);
            set_random_value(v1.new_account_name);
            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.posting);
            set_random_value(v1.memo_key);
            set_random_value(v1.json_metadata);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_account_update_operation) {
        try {
            golos::protocol::account_update_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.posting);
            set_random_value(v1.memo_key);
            set_random_value(v1.json_metadata);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_transfer_operation) {
        try {
            golos::protocol::transfer_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.amount);
            set_random_value(v1.memo);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_transfer_to_vesting_operation) {
        try {
            golos::protocol::transfer_to_vesting_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.amount);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_withdraw_vesting_operation) {
        try {
            golos::protocol::withdraw_vesting_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.vesting_shares);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_set_withdraw_vesting_route_operation) {
        try {
            golos::protocol::set_withdraw_vesting_route_operation v1, v2;

            set_random_value(v1.from_account);
            set_random_value(v1.to_account);
            set_random_value(v1.percent);
            set_random_value(v1.auto_vest);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_witness_update_operation) {
        try {
            golos::protocol::witness_update_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.url);
            set_random_value(v1.block_signing_key);
            set_random_value(v1.props);
            set_random_value(v1.fee);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_account_witness_vote_operation) {
        try {
            golos::protocol::account_witness_vote_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.witness);
            set_random_value(v1.approve);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_account_witness_proxy_operation) {
        try {
            golos::protocol::account_witness_proxy_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.proxy);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_operation) {
        try {
            golos::protocol::comment_operation v1, v2;

            set_random_value(v1.parent_author);
            set_random_value(v1.parent_permlink);
            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.title);
            set_random_value(v1.body);
            set_random_value(v1.json_metadata);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_vote_operation) {
        try {
            golos::protocol::vote_operation v1, v2;

            set_random_value(v1.voter);
            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.weight);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_custom_operation) {
        try {
            golos::protocol::custom_operation v1, v2;

            set_random_value(v1.required_auths);
            set_random_value(v1.id);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_custom_json_operation) {
        try {
            golos::protocol::custom_json_operation v1, v2;

            set_random_value(v1.required_auths);
            set_random_value(v1.required_posting_auths);
            set_random_value(v1.id);
            set_random_value(v1.json);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_custom_binary_operation) {
        try {
            golos::protocol::custom_binary_operation v1, v2;

            set_random_value(v1.required_owner_auths);
            set_random_value(v1.required_active_auths);
            set_random_value(v1.required_posting_auths);
            set_random_value(v1.required_auths);
            set_random_value(v1.id);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_limit_order_create_operation) {
        try {
            golos::protocol::limit_order_create_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.orderid);
            set_random_value(v1.amount_to_sell);
            set_random_value(v1.min_to_receive);
            set_random_value(v1.fill_or_kill);
            set_random_value(v1.expiration);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_limit_order_create2_operation) {
        try {
            golos::protocol::limit_order_create2_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.orderid);
            set_random_value(v1.amount_to_sell);
            set_random_value(v1.exchange_rate);
            set_random_value(v1.fill_or_kill);
            set_random_value(v1.expiration);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_limit_order_cancel_operation) {
        try {
            golos::protocol::limit_order_cancel_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.orderid);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_delete_comment_operation) {
        try {
            golos::protocol::delete_comment_operation v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_beneficiary_route_type) {
        try {
            golos::protocol::beneficiary_route_type v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.weight);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_payout_beneficiaries) {
        try {
            golos::protocol::comment_payout_beneficiaries v1, v2;

            set_random_value(v1.beneficiaries);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_options_operation) {
        try {
            golos::protocol::comment_options_operation v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.max_accepted_payout);
            set_random_value(v1.percent_steem_dollars);
            set_random_value(v1.allow_votes);
            set_random_value(v1.allow_curation_rewards);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_escrow_transfer_operation) {
        try {
            golos::protocol::escrow_transfer_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.sbd_amount);
            set_random_value(v1.steem_amount);
            set_random_value(v1.escrow_id);
            set_random_value(v1.agent);
            set_random_value(v1.fee);
            set_random_value(v1.json_meta);
            set_random_value(v1.ratification_deadline);
            set_random_value(v1.escrow_expiration);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_escrow_approve_operation) {
        try {
            golos::protocol::escrow_approve_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.agent);
            set_random_value(v1.who);
            set_random_value(v1.escrow_id);
            set_random_value(v1.approve);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_escrow_dispute_operation) {
        try {
            golos::protocol::escrow_dispute_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.agent);
            set_random_value(v1.who);
            set_random_value(v1.escrow_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_escrow_release_operation) {
        try {
            golos::protocol::escrow_release_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.agent);
            set_random_value(v1.who);
            set_random_value(v1.receiver);
            set_random_value(v1.escrow_id);
            set_random_value(v1.sbd_amount);
            set_random_value(v1.steem_amount);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_challenge_authority_operation) {
        try {
            golos::protocol::challenge_authority_operation v1, v2;

            set_random_value(v1.challenger);
            set_random_value(v1.challenged);
            set_random_value(v1.require_owner);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_prove_authority_operation) {
        try {
            golos::protocol::prove_authority_operation v1, v2;

            set_random_value(v1.challenged);
            set_random_value(v1.require_owner);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_request_account_recovery_operation) {
        try {
            golos::protocol::request_account_recovery_operation v1, v2;

            set_random_value(v1.recovery_account);
            set_random_value(v1.account_to_recover);
            set_random_value(v1.new_owner_authority);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_recover_account_operation) {
        try {
            golos::protocol::recover_account_operation v1, v2;

            set_random_value(v1.account_to_recover);
            set_random_value(v1.new_owner_authority);
            set_random_value(v1.recent_owner_authority);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_change_recovery_account_operation) {
        try {
            golos::protocol::change_recovery_account_operation v1, v2;

            set_random_value(v1.account_to_recover);
            set_random_value(v1.new_recovery_account);
            set_random_value(v1.extensions);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_decline_voting_rights_operation) {
        try {
            golos::protocol::decline_voting_rights_operation v1, v2;

            set_random_value(v1.account);
            set_random_value(v1.decline);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_author_reward_operation) {
        try {
            golos::protocol::author_reward_operation v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.sbd_payout);
            set_random_value(v1.steem_payout);
            set_random_value(v1.vesting_payout);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_curation_reward_operation) {
        try {
            golos::protocol::curation_reward_operation v1, v2;

            set_random_value(v1.curator);
            set_random_value(v1.reward);
            set_random_value(v1.comment_author);
            set_random_value(v1.comment_permlink);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_reward_operation) {
        try {
            golos::protocol::comment_reward_operation v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.payout);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_fill_convert_request_operation) {
        try {
            golos::protocol::fill_convert_request_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.requestid);
            set_random_value(v1.amount_in);
            set_random_value(v1.amount_out);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_liquidity_reward_operation) {
        try {
            golos::protocol::liquidity_reward_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.payout);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_interest_operation) {
        try {
            golos::protocol::interest_operation v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.interest);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_fill_vesting_withdraw_operation) {
        try {
            golos::protocol::fill_vesting_withdraw_operation v1, v2;

            set_random_value(v1.from_account);
            set_random_value(v1.to_account);
            set_random_value(v1.withdrawn);
            set_random_value(v1.deposited);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_shutdown_witness_operation) {
        try {
            golos::protocol::shutdown_witness_operation v1, v2;

            set_random_value(v1.owner);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_fill_order_operation) {
        try {
            golos::protocol::fill_order_operation v1, v2;

            set_random_value(v1.current_owner);
            set_random_value(v1.current_orderid);
            set_random_value(v1.current_pays);
            set_random_value(v1.open_owner);
            set_random_value(v1.open_orderid);
            set_random_value(v1.open_pays);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_fill_transfer_from_savings_operation) {
        try {
            golos::protocol::fill_transfer_from_savings_operation v1, v2;

            set_random_value(v1.from);
            set_random_value(v1.to);
            set_random_value(v1.amount);
            set_random_value(v1.request_id);
            set_random_value(v1.memo);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_hardfork_operation) {
        try {
            golos::protocol::hardfork_operation v1, v2;

            set_random_value(v1.hardfork_id);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_payout_update_operation) {
        try {
            golos::protocol::comment_payout_update_operation v1, v2;

            set_random_value(v1.author);
            set_random_value(v1.permlink);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_comment_benefactor_reward_operation) {
        try {
            golos::protocol::comment_benefactor_reward_operation v1, v2;

            set_random_value(v1.benefactor);
            set_random_value(v1.author);
            set_random_value(v1.permlink);
            set_random_value(v1.reward);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_authority) {
        try {
            golos::protocol::authority v1, v2;

            set_random_value(v1.weight_threshold);
            set_random_value(v1.account_auths);
            set_random_value(v1.key_auths);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_protocol_authority_classification) {
        try {
            golos::protocol::authority::classification v1, v2;

            set_random_value(v1.owner);
            set_random_value(v1.active);
            set_random_value(v1.key);
            set_random_value(v1.posting);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugin_tests_test_a_operation) {
        try {
            golos::plugin_tests::test_a_operation v1, v2;

            set_random_value(v1.account);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(golos_plugin_tests_test_b_operation) {
        try {
            golos::plugin_tests::test_b_operation v1, v2;

            set_random_value(v1.account);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(book) {
        try {
            book v1, v2;

            set_random_value(v1.name);
            set_random_value(v1.author);
            set_random_value(v1.pages);
            set_random_value(v1.prize);
            set_random_value(v1.deq);
            set_random_value(v1.auth);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(astr) {
        try {
            astr v1, v2;

            set_random_value(v1.str);
            set_random_value(v1.str1);
            set_random_value(v1.str2);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(bstr) {
        try {
            bstr v1, v2;

            set_random_value(v1.str);
            set_random_value(v1.str1);
            set_random_value(v1.str2);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(tx_signing_request) {
        try {
            tx_signing_request v1, v2;

            set_random_value(v1.tx);
            set_random_value(v1.wif);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(tx_signing_result) {
        try {
            tx_signing_result v1, v2;

            set_random_value(v1.digest);
            set_random_value(v1.sig_digest);
            set_random_value(v1.key);
            set_random_value(v1.sig);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(mystruct) {
        try {
            mystruct v1, v2;

            set_random_value(v1.alpha);
            set_random_value(v1.beta);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(signing_request) {
        try {
            signing_request v1, v2;

            set_random_value(v1.dig);
            set_random_value(v1.wif);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(signing_result) {
        try {
            signing_result v1, v2;

            set_random_value(v1.dig);
            set_random_value(v1.key);
            set_random_value(v1.sig);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_variant_type_id) {
        try {
            fc::variant::type_id v1, v2;

            set_random_value(v1.null_type);
            set_random_value(v1.int64_type);
            set_random_value(v1.uint64_type);
            set_random_value(v1.double_type);
            set_random_value(v1.bool_type);
            set_random_value(v1.string_type);
            set_random_value(v1.array_type);
            set_random_value(v1.object_type);
            set_random_value(v1.blob_type);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_blob) {
        try {
            fc::blob v1, v2;

            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_bloom_filter) {
        try {
            fc::bloom_filter v1, v2;

            set_random_value(v1.salt_);
            set_random_value(v1.bit_table_);
            set_random_value(v1.salt_count_);
            set_random_value(v1.table_size_);
            set_random_value(v1.raw_table_size_);
            set_random_value(v1.projected_element_count_);
            set_random_value(v1.inserted_element_count_);
            set_random_value(v1.random_seed_);
            set_random_value(v1.desired_false_positive_probability_);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_bloom_parameters_optimal_parameters_t) {
        try {
            fc::bloom_parameters::optimal_parameters_t v1, v2;

            set_random_value(v1.number_of_hashes);
            set_random_value(v1.table_size);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_bloom_parameters) {
        try {
            fc::bloom_parameters v1, v2;

            set_random_value(v1.minimum_size);
            set_random_value(v1.maximum_size);
            set_random_value(v1.minimum_number_of_hashes);
            set_random_value(v1.maximum_number_of_hashes);
            set_random_value(v1.projected_element_count);
            set_random_value(v1.false_positive_probability);
            set_random_value(v1.random_seed);
            set_random_value(v1.optimal_parameters);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_http_header) {
        try {
            fc::http::header v1, v2;

            set_random_value(v1.key);
            set_random_value(v1.val);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_uint128_t) {
        try {
            fc::uint128_t v1, v2;

            set_random_value(v1.hi);
            set_random_value(v1.lo);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_ecc_range_proof_info) {
        try {
            fc::ecc::range_proof_info v1, v2;

            set_random_value(v1.exp);
            set_random_value(v1.mantissa);
            set_random_value(v1.min_value);
            set_random_value(v1.max_value);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_equihash_proof) {
        try {
            fc::equihash::proof v1, v2;

            set_random_value(v1.n);
            set_random_value(v1.k);
            set_random_value(v1.seed);
            set_random_value(v1.inputs);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_rpc_brequest) {
        try {
            fc::rpc::brequest v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.method);
            set_random_value(v1.params);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_rpc_bresponse) {
        try {
            fc::rpc::bresponse v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.result);
            set_random_value(v1.error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_rpc_request) {
        try {
            fc::rpc::request v1, v2;

            set_random_value(v1.jsonrpc);
            set_random_value(v1.id);
            set_random_value(v1.method);
            set_random_value(v1.params);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_rpc_error_object) {
        try {
            fc::rpc::error_object v1, v2;

            set_random_value(v1.code);
            set_random_value(v1.message);
            set_random_value(v1.data);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_rpc_response) {
        try {
            fc::rpc::response v1, v2;

            set_random_value(v1.id);
            set_random_value(v1.result);
            set_random_value(v1.error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_json_console_appender_j_stream_type) {
        try {
            fc::json_console_appender::j_stream::type v1, v2;

            set_random_value(v1.std_out);
            set_random_value(v1.std_error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_json_console_appender_j_color_type) {
        try {
            fc::json_console_appender::j_color::type v1, v2;

            set_random_value(v1.red);
            set_random_value(v1.green);
            set_random_value(v1.brown);
            set_random_value(v1.blue);
            set_random_value(v1.magenta);
            set_random_value(v1.cyan);
            set_random_value(v1.white);
            set_random_value(v1.console_default);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_json_console_appender_j_level_color) {
        try {
            fc::json_console_appender::j_level_color v1, v2;

            set_random_value(v1.level);
            set_random_value(v1.color);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_json_console_appender_j_config) {
        try {
            fc::json_console_appender::j_config v1, v2;

            set_random_value(v1.format);
            set_random_value(v1.stream);
            set_random_value(v1.level_colors);
            set_random_value(v1.flush);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_appender_config) {
        try {
            fc::appender_config v1, v2;

            set_random_value(v1.name);
            set_random_value(v1.type);
            set_random_value(v1.args);
            set_random_value(v1.enabled);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_logger_config) {
        try {
            fc::logger_config v1, v2;

            set_random_value(v1.name);
            set_random_value(v1.parent);
            set_random_value(v1.level);
            set_random_value(v1.enabled);
            set_random_value(v1.additivity);
            set_random_value(v1.appenders);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_logging_config) {
        try {
            fc::logging_config v1, v2;

            set_random_value(v1.includes);
            set_random_value(v1.appenders);
            set_random_value(v1.loggers);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_file_appender_config) {
        try {
            fc::file_appender::config v1, v2;

            set_random_value(v1.format);
            set_random_value(v1.filename);
            set_random_value(v1.flush);
            set_random_value(v1.rotate);
            set_random_value(v1.rotation_interval);
            set_random_value(v1.rotation_limit);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_console_appender_stream_type) {
        try {
            fc::console_appender::stream::type v1, v2;

            set_random_value(v1.std_out);
            set_random_value(v1.std_error);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_console_appender_color_type) {
        try {
            fc::console_appender::color::type v1, v2;

            set_random_value(v1.red);
            set_random_value(v1.green);
            set_random_value(v1.brown);
            set_random_value(v1.blue);
            set_random_value(v1.magenta);
            set_random_value(v1.cyan);
            set_random_value(v1.white);
            set_random_value(v1.console_default);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_console_appender_level_color) {
        try {
            fc::console_appender::level_color v1, v2;

            set_random_value(v1.level);
            set_random_value(v1.color);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_console_appender_config) {
        try {
            fc::console_appender::config v1, v2;

            set_random_value(v1.format);
            set_random_value(v1.stream);
            set_random_value(v1.level_colors);
            set_random_value(v1.flush);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }

    BOOST_AUTO_TEST_CASE(fc_gelf_appender_config) {
        try {
            fc::gelf_appender::config v1, v2;

            set_random_value(v1.endpoint);
            set_random_value(v1.host);

            auto data = fc::raw::pack(v1);
            std::fstream stream_ex, stream_results;
            stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);
            fc::path file("logs");
            stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_ex.write(data.data(), data.size());
            stream_ex.close();
            
            fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);
            stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);
            stream_results.write(data.data(), data.size());
            stream_results.close();
            
            stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);
            fc::raw::unpack(stream_ex, v2);
            stream_ex.close();

        }
        FC_LOG_AND_RETHROW()
    }


BOOST_AUTO_TEST_SUITE_END()
#endif
