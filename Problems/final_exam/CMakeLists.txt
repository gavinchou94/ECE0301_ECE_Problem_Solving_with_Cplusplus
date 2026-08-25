cmake_minimum_required(VERSION 3.14)
project(final_exam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(final test_final.cpp Final.hpp Final.cpp Final.tpp catch.hpp)

enable_testing()
add_test(test-final final)