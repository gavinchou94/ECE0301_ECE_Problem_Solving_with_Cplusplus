cmake_minimum_required(VERSION 3.5)
project(arrays)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_arrays test_arrays.cpp arrays.hpp catch.hpp constants.hpp)

enable_testing()

add_test(test-arrays test_arrays)