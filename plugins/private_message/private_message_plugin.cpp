#include <golos/plugins/private_message/private_message_plugin.hpp>
#include <golos/plugins/private_message/private_message_evaluators.hpp>
#include <golos/plugins/private_message/private_message_objects.hpp>
#include <golos/plugins/private_message/private_message_exceptions.hpp>
#include <golos/plugins/json_rpc/api_helper.hpp>
#include <golos/plugins/chain/plugin.hpp>
#include <appbase/application.hpp>

#include <golos/chain/index.hpp>
#include <golos/chain/custom_operation_interpreter.hpp>
#include <golos/chain/generic_custom_operation_interpreter.hpp>

#include <fc/smart_ref_impl.hpp>


//
template<typename T>
T dejsonify(const std::string &s) {
    return fc::json::from_string(s).as<T>();
}

#define LOAD_VALUE_SET(options, name, container, type) \
if( options.count(name) ) { \
    const std::vector<std::string>& ops = options[name].as<std::vector<std::string>>(); \
    std::transform(ops.begin(), ops.end(), std::inserter(container, container.end()), &dejsonify<type>); \
}
//

namespace golos { namespace plugins { namespace private_message {

    class private_message_plugin::private_message_plugin_impl final {
    public:
        private_message_plugin_impl(private_message_plugin& plugin)
            : db_(appbase::app().get_plugin<golos::plugins::chain::plugin>().db()) {

            custom_operation_interpreter_ = std::make_shared
                    <generic_custom_operation_interpreter<private_message::private_message_plugin_operation>>(db_);

            custom_operation_interpreter_->register_evaluator<private_message_evaluator>(&plugin);
            custom_operation_interpreter_->register_evaluator<private_delete_message_evaluator>(&plugin);
            custom_operation_interpreter_->register_evaluator<private_mark_message_evaluator>(&plugin);
            custom_operation_interpreter_->register_evaluator<private_settings_evaluator>(&plugin);
            custom_operation_interpreter_->register_evaluator<private_contact_evaluator>(&plugin);

            db_.set_custom_operation_interpreter(plugin.name(), custom_operation_interpreter_);
        }

        std::vector<message_api_object> get_inbox(const std::string& to, const inbox_query&) const;

        std::vector<message_api_object> get_outbox(const std::string& from, const outbox_query&) const;

        std::vector<message_api_object> get_thread(
            const std::string& from, const std::string& to, const thread_query&) const;

        settings_api_object get_settings(const std::string& owner) const;

        contact_api_object get_contact_item(const contact_object& o) const;

        contact_api_object get_contact_info(const std::string& owner, const std::string& contact) const;

        contacts_size_api_object get_contacts_size(const std::string& owner) const;

        std::vector<contact_api_object> get_contacts(
            const std::string& owner, const private_contact_type, uint16_t limit, uint32_t offset) const;

        ~private_message_plugin_impl() = default;

        bool is_tracked_account(account_name_type) const;

        std::shared_ptr<generic_custom_operation_interpreter<private_message_plugin_operation>> custom_operation_interpreter_;
        flat_map<std::string, std::string> tracked_account_ranges_;
        flat_set<std::string> tracked_account_list_;

        golos::chain::database& db_;
    };

    static inline time_point_sec min_create_date() {
        return time_point_sec(1);
    }

    std::vector<message_api_object> private_message_plugin::private_message_plugin_impl::get_inbox(
        const std::string& to, const inbox_query& query
    ) const {
        std::vector<message_api_object> result;
        const auto& idx = db_.get_index<message_index>().indices().get<by_inbox>();

        auto itr = idx.lower_bound(std::make_tuple(to, query.start_date));
        auto etr = idx.upper_bound(std::make_tuple(to, min_create_date()));
        auto offset = query.offset;

        auto filter = [&](const message_object& o) {
            return
                (query.select_from.empty() || query.select_from.count(o.from)) &&
                (!query.unread_only || o.read_date == time_point_sec::min());
        };

        for (; itr != etr && offset; ++itr) {
            if (filter(*itr)){
                --offset;
            }
        }

        result.reserve(query.limit);
        for (; itr != etr && result.size() < query.limit; ++itr) {
            if (filter(*itr)) {
                result.emplace_back(*itr);
            }
        }

        return result;
    }

    std::vector<message_api_object> private_message_plugin::private_message_plugin_impl::get_outbox(
        const std::string& from, const outbox_query& query
    ) const {

        std::vector<message_api_object> result;
        const auto& idx = db_.get_index<message_index>().indices().get<by_outbox>();

        auto itr = idx.lower_bound(std::make_tuple(from, query.start_date));
        auto etr = idx.upper_bound(std::make_tuple(from, min_create_date()));
        auto offset = query.offset;

        auto filter = [&](const message_object& o) {
            return
                (query.select_to.empty() || query.select_to.count(o.to)) &&
                (!query.unread_only || o.read_date == time_point_sec::min());
        };

        for (; itr != etr && offset; ++itr) {
            if (filter(*itr)){
                --offset;
            }
        }

        result.reserve(query.limit);
        for (; itr != etr && result.size() < query.limit; ++itr) {
            if (filter(*itr)) {
                result.emplace_back(*itr);
            }
        }

        return result;
    }

    std::vector<message_api_object> private_message_plugin::private_message_plugin_impl::get_thread(
        const std::string& from, const std::string& to, const thread_query& query
    ) const {

        std::vector<message_api_object> result;
        const auto& outbox_idx = db_.get_index<message_index>().indices().get<by_outbox_account>();
        const auto& inbox_idx = db_.get_index<message_index>().indices().get<by_inbox_account>();

        auto outbox_itr = outbox_idx.lower_bound(std::make_tuple(from, to, query.start_date));
        auto outbox_etr = outbox_idx.upper_bound(std::make_tuple(from, to, min_create_date()));
        auto inbox_itr = inbox_idx.lower_bound(std::make_tuple(from, to, query.start_date));
        auto inbox_etr = inbox_idx.upper_bound(std::make_tuple(from, to, min_create_date()));
        auto offset = query.offset;

        auto filter = [&](const message_object& o) {
            return (!query.unread_only || o.read_date == time_point_sec::min());
        };

        auto itr_to_message = [&](auto& itr) -> const message_object& {
            const message_object& result = *itr;
            ++itr;
            return result;
        };

        auto select_message = [&]() -> const message_object& {
            if (outbox_itr != outbox_etr) {
                if (inbox_itr == inbox_etr || outbox_itr->id > inbox_itr->id) {
                    return itr_to_message(outbox_itr);
                }
            }
            return itr_to_message(inbox_itr);
        };

        auto is_not_done = [&]() -> bool {
            return outbox_itr != outbox_etr || inbox_itr != inbox_etr;
        };

        while (is_not_done() && offset) {
            auto& message = select_message();
            if (filter(message)){
                --offset;
            }
        }

        result.reserve(query.limit);
        while (is_not_done() && result.size() < query.limit) {
            auto& message = select_message();
            if (filter(message)) {
                result.emplace_back(message);
            }
        }

        return result;
    }

    settings_api_object private_message_plugin::private_message_plugin_impl::get_settings(
        const std::string& owner
    ) const {
        const auto& idx = db_.get_index<settings_index>().indices().get<by_owner>();
        auto itr = idx.find(owner);
        if (itr != idx.end()) {
            return settings_api_object(*itr);
        }

        return settings_api_object();
    }

    contact_api_object private_message_plugin::private_message_plugin_impl::get_contact_item(
        const contact_object& o
    ) const {
        contact_api_object result(o);

        const auto& idx = db_.get_index<contact_index>().indices().get<by_contact>();
        auto itr = idx.find(std::make_tuple(o.contact, o.owner));

        if (idx.end() != itr) {
            result.remote_type = itr->type;
        }

        return result;
    }

    contact_api_object private_message_plugin::private_message_plugin_impl::get_contact_info(
        const std::string& owner, const std::string& contact
    ) const {
        const auto& idx = db_.get_index<contact_index>().indices().get<by_contact>();
        auto itr = idx.find(std::make_tuple(owner, contact));

        if (itr != idx.end()) {
            return get_contact_item(*itr);
        }
        return contact_api_object();
    }

    contacts_size_api_object private_message_plugin::private_message_plugin_impl::get_contacts_size(
        const std::string& owner
    ) const {
        contacts_size_api_object result;

        const auto& idx = db_.get_index<contact_size_index>().indices().get<by_owner>();
        auto itr = idx.lower_bound(std::make_tuple(owner, unknown));
        auto etr = idx.upper_bound(std::make_tuple(owner, private_contact_type_size));

        for (; etr != itr; ++itr) {
            result.size[itr->type] = itr->size;
        }

        for (uint8_t i = unknown; i < private_contact_type_size; ++i) {
            auto t = static_cast<private_contact_type>(i);
            if (!result.size.count(t)) {
                result.size[t] = contacts_size_info();
            }
        }

        return result;
    }

    std::vector<contact_api_object> private_message_plugin::private_message_plugin_impl::get_contacts(
        const std::string& owner, const private_contact_type type, uint16_t limit, uint32_t offset
    ) const {
        std::vector<contact_api_object> result;

        result.reserve(limit);

        const auto& idx = db_.get_index<contact_index>().indices().get<by_owner>();
        auto itr = idx.lower_bound(std::make_tuple(owner, type));
        auto etr = idx.upper_bound(std::make_tuple(owner, type));

        for (; itr != etr && offset; ++itr, --offset);

        for (; itr != etr; ++itr) {
            result.push_back(get_contact_item(*itr));
        }
        return result;
    }

    void private_message_evaluator::do_apply(const private_message_operation& pm) {
        database& d = db();

        if (!plugin_->is_tracked_account(pm.from) && !plugin_->is_tracked_account(pm.to)) {
            return;
        }

        auto& contact_idx = d.get_index<contact_index>().indices().get<by_contact>();
        auto contact_itr = contact_idx.find(std::make_tuple(pm.to, pm.from));

        auto& cfg_idx = d.get_index<settings_index>().indices().get<by_owner>();
        auto cfg_itr = cfg_idx.find(pm.to);

        GOLOS_CHECK_OP_PARAM(pm, to, {
            d.get_account(pm.to);
            GOLOS_CHECK_LOGIC(contact_itr == contact_idx.end() || contact_itr->type != ignored,
                logic_errors::sender_in_ignore_list,
                "Sender is in the ignore list of recipient");
            GOLOS_CHECK_LOGIC(
                (cfg_itr == cfg_idx.end() || !cfg_itr->ignore_messages_from_unknown_contact) ||
                (contact_itr != contact_idx.end() && contact_itr->type == pinned),
                logic_errors::recepient_ignores_messages_from_unknown_contact,
                "Recipient accepts messages only from his contact list");
        });

        auto& id_idx = d.get_index<message_index>().indices().get<by_nonce>();
        auto id_itr = id_idx.find(std::make_tuple(pm.from, pm.to, pm.nonce));

        GOLOS_CHECK_OP_PARAM(pm, nonce, {
            if (pm.update && id_itr == id_idx.end()) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("from", pm.from)("to", pm.to)("nonce", pm.nonce));
            } else if (!pm.update && id_itr != id_idx.end()){
                GOLOS_THROW_OBJECT_ALREADY_EXIST("private_message",
                    fc::mutable_variant_object()("from", pm.from)("to", pm.to)("nonce", pm.nonce));
            }
        });

        auto now = d.head_block_time();

        auto set_message = [&](message_object& pmo) {
            pmo.from_memo_key = pm.from_memo_key;
            pmo.to_memo_key = pm.to_memo_key;
            pmo.checksum = pm.checksum;
            pmo.read_date = time_point_sec::min();
            pmo.receive_date = now;
            pmo.encrypted_message.resize(pm.encrypted_message.size());
            std::copy(
                pm.encrypted_message.begin(), pm.encrypted_message.end(),
                pmo.encrypted_message.begin());
        };

        if (id_itr == id_idx.end()) {
            d.create<message_object>([&](message_object& pmo) {
                pmo.from = pm.from;
                pmo.to = pm.to;
                pmo.nonce = pm.nonce;
                pmo.inbox_create_date = now;
                pmo.outbox_create_date = now;
                pmo.remove_date = time_point_sec::min();
                set_message(pmo);
            });
        } else {
            d.modify(*id_itr, set_message);
        }

        // Ok, now update contact lists and counters in them
        auto& size_idx = d.get_index<contact_size_index>().indices().get<by_owner>();

        // Increment counters depends on side of communication
        auto inc_counters = [&](auto& o, const bool is_send) {
            if (is_send) {
                o.total_outbox_messages++;
                o.unread_outbox_messages++;
            } else {
                o.total_inbox_messages++;
                o.unread_inbox_messages++;
            }
        };

        // Update global counters by type of contact
        auto modify_size = [&](auto& owner, auto type, const bool is_new_contact, const bool is_send) {
            auto modify_counters = [&](auto& pcso) {
                inc_counters(pcso.size, is_send);
                if (is_new_contact) {
                    pcso.size.total_contacts++;
                }
            };

            auto size_itr = size_idx.find(std::make_tuple(owner, type));
            if (size_idx.end() == size_itr) {
                d.create<contact_size_object>([&](auto& pcso){
                    pcso.owner = owner;
                    pcso.type = type;
                    modify_counters(pcso);
                });
            } else {
                d.modify(*size_itr, modify_counters);
            }
        };

        // Add contact list if it doesn't exist or update it if it exits
        auto modify_contact = [&](auto& owner, auto& contact, auto type, const bool is_send) {
            bool is_new_contact;
            auto contact_itr = contact_idx.find(std::make_tuple(owner, contact));
            if (contact_idx.end() != contact_itr) {
                d.modify(*contact_itr, [&](auto& pco) {
                    inc_counters(pco.size, is_send);
                });
                is_new_contact = false;
                type = contact_itr->type;
            } else {
                d.create<contact_object>([&](auto& pco) {
                    pco.owner = owner;
                    pco.contact = contact;
                    pco.type = type;
                    inc_counters(pco.size, is_send);
                });
                is_new_contact = true;
            }
            modify_size(owner, type, is_new_contact, is_send);
        };

        modify_contact(pm.from, pm.to, pinned, true);
        modify_contact(pm.to, pm.from, unknown, false);
    }

    template <typename Direction, typename Operation, typename Action, typename... Args>
    bool process_private_messages(database& db, const Operation& po, Action&& action, Args&&... args) {
        auto start_date = std::max(po.start_date, min_create_date());
        auto stop_date = std::max(po.stop_date, min_create_date());

        auto& idx = db.get_index<message_index>().indices().get<Direction>();
        auto itr = idx.lower_bound(std::make_tuple(std::forward<Args>(args)..., stop_date));
        auto etr = idx.lower_bound(std::make_tuple(std::forward<Args>(args)..., start_date));

        if (itr == etr) {
            return false;
        }

        while (itr != etr) {
            auto& message = (*itr);
            ++itr;
            if (!action(message)) {
                break;
            }
        }
        return true;
    }

    template <typename Operation, typename Map, typename ProcessAction, typename ContactAction>
    void process_group_message_operation(
        database& db, const Operation& po, const std::string& requester,
        Map& map, ProcessAction&& process_action, ContactAction&& contact_action
    ) {
        if (po.nonce != 0) {
            auto& idx = db.get_index<message_index>().indices().get<by_nonce>();
            auto itr = idx.find(std::make_tuple(po.from, po.to, po.nonce));

            if (itr == idx.end()) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("from", po.from)("to", po.to)("nonce", po.nonce));
            }

            process_action(*itr);
        } else if (po.from.size() && po.to.size()) {
            if (!process_private_messages<by_outbox_account>(db, po, process_action, po.from, po.to)) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("from", po.from)("to", po.to)
                    ("start_date", po.start_date)("stop_date", po.stop_date));
            }
        } else if (po.from.size()) {
            if (!process_private_messages<by_outbox>(db, po, process_action, po.from)) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("from", po.from)
                    ("start_date", po.start_date)("stop_date", po.stop_date));
            }
        } else if (po.to.size()) {
            if (!process_private_messages<by_inbox>(db, po, process_action, po.to)) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("to", po.to)
                    ("start_date", po.start_date)("stop_date", po.stop_date));
            }
        } else {
            if (!process_private_messages<by_inbox>(db, po, process_action, requester) &&
                !process_private_messages<by_outbox>(db, po, process_action, requester)
            ) {
                GOLOS_THROW_MISSING_OBJECT("private_message",
                    fc::mutable_variant_object()("requester", requester)
                    ("start_date", po.start_date)("stop_date", po.stop_date));
            }
        }

        auto& contact_idx = db.get_index<contact_index>().indices().get<by_contact>();
        auto& size_idx = db.get_index<contact_size_index>().indices().get<by_owner>();

        for (const auto& stat_info: map) {
            const auto& owner = std::get<0>(stat_info.first);
            const auto& size = stat_info.second;
            auto contact_itr = contact_idx.find(stat_info.first);
            auto size_itr = size_idx.find(owner);

            GOLOS_CHECK_LOGIC(contact_idx.end() != contact_itr && size_idx.end() != size_itr,
                logic_errors::invalid_size, "Invalid size");

            if (!contact_action(*contact_itr, *size_itr, size)) {
                db.modify(*contact_itr, [&](auto& pco) {
                    pco.size -= size;
                });
                db.modify(*size_itr, [&](auto& pcso){
                    pcso.size -= size;
                });
            }
        }
    }

    void private_delete_message_evaluator::do_apply(const private_delete_message_operation& pdm) {
        database& d = db();
        auto now = d.head_block_time();
        fc::flat_map<std::tuple<account_name_type, account_name_type>, contact_size_info> stat_map;

        process_group_message_operation(
            d, pdm, pdm.requester, stat_map,
            /* process_action */
            [&](const message_object& m) -> bool {
                uint32_t unread_messages = 0;

                if (m.read_date == time_point_sec::min()) {
                    unread_messages = 1;
                }
                if (pdm.requester == pdm.to) {
                    // remove from inbox
                    if (m.inbox_create_date == time_point_sec::min()) {
                        return false;
                    }
                    auto& inbox_stat = stat_map[std::make_tuple(m.to, m.from)];
                    inbox_stat.unread_inbox_messages += unread_messages;
                    inbox_stat.total_inbox_messages++;
                } else {
                    // remove from outbox
                    if (m.outbox_create_date == time_point_sec::min()) {
                        return false;
                    }
                    auto& outbox_stat = stat_map[std::make_tuple(m.from, m.to)];
                    outbox_stat.unread_outbox_messages += unread_messages;
                    outbox_stat.total_outbox_messages++;
                }
                if (m.remove_date == time_point_sec::min()) {
                    d.modify(m, [&](auto& m) {
                        m.remove_date = now;
                        if (pdm.requester == pdm.to) {
                            m.inbox_create_date = time_point_sec::min(); // remove message from find requests
                        } else {
                            m.outbox_create_date = time_point_sec::min(); // remove message from find requests
                        }
                    });
                } else {
                    d.remove(m);
                }
                return true;
            },
            /* contact_action */
            [&](const contact_object& co, const contact_size_object& so, const contact_size_info& size) -> bool {
                if (co.size != size || co.type != unknown) {
                    return false;
                }
                d.remove(co);
                if (so.size.total_contacts == 1) {
                    d.remove(so);
                } else {
                    d.modify(so, [&](auto& pcso) {
                        pcso.size.total_contacts--;
                        pcso.size -= size;
                    });
                }
                return true;
            }
        );
    }

    void private_mark_message_evaluator::do_apply(const private_mark_message_operation& pmm) {
        database& d = db();

        uint32_t total_marked_messages = 0;
        auto now = d.head_block_time();
        fc::flat_map<std::tuple<account_name_type, account_name_type>, contact_size_info> stat_map;

        process_group_message_operation(
            d, pmm, "", stat_map,
            /* process_action */
            [&](const message_object& m) -> bool {
                if (m.read_date != time_point_sec::min()) {
                    return true;
                }
                // only recipient can mark messages
                stat_map[std::make_tuple(m.to, m.from)].unread_inbox_messages++;
                // if sender hasn't yet removed the message
                if (m.remove_date == time_point_sec::min()) {
                    stat_map[std::make_tuple(m.from, m.to)].unread_outbox_messages++;
                }
                total_marked_messages++;

                d.modify(m, [&](message_object& m){
                    m.read_date = now;
                });
                return true;
            },

            /* contact_action */
            [&](const contact_object&, const contact_size_object&, const contact_size_info&) -> bool {
                return false;
            }
        );

        GOLOS_CHECK_LOGIC(total_marked_messages > 0,
            logic_errors::no_unread_messages,
            "No unread messages in requested range");
    }

    void private_settings_evaluator::do_apply(const private_settings_operation& ps) {
        database& d = db();

        auto& idx = d.get_index<settings_index>().indices().get<by_owner>();
        auto itr = idx.find(ps.owner);

        auto set_settings = [&](settings_object& pso) {
            pso.owner = ps.owner;
            pso.ignore_messages_from_unknown_contact = ps.ignore_messages_from_unknown_contact;
        };

        if (idx.end() != itr) {
            d.modify(*itr, set_settings);
        } else {
            d.create<settings_object>(set_settings);
        }
    }

    void private_contact_evaluator::do_apply(const private_contact_operation& pc) {
        database& d = db();

        if (!plugin_->is_tracked_account(pc.owner) && !plugin_->is_tracked_account(pc.contact)) {
            return;
        }

        auto& contact_idx = d.get_index<contact_index>().indices().get<by_contact>();
        auto contact_itr = contact_idx.find(std::make_tuple(pc.owner, pc.contact));

        GOLOS_CHECK_OP_PARAM(pc, contact, {
            d.get_account(pc.contact);

            if (d.is_producing()) {
                GOLOS_CHECK_LOGIC(contact_idx.end() != contact_itr || pc.type != unknown,
                    logic_errors::add_unknown_contact,
                    "Can't add unknown contact");

                std::string json_metadata(contact_itr->json_metadata.begin(), contact_itr->json_metadata.end());
                GOLOS_CHECK_LOGIC(contact_itr->type != pc.type || pc.json_metadata != json_metadata,
                    logic_errors::contact_has_same_type,
                    "Contact has the same type");
            }
        });

        auto& owner_idx = d.get_index<contact_size_index>().indices().get<by_owner>();
        auto dst_itr = owner_idx.find(std::make_tuple(pc.owner, pc.type));

        if (contact_idx.end() != contact_itr) {
            auto src_itr = owner_idx.find(std::make_tuple(pc.owner, contact_itr->type));
            if (contact_itr->type != pc.type) {
                // last contact
                if (src_itr->size.total_contacts == 1) {
                    d.remove(*src_itr);
                } else {
                    d.modify(*src_itr, [&](auto& src) {
                        src.size.total_contacts--;
                        src.size -= contact_itr->size;
                    });
                }

                // has messages or type is not unknown
                if (!contact_itr->size.empty() || pc.type != unknown) {
                    auto modify_counters = [&](auto& dst) {
                        dst.size.total_contacts++;
                        dst.size += contact_itr->size;
                    };

                    if (owner_idx.end() == dst_itr) {
                        d.create<contact_size_object>([&](auto& dst) {
                            dst.owner = pc.owner;
                            dst.type = pc.type;
                            modify_counters(dst);
                        });
                    } else {
                        d.modify(*dst_itr, modify_counters);
                    }
                }
            }

            // contact is unknown and no messages
            if (pc.type == unknown && contact_itr->size.empty()) {
                d.remove(*contact_itr);
            } else {
                d.modify(*contact_itr, [&](auto& plo) {
                    plo.type = pc.type;
                    from_string(plo.json_metadata, pc.json_metadata);
                });
            }
        } else if (pc.type != unknown) {
            d.create<contact_object>([&](auto& plo){
                plo.owner = pc.owner;
                plo.contact = pc.contact;
                plo.type = pc.type;
                from_string(plo.json_metadata, pc.json_metadata);
            });

            if (owner_idx.end() == dst_itr) {
                d.create<contact_size_object>([&](auto& pcso) {
                    pcso.owner = pc.owner;
                    pcso.type = pc.type;
                    pcso.size.total_contacts = 1;
                });
            } else {
                d.modify(*dst_itr, [&](auto& pcso) {
                    pcso.size.total_contacts++;
                });
            }
        }
    }

    private_message_plugin::private_message_plugin() = default;

    private_message_plugin::~private_message_plugin() = default;

    const std::string& private_message_plugin::name() {
        static std::string name = "private_message";
        return name;
    }

    void private_message_plugin::set_program_options(
        boost::program_options::options_description& cli,
        boost::program_options::options_description& cfg
    ) {
        cfg.add_options()
            ("pm-account-range",
             boost::program_options::value<std::vector<std::string>>()->composing()->multitoken(),
             "Defines a range of accounts to private messages to/from as a json pair [\"from\",\"to\"] [from,to]")
            ("pm-account-list",
             boost::program_options::value<std::vector<std::string>>()->composing()->multitoken(),
             "Defines a list of accounts to private messages to/from");
    }

    void private_message_plugin::plugin_initialize(const boost::program_options::variables_map &options) {
        ilog("Intializing private message plugin");
        my = std::make_unique<private_message_plugin::private_message_plugin_impl>(*this);

        add_plugin_index<message_index>(my->db_);
        add_plugin_index<settings_index>(my->db_);
        add_plugin_index<contact_index>(my->db_);
        add_plugin_index<contact_size_index>(my->db_);

        using pairstring = std::pair<std::string, std::string>;
        LOAD_VALUE_SET(options, "pm-account-range", my->tracked_account_ranges_, pairstring);
        if (options.count("pm-account-list")) {
            auto list = options["pm-account-list"].as<std::vector<std::string>>();
            my->tracked_account_list_.insert(list.begin(), list.end());
        }
        JSON_RPC_REGISTER_API(name())
    }

    void private_message_plugin::plugin_startup() {
        ilog("Starting up private message plugin");
    }

    void private_message_plugin::plugin_shutdown() {
        ilog("Shuting down private message plugin");
    }

    bool private_message_plugin::private_message_plugin_impl::is_tracked_account(account_name_type name) const {
        if (tracked_account_ranges_.empty() && tracked_account_list_.empty()) {
            return true;
        }

        auto list_itr = tracked_account_list_.find(name);
        if (tracked_account_list_.end() != list_itr) {
            return true;
        }

        auto range_itr = tracked_account_ranges_.lower_bound(name);
        return tracked_account_ranges_.end() != range_itr && name >= range_itr->first && name <= range_itr->second;
    }

    bool private_message_plugin::is_tracked_account(account_name_type name) const {
        return my->is_tracked_account(name);
    }

    // Api Defines

    DEFINE_API(private_message_plugin, get_inbox) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, to)
            (inbox_query, query)
        );

        GOLOS_CHECK_LIMIT_PARAM(query.limit, PRIVATE_DEFAULT_LIMIT);

        if (!query.limit) {
            query.limit = PRIVATE_DEFAULT_LIMIT;
        }

        if (query.start_date == time_point_sec::min()) {
            query.start_date = my->db_.head_block_time();
        }

        return my->db_.with_weak_read_lock([&]() {
            return my->get_inbox(to, query);
        });
    }

    DEFINE_API(private_message_plugin, get_outbox) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, from)
            (outbox_query, query)
        );

        GOLOS_CHECK_LIMIT_PARAM(query.limit, PRIVATE_DEFAULT_LIMIT);

        if (!query.limit) {
            query.limit = PRIVATE_DEFAULT_LIMIT;
        }

        if (query.start_date == time_point_sec::min()) {
            query.start_date = my->db_.head_block_time();
        }

        return my->db_.with_weak_read_lock([&]() {
            return my->get_outbox(from, query);
        });
    }

    DEFINE_API(private_message_plugin, get_thread) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, from)
            (std::string, to)
            (thread_query, query)
        );

        GOLOS_CHECK_LIMIT_PARAM(query.limit, PRIVATE_DEFAULT_LIMIT);

        if (!query.limit) {
            query.limit = PRIVATE_DEFAULT_LIMIT;
        }

        if (query.start_date == time_point_sec::min()) {
            query.start_date = my->db_.head_block_time();
        }

        return my->db_.with_weak_read_lock([&]() {
            return my->get_thread(from, to, query);
        });
    }

    DEFINE_API(private_message_plugin, get_settings) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, owner)
        );

        return my->db_.with_weak_read_lock([&](){
            return my->get_settings(owner);
        });
    }

    DEFINE_API(private_message_plugin, get_contacts_size) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, owner)
        );

        return my->db_.with_weak_read_lock([&](){
            return my->get_contacts_size(owner);
        });
    }

    DEFINE_API(private_message_plugin, get_contact_info) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, owner)
            (std::string, contact)
        );

        return my->db_.with_weak_read_lock([&](){
            return my->get_contact_info(owner, contact);
        });
    }

    DEFINE_API(private_message_plugin, get_contacts) {
        PLUGIN_API_VALIDATE_ARGS(
            (std::string, owner)
            (private_contact_type, type)
            (uint16_t, limit)
            (uint32_t, offset)
        );

        GOLOS_CHECK_LIMIT_PARAM(limit, 100);

        return my->db_.with_weak_read_lock([&](){
            return my->get_contacts(owner, type, limit, offset);
        });
    }

} } } // golos::plugins::private_message
