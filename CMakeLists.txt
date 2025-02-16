cmake_minimum_required(VERSION 3.30)

project(rune)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("src")

enable_testing()

add_executable(test_assert tests/test_assert.cpp)
add_test(NAME test_assert COMMAND $<TARGET_FILE:test_assert>)
set_property(TEST test_assert PROPERTY WILL_FAIL TRUE)

add_executable(test_panic tests/test_panic.cpp)
add_test(NAME test_panic COMMAND $<TARGET_FILE:test_panic>)
set_property(TEST test_panic PROPERTY WILL_FAIL TRUE)

add_executable(test_expect tests/test_expect.cpp)
add_test(NAME test_expect COMMAND $<TARGET_FILE:test_expect>)
set_property(TEST test_expect PROPERTY WILL_FAIL TRUE)

add_executable(test_unreachable tests/test_unreachable.cpp)
add_test(NAME test_unreachable COMMAND $<TARGET_FILE:test_unreachable>)
set_property(TEST test_unreachable PROPERTY WILL_FAIL TRUE)

add_executable(test_unimplemented tests/test_unimplemented.cpp)
add_test(NAME test_unimplemented COMMAND $<TARGET_FILE:test_unimplemented>)
set_property(TEST test_unimplemented PROPERTY WILL_FAIL TRUE)
