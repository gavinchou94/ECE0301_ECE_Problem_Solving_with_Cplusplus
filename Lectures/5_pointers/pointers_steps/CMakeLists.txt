cmake_minimum_required(VERSION 3.10)
project(pointers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# change to _2, _3, _4, to test different steps
#add_executable(test_pointers test_pointers_1.cpp catch.hpp)

# change to _6, _7, to test different steps
add_executable(test_pointers test_pointers_5.cpp pointers_5.hpp catch.hpp)

enable_testing()

add_test(test-pointers test_pointers)
