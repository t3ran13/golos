#pragma once

#include <golos/protocol/authority.hpp>
#include <golos/protocol/steem_operations.hpp>

#include <golos/chain/steem_object_types.hpp>
#include <golos/chain/witness_objects.hpp>

#include <boost/multi_index/composite_key.hpp>


namespace golos {
    namespace chain {

        namespace bip = boost::interprocess;

        struct strcmp_less {
            bool operator()(const shared_string &a, const shared_string &b) const {
                return less(a.c_str(), b.c_str());
            }

            bool operator()(const shared_string &a, const string &b) const {
                return less(a.c_str(), b.c_str());
            }

            bool operator()(const string &a, const shared_string &b) const {
                return less(a.c_str(), b.c_str());
            }

        private:
            inline bool less(const char *a, const char *b) const {
                return std::strcmp(a, b) < 0;
            }
        };

        enum comment_mode {
            not_set,
            first_payout,
            second_payout,
            archived
        };


        class comment_object
                : public object<comment_object_type, comment_object> {
        public:
            comment_object() = delete;

            template<typename Constructor, typename Allocator>
            comment_object(Constructor &&c, allocator <Allocator> a)
                    :parent_permlink(a), permlink(a), beneficiaries(a) {
                c(*this);
            }

            id_type id;

            account_name_type parent_author;
            shared_string parent_permlink;
            account_name_type author;
            shared_string permlink;

            time_point_sec created;
            time_point_sec last_payout;

            uint16_t depth = 0; ///< used to track max nested depth
            uint32_t children = 0; ///< used to track the total number of children, grandchildren, etc...

            /**
             *  Used to track the total rshares^2 of all children, this is used for indexing purposes. A discussion
             *  that has a nested comment of high value should promote the entire discussion so that the comment can
             *  be reviewed.
             */
            fc::uint128_t children_rshares2;

            /// index on pending_payout for "things happning now... needs moderation"
            /// TRENDING = UNCLAIMED + PENDING
            share_type net_rshares; // reward is proportional to rshares^2, this is the sum of all votes (positive and negative)
            share_type abs_rshares; /// this is used to track the total abs(weight) of votes for the purpose of calculating cashout_time
            share_type vote_rshares; /// Total positive rshares from all votes. Used to calculate delta weights. Needed to handle vote changing and removal.

            share_type children_abs_rshares; /// this is used to calculate cashout time of a discussion.
            time_point_sec cashout_time; /// 24 hours from the weighted average of vote time
            time_point_sec max_cashout_time;
            uint64_t total_vote_weight = 0; /// the total weight of voting rewards, used to calculate pro-rata share of curation payouts

            uint16_t reward_weight = 0;

            int32_t net_votes = 0;

            id_type root_comment;

            uint64_t auction_window_weight = 0;

            comment_mode mode = first_payout;

            protocol::auction_window_reward_destination_type auction_window_reward_destination = protocol::destination_not_set;
            uint32_t auction_window_size;

            asset max_accepted_payout = asset(1000000000, SBD_SYMBOL);       /// SBD value of the maximum payout this post will receive
            uint16_t percent_steem_dollars = STEEMIT_100_PERCENT; /// the percent of Golos Dollars to key, unkept amounts will be received as Golos Power
            bool allow_replies = true;      /// allows a post to disable replies.
            bool allow_votes = true;      /// allows a post to receive votes;
            bool allow_curation_rewards = true;

            bip::vector <protocol::beneficiary_route_type, allocator<protocol::beneficiary_route_type>> beneficiaries;
        };


        /**
         * This index maintains the set of voter/comment pairs that have been used, voters cannot
         * vote on the same comment more than once per payout period.
         */
        class comment_vote_object
                : public object<comment_vote_object_type, comment_vote_object> {
        public:
            template<typename Constructor, typename Allocator>
            comment_vote_object(Constructor &&c, allocator <Allocator> a) {
                c(*this);
            }

            id_type id;

            account_id_type voter;
            comment_id_type comment;
            uint64_t weight = 0; ///< defines the score this vote receives, used by vote payout calc. 0 if a negative vote or changed votes.
            int64_t rshares = 0; ///< The number of rshares this vote is responsible for
            int16_t vote_percent = 0; ///< The percent weight of the vote
            time_point_sec last_update; ///< The time of the last update of the vote
            int8_t num_changes = 0; ///< Count of vote changes (while consensus). If = -1 then related post is archived & vote no more needed for consensus
        };

        struct by_comment_voter;
        struct by_voter_comment;
        struct by_comment_weight_voter;
        struct by_vote_last_update;
        using comment_vote_index = multi_index_container<
            comment_vote_object,
            indexed_by<
                ordered_unique<tag<by_id>,
                    member<comment_vote_object, comment_vote_id_type, &comment_vote_object::id>>,
                ordered_unique<tag<by_comment_voter>,
                    composite_key<comment_vote_object,
                        member<comment_vote_object, comment_id_type, &comment_vote_object::comment>,
                        member<comment_vote_object, account_id_type, &comment_vote_object::voter>
                    >
                >,
                ordered_unique<tag<by_voter_comment>,
                    composite_key<comment_vote_object,
                        member<comment_vote_object, account_id_type, &comment_vote_object::voter>,
                        member<comment_vote_object, comment_id_type, &comment_vote_object::comment>
                    >
                >,
                ordered_non_unique<tag<by_vote_last_update>,
                    composite_key<comment_vote_object,
                        member<comment_vote_object, int8_t, &comment_vote_object::num_changes>,
                        member<comment_vote_object, time_point_sec, &comment_vote_object::last_update>
                    >
                >,
                ordered_unique<tag<by_comment_weight_voter>,
                    composite_key<comment_vote_object,
                        member<comment_vote_object, comment_id_type, &comment_vote_object::comment>,
                        member<comment_vote_object, uint64_t, &comment_vote_object::weight>,
                        member<comment_vote_object, account_id_type, &comment_vote_object::voter>
                    >,
                    composite_key_compare<std::less<comment_id_type>, std::greater<uint64_t>, std::less<account_id_type>>
                >
            >,
            allocator<comment_vote_object>
        >;


        struct by_cashout_time; /// cashout_time
        struct by_permlink; /// author, perm
        struct by_root;
        struct by_parent;

        /**
         * @ingroup object_index
         */
        typedef multi_index_container <

            comment_object,
            indexed_by<
                ordered_unique <
                    tag <by_id>, member<comment_object, comment_id_type, &comment_object::id>>,
                ordered_unique <
                    tag<by_cashout_time>,
                        composite_key<comment_object,
                        member <comment_object, time_point_sec, &comment_object::cashout_time>,
                        member<comment_object, comment_id_type, &comment_object::id>>>,
                ordered_unique <
                    tag<by_permlink>, /// used by consensus to find posts referenced in ops
                        composite_key<comment_object,
                        member <comment_object, account_name_type, &comment_object::author>,
                        member<comment_object, shared_string, &comment_object::permlink>>,
                    composite_key_compare <std::less<account_name_type>, strcmp_less>>,
                ordered_unique <
                    tag<by_root>,
                        composite_key<comment_object,
                        member <comment_object, comment_id_type, &comment_object::root_comment>,
                        member<comment_object, comment_id_type, &comment_object::id>>>,
                ordered_unique <
                    tag<by_parent>, /// used by consensus to find posts referenced in ops
                        composite_key<comment_object,
                        member <comment_object, account_name_type, &comment_object::parent_author>,
                        member<comment_object, shared_string, &comment_object::parent_permlink>,
                        member<comment_object, comment_id_type, &comment_object::id>>,
                    composite_key_compare <std::less<account_name_type>, strcmp_less, std::less<comment_id_type>> >
            >,
            allocator <comment_object>
        >
        comment_index;

    }
} // golos::chain

FC_REFLECT_ENUM(golos::chain::comment_mode, (not_set)(first_payout)(second_payout)(archived))

CHAINBASE_SET_INDEX_TYPE(golos::chain::comment_object, golos::chain::comment_index)

CHAINBASE_SET_INDEX_TYPE(golos::chain::comment_vote_object, golos::chain::comment_vote_index)

