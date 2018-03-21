
golos/plugins/test_api/include/golos/plugins/test_api/test_api_plugin.hpp
FC_REFLECT((golos::plugins::test_api::test_api_a_t), (value))
FC_REFLECT((golos::plugins::test_api::test_api_b_t), (value))

golos/plugins/private_message/include/golos/plugins/private_message/private_message_objects.hpp
FC_REFLECT((golos::plugins::private_message::private_message_operation),
           (from)(to)(from_memo_key)(to_memo_key)(sent_time)(checksum)(encrypted_message))
FC_REFLECT_TYPENAME((golos::plugins::private_message::private_message_plugin_operation))

golos/plugins/private_message/include/golos/plugins/private_message/private_message_plugin.hpp
FC_REFLECT((golos::plugins::private_message::message_body), (thread_start)(subject)(body)(json_meta)(cc))
FC_REFLECT((golos::plugins::private_message::message_object), (id)(from)(to)(from_memo_key)(to_memo_key)(sent_time)(receive_time)(checksum)(encrypted_message))
FC_REFLECT((golos::plugins::private_message::message_api_obj), (id)(from)(to)(from_memo_key)(to_memo_key)(sent_time)(receive_time)(checksum)(encrypted_message))
FC_REFLECT_DERIVED((golos::plugins::private_message::extended_message_object), ((golos::plugins::private_message::message_api_obj)), (message))

golos/plugins/blockchain_statistics/include/golos/plugins/blockchain_statistics/bucket_object.hpp
FC_REFLECT( (golos::plugins::blockchain_statistics::bucket_object),
    (id)
    (open)
    (seconds)
    (blocks)
    (bandwidth)
    (operations)
    (transactions)
    (transfers)
    (steem_transferred)
    (sbd_transferred)
    (sbd_paid_as_interest)
    (paid_accounts_created)
    (mined_accounts_created)
    (root_comments)
    (root_comment_edits)
    (root_comments_deleted)
    (replies)
    (reply_edits)
    (replies_deleted)
    (new_root_votes)
    (changed_root_votes)
    (new_reply_votes)
    (changed_reply_votes)
    (payouts)
    (sbd_paid_to_authors)
    (vests_paid_to_authors)
    (vests_paid_to_curators)
    (liquidity_rewards_paid)
    (transfers_to_vesting)
    (steem_vested)
    (new_vesting_withdrawal_requests)
    (modified_vesting_withdrawal_requests)
    (vesting_withdraw_rate_delta)
    (vesting_withdrawals_processed)
    (finished_vesting_withdrawals)
    (vests_withdrawn)
    (vests_transferred)
    (sbd_conversion_requests_created)
    (sbd_to_be_converted)
    (sbd_conversion_requests_filled)
    (steem_converted)
    (limit_orders_created)
    (limit_orders_filled)
    (limit_orders_cancelled)
    (total_pow)
    (estimated_hashpower)
)

golos/plugins/social_network/include/golos/plugins/social_network/api_object/tag_api_object.hpp
FC_REFLECT((golos::plugins::social_network::tag_api_object),
           (name)(total_children_rshares2)(total_payouts)(net_votes)(top_posts)(comments))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/category_api_object.hpp
FC_REFLECT((golos::plugins::social_network::category_api_object),
           (id)(name)(abs_rshares)(total_payouts)(discussions)(last_update))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/vote_state.hpp
FC_REFLECT((golos::plugins::social_network::vote_state), (voter)(weight)(rshares)(percent)(reputation)(time))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/account_vote.hpp
FC_REFLECT((golos::plugins::social_network::account_vote), (authorperm)(weight)(rshares)(percent)(time))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/discussion.hpp
FC_REFLECT_DERIVED((golos::plugins::social_network::discussion), ((golos::plugins::social_network::comment_api_object)), (url)(root_title)(pending_payout_value)(total_pending_payout_value)(active_votes)(replies)(author_reputation)(promoted)(body_length)(reblogged_by)(first_reblogged_by)(first_reblogged_on))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/discussion_index.hpp
FC_REFLECT((golos::plugins::social_network::discussion_index), (category)(trending)(trending30)(updated)(created)(responses)(active)(votes)(maturing)(best)(hot)(promoted)(cashout))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/tag_index.hpp
FC_REFLECT((golos::plugins::social_network::tag_index), (trending))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/comment_api_object.hpp
FC_REFLECT((golos::plugins::social_network::comment_api_object),
           (id)(author)(permlink)(category)(parent_author)(parent_permlink)(title)(body)(json_metadata)(last_update)(
                   created)(active)(last_payout)(depth)(children)(children_rshares2)(net_rshares)(abs_rshares)(
                   vote_rshares)(children_abs_rshares)(cashout_time)(max_cashout_time)(total_vote_weight)(
                   reward_weight)(total_payout_value)(curator_payout_value)(author_rewards)(net_votes)(root_comment)(
                   max_accepted_payout)(percent_steem_dollars)(allow_replies)(allow_votes)(
                   allow_curation_rewards)(beneficiaries))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/discussion_query.hpp
FC_REFLECT((golos::plugins::social_network::discussion_query),
           (select_tags)(filter_tags)(select_authors)(truncate_body)(start_author)(start_permlink)(parent_author)(
                   parent_permlink)(limit)(select_languages)(filter_languages))

golos/plugins/social_network/include/golos/plugins/social_network/api_object/category_index.hpp
FC_REFLECT((golos::plugins::social_network::category_index), (active)(recent)(best))

golos/plugins/social_network/include/golos/plugins/social_network/languages/language_object.hpp
FC_REFLECT((golos::plugins::social_network::languages::comment_metadata), (language))
FC_REFLECT((golos::plugins::social_network::languages::language_object),
           (id)(name)(created)(active)(cashout)(net_rshares)(net_votes)(hot)(trending)(promoted_balance)(children)(
                   children_rshares2)(author)(parent)(comment))
FC_REFLECT((golos::plugins::social_network::languages::language_stats_object),
           (id)(language)(total_children_rshares2)(total_payout)(net_votes)(top_posts)(comments))
FC_REFLECT((golos::plugins::social_network::languages::peer_stats_object),
           (id)(voter)(peer)(direct_positive_votes)(direct_votes)(indirect_positive_votes)(indirect_votes)(rank))
FC_REFLECT((golos::plugins::social_network::languages::author_language_stats_object),
           (id)(author)(language)(total_posts)(total_rewards))

golos/plugins/social_network/include/golos/plugins/social_network/social_network.hpp
FC_REFLECT((golos::plugins::social_network::get_languages_r), (languages))

golos/plugins/social_network/include/golos/plugins/social_network/tag/tags_object.hpp
FC_REFLECT((golos::plugins::social_network::tags::tag_object), (id)(name)(created)(active)(cashout)(net_rshares)(net_votes)(hot)(promoted_balance)(children)(children_rshares2)(mode)(author)(parent)(comment))
FC_REFLECT((golos::plugins::social_network::tags::tag_object), (id)(name)(created)(active)(cashout)(net_rshares)(net_votes)(hot)(promoted_balance)(children)(children_rshares2)(author)(parent)(comment))
FC_REFLECT((golos::plugins::social_network::tags::tag_stats_object), (id)(tag)(total_children_rshares2)(total_payout)(net_votes)(top_posts)(comments))
FC_REFLECT((golos::plugins::social_network::tags::peer_stats_object), (id)(voter)(peer)(direct_positive_votes)(direct_votes)(indirect_positive_votes)(indirect_votes)(rank))
FC_REFLECT((golos::plugins::social_network::tags::comment_metadata), (tags))
FC_REFLECT((golos::plugins::social_network::tags::author_tag_stats_object), (id)(author)(tag)(total_posts)(total_rewards))

golos/plugins/database_api/include/golos/plugins/database_api/plugin.hpp
FC_REFLECT((golos::plugins::database_api::scheduled_hardfork), (hf_version)(live_time))
FC_REFLECT((golos::plugins::database_api::withdraw_route), (from_account)(to_account)(percent)(auto_vest))
FC_REFLECT_ENUM(golos::plugins::database_api::withdraw_route_type, (incoming)(outgoing)(all))
FC_REFLECT((golos::plugins::database_api::tag_count_object), (tag)(count))
FC_REFLECT((golos::plugins::database_api::get_tags_used_by_author), (tags))
FC_REFLECT((golos::plugins::database_api::signed_block_api_object), (block_id)(signing_key)(transaction_ids))
FC_REFLECT((golos::plugins::database_api::operation_api_object),
           (trx_id)(block)(trx_in_block)(op_in_trx)(virtual_op)(timestamp)(op))

golos/plugins/database_api/include/golos/plugins/database_api/applied_operation.hpp
FC_REFLECT((golos::plugins::database_api::applied_operation), (trx_id)(block)(trx_in_block)(op_in_trx)(virtual_op)(timestamp)(op))

golos/plugins/database_api/include/golos/plugins/database_api/state.hpp
FC_REFLECT_DERIVED((golos::plugins::database_api::extended_account),
                   ((golos::plugins::database_api::account_api_object)),
                   (vesting_balance)(reputation)
                           (transfer_history)(market_history)(post_history)(vote_history)(other_history)(witness_votes)(tags_usage)(guest_bloggers)(open_orders)(comments)(feed)(blog)(recent_replies)(blog_category)(recommended))
FC_REFLECT((golos::plugins::database_api::state), (current_route)(props)(category_idx)(tag_idx)(categories)(tags)(content)(accounts)(pow_queue)(witnesses)(discussion_idx)(witness_schedule)(feed_price)(error)(market_data))
FC_REFLECT_DERIVED((golos::plugins::database_api::extended_limit_order), ((golos::plugins::database_api::limit_order_api_object)), (real_price)(rewarded))
FC_REFLECT((golos::plugins::database_api::order_history_item), (time)(type)(sbd_quantity)(steem_quantity)(real_price))
FC_REFLECT((golos::plugins::database_api::market), (bids)(asks)(history)(price_history)(available_candlesticks)(available_zoom)(current_candlestick)(current_zoom))
FC_REFLECT((golos::plugins::database_api::candle_stick), (open_time)(period)(high)(low)(open)(close)(steem_volume)(dollar_volume))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/witness_api_object.hpp
FC_REFLECT((golos::plugins::database_api::witness_api_object),
           (id)(owner)(created)(url)(votes)(virtual_last_update)(virtual_position)(virtual_scheduled_time)(
                   total_missed)(last_aslot)(last_confirmed_block_num)(pow_worker)(signing_key)(props)(
                   sbd_exchange_rate)(last_sbd_exchange_update)(last_work)(running_version)(hardfork_version_vote)(
                   hardfork_time_vote))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/account_recovery_request_api_object.hpp
FC_REFLECT((golos::plugins::database_api::account_recovery_request_api_object),
           (id)(account_to_recover)(new_owner_authority)(expires))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/feed_history_api_object.hpp
FC_REFLECT((golos::plugins::database_api::feed_history_api_object), (id)(current_median_history)(price_history))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/owner_authority_history_api_object.hpp
FC_REFLECT((golos::plugins::database_api::owner_authority_history_api_object),
           (id)(account)(previous_owner_authority)(last_valid_time))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/account_api_object.hpp
FC_REFLECT((golos::plugins::database_api::account_api_object),
           (id)(name)(owner)(active)(posting)(memo_key)(json_metadata)(proxy)(last_owner_update)(last_account_update)(
                   created)(mined)(owner_challenged)(active_challenged)(last_owner_proved)(last_active_proved)(
                   recovery_account)(last_account_recovery)(reset_account)(comment_count)(lifetime_vote_count)(
                   post_count)(can_vote)(voting_power)(last_vote_time)(balance)(savings_balance)(sbd_balance)(
                   sbd_seconds)(sbd_seconds_last_update)(sbd_last_interest_payment)(savings_sbd_balance)(
                   savings_sbd_seconds)(savings_sbd_seconds_last_update)(savings_sbd_last_interest_payment)(
                   savings_withdraw_requests)(vesting_shares)(delegated_vesting_shares)(received_vesting_shares)(
                   vesting_withdraw_rate)(next_vesting_withdrawal)(withdrawn)(to_withdraw)(withdraw_routes)(
                   curation_rewards)(posting_rewards)(proxied_vsf_votes)(witnesses_voted_for)(average_bandwidth)(
                   lifetime_bandwidth)(last_bandwidth_update)(average_market_bandwidth)(last_market_bandwidth_update)(
                   last_post)(last_root_post)(post_bandwidth)(new_average_bandwidth)(new_average_market_bandwidth))

golos/plugins/database_api/include/golos/plugins/database_api/api_objects/savings_withdraw_api_object.hpp
FC_REFLECT((golos::plugins::database_api::savings_withdraw_api_object),
           (id)(from)(to)(memo)(request_id)(amount)(complete))

golos/plugins/raw_block/include/golos/plugins/raw_block/plugin.hpp
FC_REFLECT((golos::plugins::raw_block::get_raw_block_r),
    (block_id)(previous)(timestamp)(raw_block)
)

golos/plugins/follow/include/golos/plugins/follow/follow_objects.hpp
FC_REFLECT((golos::plugins::follow::follow_object), (id)(follower)(following)(what))
FC_REFLECT((golos::plugins::follow::feed_object),
           (id)(account)(first_reblogged_by)(first_reblogged_on)(reblogged_by)(comment)(reblogs)(account_feed_id))
FC_REFLECT((golos::plugins::follow::blog_object), (id)(account)(comment)(reblogged_on)(blog_feed_id))
FC_REFLECT((golos::plugins::follow::reputation_object), (id)(account)(reputation))
FC_REFLECT((golos::plugins::follow::follow_count_object), (id)(account)(follower_count)(following_count))
FC_REFLECT((golos::plugins::follow::blog_author_stats_object), (id)(blogger)(guest)(count))

golos/plugins/follow/include/golos/plugins/follow/follow_operations.hpp
FC_REFLECT((golos::plugins::follow::follow_operation), (follower)(following)(what))
FC_REFLECT((golos::plugins::follow::reblog_operation), (account)(author)(permlink))
FC_REFLECT_TYPENAME((golos::plugins::follow::follow_plugin_operation))

golos/plugins/follow/include/golos/plugins/follow/follow_forward.hpp
FC_REFLECT_ENUM(golos::plugins::follow::follow_type, (undefined)(blog)(ignore))

golos/plugins/follow/include/golos/plugins/follow/follow_api_object.hpp
FC_REFLECT((golos::plugins::follow::feed_entry), (author)(permlink)(reblog_by)(reblog_on)(entry_id))
FC_REFLECT((golos::plugins::follow::comment_feed_entry), (comment)(reblog_by)(reblog_on)(entry_id))
FC_REFLECT((golos::plugins::follow::blog_entry), (author)(permlink)(blog)(reblog_on)(entry_id))
FC_REFLECT((golos::plugins::follow::comment_blog_entry), (comment)(blog)(reblog_on)(entry_id))
FC_REFLECT((golos::plugins::follow::account_reputation), (account)(reputation))
FC_REFLECT((golos::plugins::follow::follow_api_object), (follower)(following)(what))
FC_REFLECT((golos::plugins::follow::reblog_count), (author)(count))
FC_REFLECT((golos::plugins::follow::follow_count_api_obj), (account)(follower_count)(following_count)(limit))

golos/plugins/block_info/include/golos/plugins/block_info/block_info.hpp
FC_REFLECT( (golos::plugins::block_info::block_info),
    (block_id)
    (block_size)
    (average_block_size)
    (aslot)
    (last_irreversible_block_num)
    (num_pow_witnesses)
)
FC_REFLECT( (golos::plugins::block_info::block_with_info),
    (block)
    (info)
)
FC_REFLECT ((golos::plugins::block_info::test_str),
    (lol)
)

golos/plugins/network_broadcast_api/include/golos/plugins/network_broadcast_api/network_broadcast_api_plugin.hpp
FC_REFLECT((golos::plugins::network_broadcast_api::broadcast_transaction_synchronous_t),
           (id)(block_num)(trx_num)(expired))

golos/plugins/account_by_key/include/golos/plugins/account_by_key/account_by_key_objects.hpp
FC_REFLECT((golos::plugins::account_by_key::key_lookup_object), (id)(key)(account))

golos/plugins/market_history/include/golos/plugins/market_history/market_history_objects.hpp
FC_REFLECT((golos::plugins::market_history::market_ticker),
           (latest)(lowest_ask)(highest_bid)(percent_change)(steem_volume)(sbd_volume))
FC_REFLECT((golos::plugins::market_history::market_volume),
           (steem_volume)(sbd_volume))
FC_REFLECT((golos::plugins::market_history::order),
           (price)(steem)(sbd))
FC_REFLECT((golos::plugins::market_history::order_book),
           (bids)(asks))
FC_REFLECT((golos::plugins::market_history::market_trade),
           (date)(current_pays)(open_pays))
FC_REFLECT_DERIVED((golos::plugins::market_history::limit_order),((golos::plugins::market_history::limit_order_api_object)) ,(real_price)(rewarded))
FC_REFLECT((golos::plugins::market_history::bucket_object),
           (id)
                   (open)(seconds)
                   (high_steem)(high_sbd)
                   (low_steem)(low_sbd)
                   (open_steem)(open_sbd)
                   (close_steem)(close_sbd)
                   (steem_volume)(sbd_volume))
FC_REFLECT((golos::plugins::market_history::order_history_object),(id)(time)(op))

golos/plugins/json_rpc/include/golos/plugins/json_rpc/plugin.hpp
FC_REFLECT((golos::plugins::json_rpc::api_method_signature), (args)(ret))

golos/plugins/json_rpc/include/golos/plugins/json_rpc/utility.hpp
FC_REFLECT((golos::plugins::json_rpc::void_type),)

golos/plugins/json_rpc/plugin.cpp
FC_REFLECT((golos::plugins::json_rpc::json_rpc_error), (code)(message)(data))
FC_REFLECT((golos::plugins::json_rpc::json_rpc_response), (jsonrpc)(result)(error)(id))

golos/libraries/wallet/include/golos/wallet/wallet.hpp
FC_REFLECT( (golos::wallet::wallet_data),
            (cipher_keys)
                    (ws_server)
                    (ws_user)
                    (ws_password)
)
FC_REFLECT( (golos::wallet::brain_key_info), (brain_priv_key)(wif_priv_key) (pub_key))
FC_REFLECT( (golos::wallet::plain_keys), (checksum)(keys) )
FC_REFLECT_ENUM( golos::wallet::authority_type, (owner)(active)(posting) )
FC_REFLECT( (golos::wallet::memo_data), (from)(to)(nonce)(check)(encrypted) )

golos/libraries/network/include/golos/network/peer_connection.hpp
FC_REFLECT_ENUM(golos::network::peer_connection::our_connection_state, (disconnected)
        (just_connected)
        (connection_accepted)
        (connection_rejected))
FC_REFLECT_ENUM(golos::network::peer_connection::their_connection_state, (disconnected)
        (just_connected)
        (connection_accepted)
        (connection_rejected))
FC_REFLECT_ENUM(golos::network::peer_connection::connection_negotiation_status, (disconnected)
        (connecting)
        (connected)
        (accepting)
        (accepted)
        (hello_sent)
        (peer_connection_accepted)
        (peer_connection_rejected)
        (negotiation_complete)
        (closing)
        (closed))
FC_REFLECT((golos::network::peer_connection::timestamped_item_id), (item)(timestamp))

golos/libraries/network/include/golos/network/peer_database.hpp
FC_REFLECT_ENUM(golos::network::potential_peer_last_connection_disposition, (never_attempted_to_connect)(last_connection_failed)(last_connection_rejected)(last_connection_handshaking_failed)(last_connection_succeeded))
FC_REFLECT((golos::network::potential_peer_record), (endpoint)(last_seen_time)(last_connection_disposition)(last_connection_attempt_time)(number_of_successful_connection_attempts)(number_of_failed_connection_attempts)(last_error))

golos/libraries/network/include/golos/network/core_messages.hpp
FC_REFLECT_ENUM(golos::network::core_message_type_enum,
        (trx_message_type)
                (block_message_type)
                (core_message_type_first)
                (item_ids_inventory_message_type)
                (blockchain_item_ids_inventory_message_type)
                (fetch_blockchain_item_ids_message_type)
                (fetch_items_message_type)
                (item_not_available_message_type)
                (hello_message_type)
                (connection_accepted_message_type)
                (connection_rejected_message_type)
                (address_request_message_type)
                (address_message_type)
                (closing_connection_message_type)
                (current_time_request_message_type)
                (current_time_reply_message_type)
                (check_firewall_message_type)
                (check_firewall_reply_message_type)
                (get_current_connections_request_message_type)
                (get_current_connections_reply_message_type)
                (core_message_type_last))
FC_REFLECT((golos::network::trx_message), (trx))
FC_REFLECT((golos::network::block_message), (block)(block_id))
FC_REFLECT((golos::network::item_id), (item_type)
        (item_hash))
FC_REFLECT((golos::network::item_ids_inventory_message), (item_type)
        (item_hashes_available))
FC_REFLECT((golos::network::blockchain_item_ids_inventory_message), (total_remaining_item_count)
        (item_type)
        (item_hashes_available))
FC_REFLECT((golos::network::fetch_blockchain_item_ids_message), (item_type)
        (blockchain_synopsis))
FC_REFLECT((golos::network::fetch_items_message), (item_type)
        (items_to_fetch))
FC_REFLECT((golos::network::item_not_available_message), (requested_item))
FC_REFLECT((golos::network::hello_message), (user_agent)
        (core_protocol_version)
        (inbound_address)
        (inbound_port)
        (outbound_port)
        (node_public_key)
        (signed_shared_secret)
        (user_data))
FC_REFLECT_EMPTY((golos::network::connection_accepted_message))
FC_REFLECT_ENUM(golos::network::rejection_reason_code, (unspecified)
        (different_chain)
        (already_connected)
        (connected_to_self)
        (not_accepting_connections)
        (blocked)
        (invalid_hello_message)
        (client_too_old))
FC_REFLECT((golos::network::connection_rejected_message), (user_agent)
        (core_protocol_version)
        (remote_endpoint)
        (reason_code)
        (reason_string))
FC_REFLECT_EMPTY((golos::network::address_request_message))
FC_REFLECT((golos::network::address_info), (remote_endpoint)
        (last_seen_time)
        (latency)
        (node_id)
        (direction)
        (firewalled))
FC_REFLECT((golos::network::address_message), (addresses))
FC_REFLECT((golos::network::closing_connection_message), (reason_for_closing)
        (closing_due_to_error)
        (error))
FC_REFLECT_ENUM(golos::network::peer_connection_direction, (unknown)
        (inbound)
        (outbound))
FC_REFLECT_ENUM(golos::network::firewalled_state, (unknown)
        (firewalled)
        (not_firewalled))
FC_REFLECT((golos::network::current_time_request_message), (request_sent_time))
FC_REFLECT((golos::network::current_time_reply_message), (request_sent_time)
        (request_received_time)
        (reply_transmitted_time))
FC_REFLECT_ENUM(golos::network::firewall_check_result, (unable_to_check)
        (unable_to_connect)
        (connection_successful))
FC_REFLECT((golos::network::check_firewall_message), (node_id)(endpoint_to_check))
FC_REFLECT((golos::network::check_firewall_reply_message), (node_id)(endpoint_checked)(result))
FC_REFLECT_EMPTY((golos::network::get_current_connections_request_message))
FC_REFLECT((golos::network::current_connection_data), (connection_duration)
        (remote_endpoint)
        (node_id)
        (clock_offset)
        (round_trip_delay)
        (connection_direction)
        (firewalled)
        (user_data))
FC_REFLECT((golos::network::get_current_connections_reply_message), (upload_rate_one_minute)
        (download_rate_one_minute)
        (upload_rate_fifteen_minutes)
        (download_rate_fifteen_minutes)
        (upload_rate_one_hour)
        (download_rate_one_hour)
        (current_connections))

golos/libraries/network/include/golos/network/message.hpp
FC_REFLECT((golos::network::message_header), (size)(msg_type))
FC_REFLECT_DERIVED((golos::network::message), ((golos::network::message_header)), (data))

golos/libraries/network/include/golos/network/node.hpp
FC_REFLECT((golos::network::message_propagation_data), (received_time)(validated_time)(originating_peer))
FC_REFLECT((golos::network::peer_status), (version)(host)(info))

golos/libraries/network/node.cpp
FC_REFLECT((golos::network::detail::node_configuration), (listen_endpoint)
        (accept_incoming_connections)
        (wait_if_endpoint_is_busy)
        (private_key))

golos/libraries/chain/include/golos/chain/witness_objects.hpp
FC_REFLECT_ENUM(golos::chain::witness_object::witness_schedule_type, (top19)(timeshare)(miner)(none))
FC_REFLECT((golos::chain::witness_object),
        (id)
                (owner)
                (created)
                (url)(votes)(schedule)(virtual_last_update)(virtual_position)(virtual_scheduled_time)(total_missed)
                (last_aslot)(last_confirmed_block_num)(pow_worker)(signing_key)
                (props)
                (sbd_exchange_rate)(last_sbd_exchange_update)
                (last_work)
                (running_version)
                (hardfork_version_vote)(hardfork_time_vote)
)
FC_REFLECT((golos::chain::witness_vote_object), (id)(witness)(account))
FC_REFLECT((golos::chain::witness_schedule_object),
        (id)(current_virtual_time)(next_shuffle_block_num)(current_shuffled_witnesses)(num_scheduled_witnesses)
                (top19_weight)(timeshare_weight)(miner_weight)(witness_pay_normalization_factor)
                (median_props)(majority_version)
)

golos/libraries/chain/include/golos/chain/snapshot_state.hpp
FC_REFLECT((golos::chain::account_keys), (owner_key)(active_key)(posting_key)(memo_key))
FC_REFLECT((golos::chain::account_balances), (assets))
FC_REFLECT((golos::chain::snapshot_summary), (balance)(sbd_balance)(total_vesting_shares)(total_vesting_fund_steem)(accounts_count))
FC_REFLECT((golos::chain::account_summary), (id)(name)(posting_rewards)(curation_rewards)(keys)(balances)(json_metadata)(proxy)(post_count)(recovery_account)(reputation))
FC_REFLECT((golos::chain::snapshot_state), (timestamp)(head_block_num)(head_block_id)(chain_id)(summary)(accounts))

golos/libraries/chain/include/golos/chain/immutable_chain_parameters.hpp
FC_REFLECT((golos::chain::immutable_chain_parameters),
        (min_committee_member_count)
                (min_witness_count)
                (num_special_accounts)
                (num_special_assets)
)

golos/libraries/chain/include/golos/chain/transaction_object.hpp
FC_REFLECT((golos::chain::transaction_object), (id)(packed_trx)(trx_id)(expiration))

golos/libraries/chain/include/golos/chain/block_summary_object.hpp
FC_REFLECT((golos::chain::block_summary_object), (id)(block_id))

golos/libraries/chain/include/golos/chain/comment_object.hpp
FC_REFLECT_ENUM(golos::chain::comment_mode, (first_payout)(second_payout)(archived))
FC_REFLECT((golos::chain::comment_object),
        (id)(author)(permlink)
                (category)(parent_author)(parent_permlink)
                (title)(body)(json_metadata)(last_update)(created)(active)(last_payout)
                (depth)(children)(children_rshares2)
                (net_rshares)(abs_rshares)(vote_rshares)
                (children_abs_rshares)(cashout_time)(max_cashout_time)
                (total_vote_weight)(reward_weight)(total_payout_value)(curator_payout_value)(beneficiary_payout_value)
                (author_rewards)(net_votes)(root_comment)(mode)
                (max_accepted_payout)(percent_steem_dollars)(allow_replies)(allow_votes)(allow_curation_rewards)
                (beneficiaries)
)
FC_REFLECT((golos::chain::comment_vote_object),
        (id)(voter)(comment)(weight)(rshares)(vote_percent)(last_update)(num_changes)
)
FC_REFLECT((golos::chain::category_object),
        (id)(name)(abs_rshares)(total_payouts)(discussions)(last_update)
)

golos/libraries/chain/include/golos/chain/account_object.hpp
FC_REFLECT((golos::chain::account_object),
        (id)(name)(memo_key)(json_metadata)(proxy)(last_account_update)
                (created)(mined)
                (owner_challenged)(active_challenged)(last_owner_proved)(last_active_proved)(recovery_account)(last_account_recovery)(reset_account)
                (comment_count)(lifetime_vote_count)(post_count)(can_vote)(voting_power)(last_vote_time)
                (balance)
                (savings_balance)
                (sbd_balance)(sbd_seconds)(sbd_seconds_last_update)(sbd_last_interest_payment)
                (savings_sbd_balance)(savings_sbd_seconds)(savings_sbd_seconds_last_update)(savings_sbd_last_interest_payment)(savings_withdraw_requests)
                (vesting_shares)(vesting_withdraw_rate)(next_vesting_withdrawal)(withdrawn)(to_withdraw)(withdraw_routes)
                (curation_rewards)
                (posting_rewards)
                (proxied_vsf_votes)(witnesses_voted_for)
                (last_post)
)
FC_REFLECT((golos::chain::account_authority_object),
        (id)(account)(owner)(active)(posting)(last_owner_update)
)
FC_REFLECT((golos::chain::account_bandwidth_object),
        (id)(account)(type)(average_bandwidth)(lifetime_bandwidth)(last_bandwidth_update))
FC_REFLECT((golos::chain::owner_authority_history_object),
        (id)(account)(previous_owner_authority)(last_valid_time)
)
FC_REFLECT((golos::chain::account_recovery_request_object),
        (id)(account_to_recover)(new_owner_authority)(expires)
)
FC_REFLECT((golos::chain::change_recovery_account_request_object),
        (id)(account_to_recover)(recovery_account)(effective_on)
)

golos/libraries/chain/include/golos/chain/history_object.hpp
FC_REFLECT((golos::chain::operation_object), (id)(trx_id)(block)(trx_in_block)(op_in_trx)(virtual_op)(timestamp)(serialized_op))
FC_REFLECT((golos::chain::account_history_object), (id)(account)(sequence)(op))

golos/libraries/chain/include/golos/chain/hardfork.hpp
FC_REFLECT((golos::chain::hardfork_property_object),
        (id)(processed_hardforks)(last_hardfork)(current_hardfork_version)
                (next_hardfork)(next_hardfork_time))

golos/libraries/chain/include/golos/chain/global_property_object.hpp
FC_REFLECT((golos::chain::dynamic_global_property_object),
        (id)
                (head_block_number)
                (head_block_id)
                (time)
                (current_witness)
                (total_pow)
                (num_pow_witnesses)
                (virtual_supply)
                (current_supply)
                (confidential_supply)
                (current_sbd_supply)
                (confidential_sbd_supply)
                (total_vesting_fund_steem)
                (total_vesting_shares)
                (total_reward_fund_steem)
                (total_reward_shares2)
                (sbd_interest_rate)
                (sbd_print_rate)
                (average_block_size)
                (maximum_block_size)
                (current_aslot)
                (recent_slots_filled)
                (participation_count)
                (last_irreversible_block_num)
                (max_virtual_bandwidth)
                (current_reserve_ratio)
                (vote_regeneration_per_day)
)

golos/libraries/chain/include/golos/chain/shared_authority.hpp
FC_REFLECT_TYPENAME((golos::chain::shared_authority::account_authority_map))
FC_REFLECT((golos::chain::shared_authority), (weight_threshold)(account_auths)(key_auths))

golos/libraries/chain/include/golos/chain/steem_object_types.hpp
FC_REFLECT_ENUM(golos::chain::object_type,
        (dynamic_global_property_object_type)
                (account_object_type)
                (account_authority_object_type)
                (account_bandwidth_object_type)
                (witness_object_type)
                (transaction_object_type)
                (block_summary_object_type)
                (witness_schedule_object_type)
                (comment_object_type)
                (category_object_type)
                (comment_vote_object_type)
                (witness_vote_object_type)
                (limit_order_object_type)
                (feed_history_object_type)
                (convert_request_object_type)
                (liquidity_reward_balance_object_type)
                (operation_object_type)
                (account_history_object_type)
                (hardfork_property_object_type)
                (withdraw_vesting_route_object_type)
                (owner_authority_history_object_type)
                (account_recovery_request_object_type)
                (change_recovery_account_request_object_type)
                (escrow_object_type)
                (savings_withdraw_object_type)
                (decline_voting_rights_request_object_type)
                (block_stats_object_type)
)
FC_REFLECT_TYPENAME((golos::chain::shared_string))
FC_REFLECT_TYPENAME((golos::chain::buffer_type))
FC_REFLECT_ENUM(golos::chain::bandwidth_type, (post)(forum)(market)(old_forum)(old_market))

golos/libraries/chain/include/golos/chain/steem_objects.hpp
FC_REFLECT((golos::chain::limit_order_object),
        (id)(created)(expiration)(seller)(orderid)(for_sale)(sell_price))
FC_REFLECT((golos::chain::feed_history_object),
        (id)(current_median_history)(price_history))
FC_REFLECT((golos::chain::convert_request_object),
        (id)(owner)(requestid)(amount)(conversion_date))
FC_REFLECT((golos::chain::liquidity_reward_balance_object),
        (id)(owner)(steem_volume)(sbd_volume)(weight)(last_update))
FC_REFLECT((golos::chain::withdraw_vesting_route_object),
        (id)(from_account)(to_account)(percent)(auto_vest))
FC_REFLECT((golos::chain::savings_withdraw_object),
        (id)(from)(to)(memo)(request_id)(amount)(complete))
FC_REFLECT((golos::chain::escrow_object),
        (id)(escrow_id)(from)(to)(agent)
                (ratification_deadline)(escrow_expiration)
                (sbd_balance)(steem_balance)(pending_fee)
                (to_approved)(agent_approved)(disputed))
FC_REFLECT((golos::chain::decline_voting_rights_request_object),
        (id)(account)(effective_date))

golos/libraries/chain/database.cpp
FC_REFLECT((golos::chain::object_schema_repr), (space_type)(type))
FC_REFLECT((golos::chain::operation_schema_repr), (id)(type))
FC_REFLECT((golos::chain::db_schema), (types)(object_types)(operation_type)(custom_operation_types))

golos/libraries/protocol/include/golos/protocol/types.hpp
FC_REFLECT((golos::protocol::public_key_type), (key_data))
FC_REFLECT((golos::protocol::public_key_type::binary_key), (data)(check))
FC_REFLECT((golos::protocol::extended_public_key_type), (key_data))
FC_REFLECT((golos::protocol::extended_public_key_type::binary_key), (check)(data))
FC_REFLECT((golos::protocol::extended_private_key_type), (key_data))
FC_REFLECT((golos::protocol::extended_private_key_type::binary_key), (check)(data))
FC_REFLECT_TYPENAME((golos::protocol::share_type))
FC_REFLECT((golos::void_t),)

golos/libraries/protocol/include/golos/protocol/block_header.hpp
FC_REFLECT((golos::protocol::block_header), (previous)(timestamp)(witness)(transaction_merkle_root)(extensions))
FC_REFLECT_DERIVED((golos::protocol::signed_block_header), ((golos::protocol::block_header)), (witness_signature))

golos/libraries/protocol/include/golos/protocol/block.hpp
FC_REFLECT_DERIVED((golos::protocol::signed_block), ((golos::protocol::signed_block_header)), (transactions))

golos/libraries/protocol/include/golos/protocol/version.hpp
FC_REFLECT((golos::protocol::version), (v_num))
FC_REFLECT_DERIVED((golos::protocol::hardfork_version), ((golos::protocol::version)),)
FC_REFLECT((golos::protocol::hardfork_version_vote), (hf_version)(hf_time))

golos/libraries/protocol/include/golos/protocol/transaction.hpp
FC_REFLECT((golos::protocol::transaction), (ref_block_num)(ref_block_prefix)(expiration)(operations)(extensions))
FC_REFLECT_DERIVED((golos::protocol::signed_transaction), ((golos::protocol::transaction)), (signatures))
FC_REFLECT_DERIVED((golos::protocol::annotated_signed_transaction), ((golos::protocol::signed_transaction)), (transaction_id)(block_num)(transaction_num))

golos/libraries/protocol/include/golos/protocol/asset.hpp
FC_REFLECT((golos::protocol::asset), (amount)(symbol))
FC_REFLECT((golos::protocol::price), (base)(quote))

golos/libraries/protocol/include/golos/protocol/steem_operations.hpp
FC_REFLECT((golos::protocol::transfer_to_savings_operation), (from)(to)(amount)(memo))
FC_REFLECT((golos::protocol::transfer_from_savings_operation), (from)(request_id)(to)(amount)(memo))
FC_REFLECT((golos::protocol::cancel_transfer_from_savings_operation), (from)(request_id))
FC_REFLECT((golos::protocol::reset_account_operation), (reset_account)(account_to_reset)(new_owner_authority))
FC_REFLECT((golos::protocol::set_reset_account_operation), (account)(current_reset_account)(reset_account))
FC_REFLECT((golos::protocol::report_over_production_operation), (reporter)(first_block)(second_block))
FC_REFLECT((golos::protocol::convert_operation), (owner)(requestid)(amount))
FC_REFLECT((golos::protocol::feed_publish_operation), (publisher)(exchange_rate))
FC_REFLECT((golos::protocol::pow), (worker)(input)(signature)(work))
FC_REFLECT((golos::protocol::pow2), (input)(pow_summary))
FC_REFLECT((golos::protocol::pow2_input), (worker_account)(prev_block)(nonce))
FC_REFLECT((golos::protocol::equihash_pow), (input)(proof)(prev_block)(pow_summary))
FC_REFLECT((golos::protocol::chain_properties), (account_creation_fee)(maximum_block_size)(sbd_interest_rate))
FC_REFLECT_TYPENAME((golos::protocol::pow2_work))
FC_REFLECT((golos::protocol::pow_operation), (worker_account)(block_id)(nonce)(work)(props))
FC_REFLECT((golos::protocol::pow2_operation), (work)(new_owner_key)(props))
FC_REFLECT((golos::protocol::account_create_operation),
        (fee)
                (creator)
                (new_account_name)
                (owner)
                (active)
                (posting)
                (memo_key)
                (json_metadata))
FC_REFLECT((golos::protocol::account_update_operation),
        (account)
                (owner)
                (active)
                (posting)
                (memo_key)
                (json_metadata))
FC_REFLECT((golos::protocol::transfer_operation), (from)(to)(amount)(memo))
FC_REFLECT((golos::protocol::transfer_to_vesting_operation), (from)(to)(amount))
FC_REFLECT((golos::protocol::withdraw_vesting_operation), (account)(vesting_shares))
FC_REFLECT((golos::protocol::set_withdraw_vesting_route_operation), (from_account)(to_account)(percent)(auto_vest))
FC_REFLECT((golos::protocol::witness_update_operation), (owner)(url)(block_signing_key)(props)(fee))
FC_REFLECT((golos::protocol::account_witness_vote_operation), (account)(witness)(approve))
FC_REFLECT((golos::protocol::account_witness_proxy_operation), (account)(proxy))
FC_REFLECT((golos::protocol::comment_operation), (parent_author)(parent_permlink)(author)(permlink)(title)(body)(json_metadata))
FC_REFLECT((golos::protocol::vote_operation), (voter)(author)(permlink)(weight))
FC_REFLECT((golos::protocol::custom_operation), (required_auths)(id)(data))
FC_REFLECT((golos::protocol::custom_json_operation), (required_auths)(required_posting_auths)(id)(json))
FC_REFLECT((golos::protocol::custom_binary_operation), (required_owner_auths)(required_active_auths)(required_posting_auths)(required_auths)(id)(data))
FC_REFLECT((golos::protocol::limit_order_create_operation), (owner)(orderid)(amount_to_sell)(min_to_receive)(fill_or_kill)(expiration))
FC_REFLECT((golos::protocol::limit_order_create2_operation), (owner)(orderid)(amount_to_sell)(exchange_rate)(fill_or_kill)(expiration))
FC_REFLECT((golos::protocol::limit_order_cancel_operation), (owner)(orderid))
FC_REFLECT((golos::protocol::delete_comment_operation), (author)(permlink))
FC_REFLECT((golos::protocol::beneficiary_route_type), (account)(weight))
FC_REFLECT((golos::protocol::comment_payout_beneficiaries), (beneficiaries))
FC_REFLECT_TYPENAME((golos::protocol::comment_options_extension))
FC_REFLECT((golos::protocol::comment_options_operation), (author)(permlink)(max_accepted_payout)(percent_steem_dollars)(allow_votes)(allow_curation_rewards)(extensions))
FC_REFLECT((golos::protocol::escrow_transfer_operation), (from)(to)(sbd_amount)(steem_amount)(escrow_id)(agent)(fee)(json_meta)(ratification_deadline)(escrow_expiration))
FC_REFLECT((golos::protocol::escrow_approve_operation), (from)(to)(agent)(who)(escrow_id)(approve))
FC_REFLECT((golos::protocol::escrow_dispute_operation), (from)(to)(agent)(who)(escrow_id))
FC_REFLECT((golos::protocol::escrow_release_operation), (from)(to)(agent)(who)(receiver)(escrow_id)(sbd_amount)(steem_amount))
FC_REFLECT((golos::protocol::challenge_authority_operation), (challenger)(challenged)(require_owner))
FC_REFLECT((golos::protocol::prove_authority_operation), (challenged)(require_owner))
FC_REFLECT((golos::protocol::request_account_recovery_operation), (recovery_account)(account_to_recover)(new_owner_authority)(extensions))
FC_REFLECT((golos::protocol::recover_account_operation), (account_to_recover)(new_owner_authority)(recent_owner_authority)(extensions))
FC_REFLECT((golos::protocol::change_recovery_account_operation), (account_to_recover)(new_recovery_account)(extensions))
FC_REFLECT((golos::protocol::decline_voting_rights_operation), (account)(decline))

golos/libraries/protocol/include/golos/protocol/base.hpp
FC_REFLECT_TYPENAME((golos::protocol::block_header_extensions))
FC_REFLECT_TYPENAME((golos::protocol::future_extensions))

golos/libraries/protocol/include/golos/protocol/operations.hpp
FC_REFLECT_TYPENAME((golos::protocol::operation))

golos/libraries/protocol/include/golos/protocol/steem_virtual_operations.hpp
FC_REFLECT((golos::protocol::author_reward_operation), (author)(permlink)(sbd_payout)(steem_payout)(vesting_payout))
FC_REFLECT((golos::protocol::curation_reward_operation), (curator)(reward)(comment_author)(comment_permlink))
FC_REFLECT((golos::protocol::comment_reward_operation), (author)(permlink)(payout))
FC_REFLECT((golos::protocol::fill_convert_request_operation), (owner)(requestid)(amount_in)(amount_out))
FC_REFLECT((golos::protocol::liquidity_reward_operation), (owner)(payout))
FC_REFLECT((golos::protocol::interest_operation), (owner)(interest))
FC_REFLECT((golos::protocol::fill_vesting_withdraw_operation), (from_account)(to_account)(withdrawn)(deposited))
FC_REFLECT((golos::protocol::shutdown_witness_operation), (owner))
FC_REFLECT((golos::protocol::fill_order_operation), (current_owner)(current_orderid)(current_pays)(open_owner)(open_orderid)(open_pays))
FC_REFLECT((golos::protocol::fill_transfer_from_savings_operation), (from)(to)(amount)(request_id)(memo))
FC_REFLECT((golos::protocol::hardfork_operation), (hardfork_id))
FC_REFLECT((golos::protocol::comment_payout_update_operation), (author)(permlink))
FC_REFLECT((golos::protocol::comment_benefactor_reward_operation), (benefactor)(author)(permlink)(reward) )

golos/libraries/protocol/include/golos/protocol/authority.hpp
FC_REFLECT_TYPENAME((golos::protocol::authority::account_authority_map))
FC_REFLECT_TYPENAME((golos::protocol::authority::key_authority_map))
FC_REFLECT((golos::protocol::authority), (weight_threshold)(account_auths)(key_auths))
FC_REFLECT_ENUM(golos::protocol::authority::classification, (owner)(active)(key)(posting))

golos/tests/tests/operation_time_tests.cpp
FC_REFLECT( (golos::plugins::block_info::block_info),
    //     (block_id)
    //     (block_size)
    //     (average_block_size)
    //     (aslot)
    //     (last_irreversible_block_num)
    //     (num_pow_witnesses)
    // )
FC_REFLECT( (golos::plugins::block_info::block_with_info),
    //     (block)
    //     (info)
    // )

golos/tests/plugin_tests/plugin_ops.cpp
FC_REFLECT( golos::plugin_tests::test_a_operation, (account) )
FC_REFLECT( golos::plugin_tests::test_b_operation, (account) )
FC_REFLECT_TYPENAME( golos::plugin_tests::test_op )

golos/programs/util/test_shared_mem.cpp
FC_REFLECT((book), (name)(author)(pages)(prize)(deq)(auth))
FC_REFLECT((astr), (str)(str1)(str2))
FC_REFLECT((bstr), (str)(str1)(str2))

golos/programs/util/sign_transaction.cpp
FC_REFLECT((tx_signing_request), (tx)(wif))
FC_REFLECT((tx_signing_result), (digest)(sig_digest)(key)(sig))

golos/programs/util/schema_test.cpp
FC_REFLECT(mystruct,
(alpha)
        (beta)
)

golos/programs/util/sign_digest.cpp
FC_REFLECT((signing_request), (dig)(wif))
FC_REFLECT((signing_result), (dig)(key)(sig))

golos/thirdparty/chainbase/include/chainbase/chainbase.hpp
FC_REFLECT()

golos/thirdparty/fc/include/fc/variant.hpp
FC_REFLECT_TYPENAME((fc::variant))
FC_REFLECT_ENUM(fc::variant::type_id,
                (null_type)(int64_type)(uint64_type)(double_type)(bool_type)(string_type)(array_type)(object_type)(
                        blob_type))
FC_REFLECT((fc::blob), (data))

golos/thirdparty/fc/include/fc/bloom_filter.hpp
FC_REFLECT((fc::bloom_filter), (salt_)(bit_table_)(salt_count_)(table_size_)(raw_table_size_)(projected_element_count_)(
        inserted_element_count_)(random_seed_)(desired_false_positive_probability_))
FC_REFLECT((fc::bloom_parameters::optimal_parameters_t), (number_of_hashes)(table_size))
FC_REFLECT((fc::bloom_parameters),
           (minimum_size)(maximum_size)(minimum_number_of_hashes)(maximum_number_of_hashes)(projected_element_count)(
                   false_positive_probability)(random_seed)(optimal_parameters))

golos/thirdparty/fc/include/fc/network/ip.hpp
FC_REFLECT_TYPENAME((fc::ip::address))
FC_REFLECT_TYPENAME((fc::ip::endpoint))

golos/thirdparty/fc/include/fc/network/http/connection.hpp
FC_REFLECT((fc::http::header), (key)(val))

golos/thirdparty/fc/include/fc/uint128_t.hpp
FC_REFLECT((fc::uint128_t), (hi)(lo))

golos/thirdparty/fc/include/fc/crypto/elliptic.hpp
FC_REFLECT_TYPENAME((fc::ecc::private_key))
FC_REFLECT_TYPENAME((fc::ecc::public_key))
FC_REFLECT((fc::ecc::range_proof_info), (exp)(mantissa)(min_value)(max_value))

golos/thirdparty/fc/include/fc/crypto/equihash.hpp
FC_REFLECT((fc::equihash::proof), (n)(k)(seed)(inputs))

golos/thirdparty/fc/include/fc/crypto/sha224.hpp
FC_REFLECT_TYPENAME((fc::sha224))

golos/thirdparty/fc/include/fc/crypto/sha256.hpp
FC_REFLECT_TYPENAME((fc::sha256))

golos/thirdparty/fc/include/fc/crypto/sha512.hpp
FC_REFLECT_TYPENAME((fc::sha512))

golos/thirdparty/fc/include/fc/safe.hpp
FC_REFLECT_TEMPLATE((typename T), (fc::safe<T>), (value))

golos/thirdparty/fc/include/fc/rpc/bstate.hpp
FC_REFLECT( (fc::rpc::brequest), (id)(method)(params) )
FC_REFLECT( (fc::rpc::bresponse), (id)(result)(error) )

golos/thirdparty/fc/include/fc/rpc/state.hpp
FC_REFLECT( (fc::rpc::request), (jsonrpc)(id)(method)(params) )
FC_REFLECT( (fc::rpc::error_object), (code)(message)(data) )
FC_REFLECT( (fc::rpc::response), (id)(result)(error) )

golos/thirdparty/fc/include/fc/time.hpp
FC_REFLECT_TYPENAME((fc::time_point))
FC_REFLECT_TYPENAME((fc::microseconds))
FC_REFLECT_TYPENAME((fc::time_point_sec))

golos/thirdparty/fc/include/fc/log/log_message.hpp
FC_REFLECT_TYPENAME((fc::log_message))

golos/thirdparty/fc/include/fc/log/json_console_appender.hpp
FC_REFLECT_ENUM(fc::json_console_appender::j_stream::type, (std_out)(std_error))
FC_REFLECT_ENUM(fc::json_console_appender::j_color::type,
                (red)(green)(brown)(blue)(magenta)(cyan)(white)(console_default))
FC_REFLECT((fc::json_console_appender::j_level_color), (level)(color))
FC_REFLECT((fc::json_console_appender::j_config), (format)(stream)(level_colors)(flush))

golos/thirdparty/fc/include/fc/log/logger_config.hpp
FC_REFLECT((fc::appender_config), (name)(type)(args)(enabled))
FC_REFLECT((fc::logger_config), (name)(parent)(level)(enabled)(additivity)(appenders))
FC_REFLECT((fc::logging_config), (includes)(appenders)(loggers))

golos/thirdparty/fc/include/fc/log/file_appender.hpp
FC_REFLECT((fc::file_appender::config), (format)(filename)(flush)(rotate)(rotation_interval)(rotation_limit))

golos/thirdparty/fc/include/fc/log/console_appender.hpp
FC_REFLECT_ENUM(fc::console_appender::stream::type, (std_out)(std_error))
FC_REFLECT_ENUM(fc::console_appender::color::type, (red)(green)(brown)(blue)(magenta)(cyan)(white)(console_default))
FC_REFLECT((fc::console_appender::level_color), (level)(color))
FC_REFLECT((fc::console_appender::config), (format)(stream)(level_colors)(flush))

golos/thirdparty/fc/include/fc/log/gelf_appender.hpp
FC_REFLECT((fc::gelf_appender::config), (endpoint)(host))
