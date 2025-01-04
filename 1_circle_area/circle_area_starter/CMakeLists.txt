cmake_minimum_required(VERSION 3.5)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# this project set-up is not useful for now, but would help in the future
project(circle_area)

# this is the line that matters, build a target circle_area from source code circle_area_starter.cpp
add_executable(circle_area circle_area_starter.cpp)