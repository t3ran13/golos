#pragma once

#include <golos/plugins/account_notes/account_notes_operations.hpp>
#include <golos/plugins/account_notes/account_notes_plugin.hpp>
#include <golos/chain/database.hpp>
#include <golos/chain/evaluator.hpp>

namespace golos { namespace plugins { namespace account_notes {

using golos::chain::database;
using golos::chain::evaluator;
using golos::chain::evaluator_impl;

class set_value_evaluator : public golos::chain::evaluator_impl<set_value_evaluator, account_notes_plugin_operation> {
public:
    using operation_type = set_value_operation;

    set_value_evaluator(database& db, account_notes_plugin* plugin)
            : evaluator_impl<set_value_evaluator, account_notes_plugin_operation>(db), plugin_(plugin) {
    }

    void do_apply(const set_value_operation& o);

private:
    account_notes_plugin* plugin_;
};

} } } // golos::plugins::account_notes
