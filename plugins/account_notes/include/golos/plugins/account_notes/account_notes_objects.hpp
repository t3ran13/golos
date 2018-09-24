#pragma once

#include <golos/protocol/authority.hpp>
#include <golos/protocol/base.hpp>
#include <golos/protocol/operations.hpp>
#include <golos/protocol/steem_operations.hpp>
#include <golos/chain/index.hpp>
#include <golos/chain/steem_object_types.hpp>
#include <chainbase/chainbase.hpp>

#include <boost/multi_index/composite_key.hpp>

//
// Plugins should #define their SPACE_ID's so plugins with
// conflicting SPACE_ID assignments can be compiled into the
// same binary (by simply re-assigning some of the conflicting #defined
// SPACE_ID's in a build script).
//
// Assignment of SPACE_ID's cannot be done at run-time because
// various template automagic depends on them being known at compile
// time.
//

#ifndef ACCOUNT_NOTES_SPACE_ID
#define ACCOUNT_NOTES_SPACE_ID 13
#endif


namespace golos { namespace plugins { namespace account_notes {

using chainbase::allocator;
using chainbase::object;
using chainbase::object_id;
using golos::chain::by_id;
using golos::chain::shared_string;
using namespace boost::multi_index;

enum account_object_types {
    account_note_object_type = (ACCOUNT_NOTES_SPACE_ID << 8)
};

class account_note_object final : public object<account_note_object_type, account_note_object> {
public:
    template<typename Constructor, typename Allocator>
    account_note_object(Constructor&& c, allocator<Allocator> a)
            :  key(a), value(a) {
        c(*this);
    }

    id_type id;

    account_name_type account;
    shared_string key;
    shared_string value;
};

using account_note_id_type = object_id<account_note_object>;

struct by_account;
struct by_account_key;

using account_note_index = multi_index_container<
    account_note_object,
    indexed_by<
        ordered_unique<
            tag<by_id>,
            member<account_note_object, account_note_id_type, &account_note_object::id>>,
        ordered_non_unique<
            tag<by_account>,
            member<account_note_object, account_name_type, &account_note_object::account>>,
        ordered_unique<
            tag<by_account_key>,
            composite_key<account_note_object,
                member<account_note_object, account_name_type, &account_note_object::account>,
                member<account_note_object, shared_string, &account_note_object::key>>,
            composite_key_compare<std::less<account_name_type>, chainbase::strcmp_less>>>,
    allocator<account_note_object>>;

} } } // golos::plugins::account_notes

CHAINBASE_SET_INDEX_TYPE(
    golos::plugins::account_notes::account_note_object,
    golos::plugins::account_notes::account_note_index)
