cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello-world) # project name can be anything

# target name can be anything, but .cpp file must match the file name
add_executable(hello-world-cmake hello_world_cmake.cpp)