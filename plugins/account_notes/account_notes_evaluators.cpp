#include <golos/plugins/account_notes/account_notes_operations.hpp>
#include <golos/plugins/account_notes/account_notes_objects.hpp>
#include <golos/plugins/account_notes/account_notes_evaluators.hpp>
#include <golos/chain/account_object.hpp>

namespace golos { namespace plugins { namespace account_notes {

using golos::chain::from_string;

void set_value_evaluator::do_apply(const set_value_operation& o) {
    try {
        GOLOS_CHECK_OP_PARAM(o, account, {
            GOLOS_CHECK_VALUE(plugin_->is_tracked_account(o.account),
                "Account ${account} is not tracked.", ("account", o.account));
        });

        db().get_account(o.account);

        auto max_key_length = plugin_->max_key_length();
        GOLOS_CHECK_OP_PARAM(o, key, {
            GOLOS_CHECK_VALUE(o.key.size() <= max_key_length,
                "Key is too long: ${size} bytes provided, ${limit} is maximum allowed.", ("size", o.key.size())("limit", max_key_length));
        });

        auto max_value_length = plugin_->max_value_length();
        GOLOS_CHECK_OP_PARAM(o, value, {
            GOLOS_CHECK_VALUE(o.value.size() <= max_value_length,
                "Value is too long: ${size} bytes provided, ${limit} is maximum allowed.", ("size", o.value.size())("limit", max_value_length));
        });

        const auto& notes_idx = db().get_index<account_note_index, by_account_key>();
        auto notes_itr = notes_idx.find(boost::make_tuple(o.account, o.key));

        if (o.value.empty()) { // Delete case
            if (notes_itr != notes_idx.end()) {
                db().remove(*notes_itr);
            }
            return;
        }

        if (notes_itr != notes_idx.end()) { // Edit case
            db().modify(*notes_itr, [&](account_note_object& n) {
                from_string(n.value, o.value);
            });
        } else { // Create case
            const auto& count_idx = db().get_index<account_note_index, by_account>();
            auto notes = count_idx.count(o.account);

            GOLOS_CHECK_LOGIC(notes < plugin_->max_note_count(),
                logic_errors::note_count_limit_exceeded,
                "Note count limit is exceeded for this account. Cannot add anymore notes.");

            db().create<account_note_object>([&](account_note_object& n) {
                n.account = o.account;
                from_string(n.key, o.key);
                from_string(n.value, o.value);
            });
        }
    }
    FC_CAPTURE_AND_RETHROW((o))
}

} } } // golos::plugins::account_notes
