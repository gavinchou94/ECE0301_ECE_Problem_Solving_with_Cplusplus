cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(header_test)
# add_executable(header_test header_test_1.cpp shapes_1A.hpp)

# switch to run the test file _1, _2, _3, _4 instead of the main program from here
add_executable(header_test test_shapes_1.cpp shapes_1.hpp catch.hpp)