cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(problem02)
add_executable(problem02 problem02.cpp)

if(EXISTS "${PROJECT_SOURCE_DIR}/problem02_bonus.cpp")
    add_executable(problem02_bonus problem02_bonus.cpp)
endif()
