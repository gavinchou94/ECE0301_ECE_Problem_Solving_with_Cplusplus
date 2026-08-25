cmake_minimum_required(VERSION 3.14)
project(exam1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exam1 exam1.cpp exam1.hpp catch.hpp)

enable_testing()
add_test(test-exam1 exam1)