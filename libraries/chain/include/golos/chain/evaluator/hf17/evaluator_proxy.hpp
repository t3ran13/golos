#ifndef GOLOS_EVALUATOR_PROXY_HP
#define GOLOS_EVALUATOR_PROXY_HP

#include <golos/protocol/steem_operations.hpp>
#include <golos/chain/evaluator/hf17/steem_evaluator.hpp>

namespace golos {
    namespace chain {
        /*
        using proxy_account_create = evaluator_proxy<account_create_operation>;

        using proxy_account_update = evaluator_proxy<account_update_operation>;

        using proxy_transfer = evaluator_proxy<transfer_operation>;

        using proxy_transfer_to_vesting = evaluator_proxy<transfer_to_vesting_operation>;

        using proxy_witness_update = evaluator_proxy<witness_update_operation>;

        using proxy_account_witness_vote = evaluator_proxy<account_witness_vote_operation>;

        using proxy_account_witness_proxy = evaluator_proxy<account_witness_proxy_operation>;

        using proxy_withdraw_vesting = evaluator_proxy<withdraw_vesting_operation>;

        using proxy_set_withdraw_vesting_route= evaluator_proxy<set_withdraw_vesting_route_operation>;

        using proxy_comment = evaluator_proxy<comment_operation>;

        using proxy_comment_options = evaluator_proxy<comment_options_operation>;

        using proxy_delete_comment = evaluator_proxy<delete_comment_operation>;

        using proxy_vote = evaluator_proxy<vote_operation>;

        using proxy_custom = evaluator_proxy<custom_operation>;

        using proxy_custom_json = evaluator_proxy<custom_json_operation>;

        using proxy_custom_binary = evaluator_proxy<custom_binary_operation>;

        using proxy_pow = evaluator_proxy<pow_operation>;

        using proxy_pow2 = evaluator_proxy<pow2_operation>;

        using proxy_feed_publish = evaluator_proxy<feed_publish_operation>;

        using proxy_convert = evaluator_proxy<convert_operation>;

        using proxy_limit_order_create = evaluator_proxy<limit_order_create_operation>;

        using proxy_limit_order_cancel = evaluator_proxy<limit_order_cancel_operation>;

        using proxy_report_over_production = evaluator_proxy<report_over_production_operation>;

        using proxy_limit_order_create2 = evaluator_proxy<limit_order_create2_operation>;

        using proxy_escrow_transfer = evaluator_proxy<escrow_transfer_operation>;

        using proxy_escrow_approve = evaluator_proxy<escrow_approve_operation>;

        using proxy_escrow_dispute = evaluator_proxy<escrow_dispute_operation>;

        using proxy_escrow_release = evaluator_proxy<escrow_release_operation>;

        using proxy_challenge_authority = evaluator_proxy<challenge_authority_operation>;

        using proxy_prove_authority = evaluator_proxy<prove_authority_operation>;

        using proxy_request_account_recovery = evaluator_proxy<request_account_recovery_operation>;

        using proxy_recover_account = evaluator_proxy<recover_account_operation>;

        using proxy_change_recovery_account = evaluator_proxy<change_recovery_account_operation>;

        using proxy_transfer_to_savings = evaluator_proxy<transfer_to_savings_operation>;

        using proxy_transfer_from_savings = evaluator_proxy<transfer_from_savings_operation>;

        using proxy_cancel_transfer_from_savings = evaluator_proxy<cancel_transfer_from_savings_operation>;

        using proxy_decline_voting_rights = evaluator_proxy<decline_voting_rights_operation>;

        using proxy_reset_account = evaluator_proxy<reset_account_operation>;

        using proxy_set_reset_account = evaluator_proxy<set_reset_account_operation>;

*/

        PROXY_DEFINE_EVALUATOR(account_create)

        PROXY_DEFINE_EVALUATOR(account_update)

        PROXY_DEFINE_EVALUATOR(transfer)

        PROXY_DEFINE_EVALUATOR(transfer_to_vesting)

        PROXY_DEFINE_EVALUATOR(witness_update)

        PROXY_DEFINE_EVALUATOR(account_witness_vote)

        PROXY_DEFINE_EVALUATOR(account_witness_proxy)

        PROXY_DEFINE_EVALUATOR(withdraw_vesting)

        PROXY_DEFINE_EVALUATOR(set_withdraw_vesting_route)

        PROXY_DEFINE_EVALUATOR(comment)

        PROXY_DEFINE_EVALUATOR(comment_options)

        PROXY_DEFINE_EVALUATOR(delete_comment)

        PROXY_DEFINE_EVALUATOR(vote)

        PROXY_DEFINE_EVALUATOR(custom)

        PROXY_DEFINE_EVALUATOR(custom_json)

        PROXY_DEFINE_EVALUATOR(custom_binary)

        PROXY_DEFINE_EVALUATOR(pow)

        PROXY_DEFINE_EVALUATOR(pow2)

        PROXY_DEFINE_EVALUATOR(feed_publish)

        PROXY_DEFINE_EVALUATOR(convert)

        PROXY_DEFINE_EVALUATOR(limit_order_create)

        PROXY_DEFINE_EVALUATOR(limit_order_cancel)

        PROXY_DEFINE_EVALUATOR(report_over_production)

        PROXY_DEFINE_EVALUATOR(limit_order_create2)

        PROXY_DEFINE_EVALUATOR(escrow_transfer)

        PROXY_DEFINE_EVALUATOR(escrow_approve)

        PROXY_DEFINE_EVALUATOR(escrow_dispute)

        PROXY_DEFINE_EVALUATOR(escrow_release)

        PROXY_DEFINE_EVALUATOR(challenge_authority)

        PROXY_DEFINE_EVALUATOR(prove_authority)

        PROXY_DEFINE_EVALUATOR(request_account_recovery)

        PROXY_DEFINE_EVALUATOR(recover_account)

        PROXY_DEFINE_EVALUATOR(change_recovery_account)

        PROXY_DEFINE_EVALUATOR(transfer_to_savings)

        PROXY_DEFINE_EVALUATOR(transfer_from_savings)

        PROXY_DEFINE_EVALUATOR(cancel_transfer_from_savings)

        PROXY_DEFINE_EVALUATOR(decline_voting_rights)

        PROXY_DEFINE_EVALUATOR(reset_account)

        PROXY_DEFINE_EVALUATOR(set_reset_account)

    }
}

#endif //GOLOS_EVALUATOR_PROXY_HP
