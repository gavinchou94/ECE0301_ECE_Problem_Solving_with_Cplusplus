cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(final)
add_executable(final test_final.cpp Final.hpp Final.cpp Final.tpp catch.hpp)

enable_testing()

add_test(test-final final)