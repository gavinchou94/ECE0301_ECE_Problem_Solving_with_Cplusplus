cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(circle_area)
# change the source codes to _3, _3b, _4, _4b, _5, _6, _7, _8 to test
add_executable(circle_area circle_area_2.cpp)