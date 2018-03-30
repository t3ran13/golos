file(GLOB COMMON_SOURCES "common/*.cpp")

find_package(Gperftools QUIET)
if(GPERFTOOLS_FOUND)
    message(STATUS "Found gperftools; compiling tests with TCMalloc")
    list(APPEND PLATFORM_SPECIFIC_LIBS tcmalloc)
endif()

if(NOT Boost_USE_STATIC_LIBS)
    add_definitions(-DBOOST_TEST_DYN_LINK)
endif()

file(GLOB UNIT_TESTS "tests/*.cpp")
add_executable(chain_test ${UNIT_TESTS} ${COMMON_SOURCES})
target_link_libraries(
        chain_test
        chainbase
        golos_chain
        golos_protocol
        golos_account_history
        golos_market_history
        golos_debug_node
        golos_block_info
        fc ${PLATFORM_SPECIFIC_LIBS}
)

add_test(NAME chain_test_run COMMAND chain_test)

file(GLOB PLUGIN_TESTS "plugin_tests/*.cpp")
add_executable(plugin_test ${PLUGIN_TESTS} ${COMMON_SOURCES})

target_link_libraries(plugin_test
    golos_chain
    golos_protocol
    golos_account_history
    golos_market_history
    golos_debug_node
    fc
    ${PLATFORM_SPECIFIC_LIBS}
)
add_test(NAME plugin_test_run COMMAND plugin_test)

file(GLOB REFLECT_TESTS "reflect/*.cpp")
add_executable(reflect_test ${REFLECT_TESTS} ${COMMON_SOURCES})

target_link_libraries(reflect_test
    golos_chain
    appbase
    golos::webserver_plugin
    golos::p2p
    graphene_utilities
    golos::chain_plugin
    golos::network_broadcast_api
    golos::witness
    golos::database_api
    golos::test_api_plugin
    golos::social_network
    golos::market_history
    golos::blockchain_statistics
    golos::account_by_key
    golos::account_history
    golos::private_message
    golos::auth_util
    golos::debug_node
    golos::raw_block
    golos::block_info
    golos::json_rpc
    golos_protocol
    golos::follow
    golos_wallet
    golos_network
    fc
    ${PLATFORM_SPECIFIC_LIBS}
)

add_test(NAME reflect_test_run COMMAND reflect_test)

if(MSVC)
    set_source_files_properties(tests/serialization_tests.cpp PROPERTIES COMPILE_FLAGS "/bigobj")
endif(MSVC)

# add_subdirectory( generate_empty_blocks )
