cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(arrays)
# change to _2, _4, _5, ... as needed
add_executable(test_arrays test_arrays_2.cpp arrays_2.hpp catch.hpp constants.hpp)

enable_testing()

add_test(test-arrays test_arrays)
