cmake_minimum_required(VERSION 3.5)
project(pointers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_pointers test_pointers_1.cpp pointers_starter.hpp catch.hpp)

enable_testing()

add_test(test-pointers test_pointers)
