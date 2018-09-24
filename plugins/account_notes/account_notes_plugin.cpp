#include <golos/plugins/account_notes/account_notes_plugin.hpp>
#include <golos/plugins/account_notes/account_notes_evaluators.hpp>
#include <golos/plugins/account_notes/account_notes_objects.hpp>
#include <golos/plugins/json_rpc/api_helper.hpp>
#include <golos/plugins/chain/plugin.hpp>
#include <appbase/application.hpp>

#include <golos/chain/index.hpp>
#include <golos/chain/custom_operation_interpreter.hpp>
#include <golos/chain/generic_custom_operation_interpreter.hpp>

#include <fc/smart_ref_impl.hpp>

#include <mutex>

namespace golos { namespace plugins { namespace account_notes {

namespace bpo = boost::program_options;

class account_notes_plugin::account_notes_plugin_impl final {
public:
    account_notes_plugin_impl(account_notes_plugin& plugin)
            : db_(appbase::app().get_plugin<golos::plugins::chain::plugin>().db()) {
        // Each plugin needs its own evaluator registry.
        custom_operation_interpreter_ = std::make_shared<
            generic_custom_operation_interpreter<account_notes_plugin_operation>>(db_);

        auto coi = custom_operation_interpreter_.get();

        // Add each operation evaluator to the registry
        coi->register_evaluator<set_value_evaluator>(&plugin);

        // Add the registry to the database so the database can delegate custom ops to the plugin
        db_.set_custom_operation_interpreter(plugin.name(), custom_operation_interpreter_);
    }

    ~account_notes_plugin_impl() = default;

    golos::chain::database& database() {
        return db_;
    }

    golos::chain::database& database() const {
        return db_;
    }

    string get_value(
        account_name_type account, string key
    ) const;

    uint16_t max_key_length = 20;

    uint16_t max_value_length = 512;

    uint16_t max_note_count = 10;

    std::vector<std::string> tracked_accounts;

    std::vector<std::string> untracked_accounts;

private:
    golos::chain::database& db_;
    std::shared_ptr<generic_custom_operation_interpreter<account_notes_plugin_operation>> custom_operation_interpreter_;
};

string account_notes_plugin::account_notes_plugin_impl::get_value(
    account_name_type account,
    string key
) const {
    string result;

    const auto& notes_idx = db_.get_index<account_note_index, by_account_key>();
    auto notes_itr = notes_idx.find(boost::make_tuple(account, key));
    if (notes_itr != notes_idx.end()) {
        result = to_string(notes_itr->value);
    }

    return result;
}

account_notes_plugin::account_notes_plugin() = default;

account_notes_plugin::~account_notes_plugin() = default;

const std::string& account_notes_plugin::name() {
    static std::string name = "account_notes";
    return name;
}

void account_notes_plugin::set_program_options(
    bpo::options_description& cli,
    bpo::options_description& cfg
) {
    cfg.add_options() (
        "an-tracked-accounts",
        bpo::value<string>()->default_value("[]"),
        "Defines a count of accounts to store notes"
    ) (
        "an-untracked-accounts",
        bpo::value<string>()->default_value("[]"),
        "Defines a count of accounts to do not store notes"
    ) (
        "an-max-key-length",
        bpo::value<uint16_t>()->default_value(20),
        "Maximum length of note key"
    ) (
        "an-max-value-length",
        bpo::value<uint16_t>()->default_value(512),
        "Maximum length of note value"
    ) (
        "an-max-note-count",
        bpo::value<uint16_t>()->default_value(10),
        "Maximum count of key-value notes per account"
    );
}

void account_notes_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
    ilog("Intializing account notes plugin");
    my = std::make_unique<account_notes_plugin::account_notes_plugin_impl>(*this);

    add_plugin_index<account_note_index>(my->database());

    my->max_key_length = options.at("an-max-key-length").as<uint16_t>();

    my->max_value_length = options.at("an-max-value-length").as<uint16_t>();

    my->max_note_count = options.at("an-max-note-count").as<uint16_t>();

    if (options.count("an-tracked-accounts")) {
        auto tracked_accounts = options["an-tracked-accounts"].as<string>();
        my->tracked_accounts = fc::json::from_string(tracked_accounts).as<std::vector<std::string>>();
    }

    if (options.count("an-untracked-accounts")) {
        auto untracked_accounts = options["an-untracked-accounts"].as<string>();
        my->untracked_accounts = fc::json::from_string(untracked_accounts).as<std::vector<std::string>>();
    }

    JSON_RPC_REGISTER_API(name())
}

void account_notes_plugin::plugin_startup() {
    ilog("Starting up account notes plugin");
}

void account_notes_plugin::plugin_shutdown() {
    ilog("Shutting down account notes plugin");
}

uint16_t account_notes_plugin::max_key_length() {
    return my->max_key_length;
}

uint16_t account_notes_plugin::max_value_length() {
    return my->max_value_length;
}

uint16_t account_notes_plugin::max_note_count() {
    return my->max_note_count;
}

bool account_notes_plugin::is_tracked_account(const account_name_type& account) {
    if (!my->tracked_accounts.empty()
        && std::find(my->tracked_accounts.begin(), my->tracked_accounts.end(), std::string(account)) == my->tracked_accounts.end()) {
        return false;
    }

    if (std::find(my->untracked_accounts.begin(), my->untracked_accounts.end(), std::string(account)) != my->untracked_accounts.end()) {
        return false;
    }

    return true;
}

// Api Defines

DEFINE_API(account_notes_plugin, get_value) {
    PLUGIN_API_VALIDATE_ARGS(
        (account_name_type, account)
        (string,          key)
    )
    return my->database().with_weak_read_lock([&]() {
        return my->get_value(account, key);
    });
}

} } } // golos::plugins::account_notes
