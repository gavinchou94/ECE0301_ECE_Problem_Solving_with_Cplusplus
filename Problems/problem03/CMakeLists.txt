cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(problem03)
add_executable(problem03 problem03.cpp)