cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pointers)
add_executable(test_pointers test_pointers_starter.cpp pointers_starter.hpp catch.hpp)

enable_testing()

add_test(test-pointers test_pointers)
