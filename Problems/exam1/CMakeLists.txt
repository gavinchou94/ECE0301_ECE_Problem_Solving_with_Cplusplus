cmake_minimum_required(VERSION 3.10)
project(exam1)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exam1 exam1.cpp exam1.hpp catch.hpp)

enable_testing()

add_test(test-exam1 exam1)