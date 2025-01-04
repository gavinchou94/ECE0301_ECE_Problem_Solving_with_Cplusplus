cmake_minimum_required(VERSION 3.5)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(problem01)
add_executable(problem01 problem01.cpp)