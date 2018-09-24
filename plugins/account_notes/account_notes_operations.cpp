#include <golos/plugins/account_notes/account_notes_operations.hpp>
#include <golos/plugins/account_notes/account_notes_plugin.hpp>
#include <golos/protocol/authority.hpp>
#include <golos/protocol/operation_util_impl.hpp>
#include <golos/protocol/exceptions.hpp>
#include <golos/protocol/validate_helper.hpp>
#include <fc/io/json.hpp>

namespace golos {

template<>
std::string get_logic_error_namespace<golos::plugins::account_notes::logic_errors::error_type>() {
    return golos::plugins::account_notes::account_notes_plugin::name();
}

} // namespace golos

namespace golos { namespace plugins { namespace account_notes {

using golos::protocol::is_valid_account_name;

static inline void validate_account_name(const string& name) {
    GOLOS_CHECK_VALUE(is_valid_account_name(name), "Account name ${name} is invalid", ("name", name));
}

void set_value_operation::validate() const {
    GOLOS_CHECK_PARAM_ACCOUNT(account);
}

} } } // golos::plugins::account_notes

DEFINE_OPERATION_TYPE(golos::plugins::account_notes::account_notes_plugin_operation);