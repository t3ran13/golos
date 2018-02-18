#pragma once
// Object which need voting
#include <golos/chain/witness_objects.hpp>
#include <golos/chain/comment_object.hpp>
// 
#include <golos/protocol/authority.hpp>
#include <golos/protocol/steem_operations.hpp>
#include <golos/chain/steem_object_types.hpp>
// 
// This is the generalization of vote_objects which uses policy-based design
// 
namespace golos {
namespace chain {

template<typename VotingPolicy, uint32_t shift = 1>
class vote_interface : public object<(VotingPolicy::type_id << 8) + shift, vote_interface<VotingPolicy, shift> > {
public:
    template<typename Constructor, typename Allocator>
    vote_interface(Constructor &&c, allocator <Allocator> a) {
        c(*this);
    }

    id_type id;
    account_id_type voter;
};

template<>
class vote_object <comment_object> : public vote_interface<comment_object> {
    comment_id_type comment;

    uint64_t weight = 0; ///< defines the score this vote receives, used by vote payout calc. 0 if a negative vote or changed votes.
    int64_t rshares = 0; ///< The number of rshares this vote is responsible for
    int16_t vote_percent = 0; ///< The percent weight of the vote
    time_point_sec last_update; ///< The time of the last update of the vote
    int8_t num_changes = 0;
}

template<>
class vote_object <witness_object> : public vote_interface<witness_object> {
    witness_id_type witness;
    // account_id_type account;  was -> account_id_type voter;
}

struct by_account_witness;
struct by_witness_account;	

typedef multi_index_container <
vote_object<witness_object>,
indexed_by<
        ordered_unique < tag <
        by_id>, member<vote_object<witness_object>, witness_vote_id_type, &vote_object<witness_object>::id>>,
ordered_unique <tag<by_account_witness>,
composite_key<vote_object<witness_object>,
        member <
        vote_object<witness_object>, account_id_type, &vote_object<witness_object>::voter>,
member<vote_object<witness_object>, witness_id_type, &vote_object<witness_object>::witness>
>,
composite_key_compare <std::less<account_id_type>, std::less<witness_id_type>>
>,
ordered_unique <tag<by_witness_account>,
composite_key<vote_object<witness_object>,
        member <
        vote_object<witness_object>, witness_id_type, &vote_object<witness_object>::witness>,
member<vote_object<witness_object>, account_id_type, &vote_object<witness_object>::voter>
>,
composite_key_compare <std::less<witness_id_type>, std::less<account_id_type>>
>
>, // indexed_by
allocator <vote_object<witness_object>>
>
witness_vote_index;


struct by_comment_voter;
struct by_voter_comment;
struct by_comment_weight_voter;
struct by_voter_last_update;
typedef multi_index_container <
vote_object<comment_object>,
indexed_by<
        ordered_unique < tag <
        by_id>, member<vote_object<comment_object>, comment_vote_id_type, &vote_object<comment_object>::id>>,
ordered_unique <tag<by_comment_voter>,
composite_key<vote_object<comment_object>,
        member <
        vote_object<comment_object>, comment_id_type, &vote_object<comment_object>::comment>,
member<vote_object<comment_object>, account_id_type, &vote_object<comment_object>::voter>
>
>,
ordered_unique <tag<by_voter_comment>,
composite_key<vote_object<comment_object>,
        member <
        vote_object<comment_object>, account_id_type, &vote_object<comment_object>::voter>,
member<vote_object<comment_object>, comment_id_type, &vote_object<comment_object>::comment>
>
>,
ordered_unique <tag<by_voter_last_update>,
composite_key<vote_object<comment_object>,
        member <
        vote_object<comment_object>, account_id_type, &vote_object<comment_object>::voter>,
member<vote_object<comment_object>, time_point_sec, &vote_object<comment_object>::last_update>,
member<vote_object<comment_object>, comment_id_type, &vote_object<comment_object>::comment>
>,
composite_key_compare <std::less<account_id_type>, std::greater<time_point_sec>, std::less<comment_id_type>>
>,
ordered_unique <tag<by_comment_weight_voter>,
composite_key<vote_object<comment_object>,
        member <
        vote_object<comment_object>, comment_id_type, &vote_object<comment_object>::comment>,
member<vote_object<comment_object>, uint64_t, &vote_object<comment_object>::weight>,
member<vote_object<comment_object>, account_id_type, &vote_object<comment_object>::voter>
>,
composite_key_compare <std::less<comment_id_type>, std::greater<uint64_t>, std::less<account_id_type>>
>
>,
allocator <vote_object<comment_object>>
>
comment_vote_index;

} } //golos::chain


// TODO: FIGURE OUT HOW TO CORRECTLY REFLECT VOTE_OBJECTS
FC_REFLECT( (golos::chain::vote_interface), (id)(voter))

FC_REFLECT_DERIVED( (golos::chain::vote_object <comment_object>), 
    	(comment)(weight)(rshares)(vote_percent)(last_update)(num_changes)
)

FC_REFLECT((golos::chain::vote_object <witness_object>), (witness))
