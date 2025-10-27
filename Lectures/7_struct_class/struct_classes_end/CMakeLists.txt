cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(struct_and_class)
add_executable(test_vector test_vector.cpp catch.hpp)
add_executable(test_class test_class.cpp Employee.hpp Employee.cpp Date.hpp Date.cpp catch.hpp)

enable_testing()

add_test(test-vector test_vector)
add_test(test-class test_class)