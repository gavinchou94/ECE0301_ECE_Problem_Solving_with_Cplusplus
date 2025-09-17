cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(header_test)
add_executable(header_test test_shapes.cpp shapes.hpp catch.hpp)