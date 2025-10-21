cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(vector)
# change to _2, _3 ..., _7 to look through code
add_executable(test_vector test_vector_1.cpp catch.hpp)

enable_testing()

add_test(test-vector test_vector)