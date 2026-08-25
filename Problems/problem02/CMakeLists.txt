cmake_minimum_required(VERSION 3.14)
project(problem02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem02 problem02.cpp)

if(EXISTS "${PROJECT_SOURCE_DIR}/problem02_bonus.cpp")
    add_executable(problem02_bonus problem02_bonus.cpp)
endif()