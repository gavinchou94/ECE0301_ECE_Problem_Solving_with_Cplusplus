cmake_minimum_required(VERSION 3.10)
project(vec_and_class)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_vector test_vector.cpp catch.hpp)

enable_testing()

add_test(test-vector test_vector)
