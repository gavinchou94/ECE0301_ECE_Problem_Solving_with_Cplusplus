cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(shape_func)
# change the source codes from _1, _2 ..., to _6 to test
add_executable(shape_func shape_func_1.cpp)