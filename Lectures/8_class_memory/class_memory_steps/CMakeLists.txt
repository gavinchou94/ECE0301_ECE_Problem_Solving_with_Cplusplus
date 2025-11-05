cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(class_memory)
# change to xx2, xx3, xx4, xx5 to test steps incrementally
set(SOURCE test_class_memory5.cpp SafeArray5.hpp SafeArray5.cpp catch.hpp)
add_executable(test_class_memory ${SOURCE})

enable_testing()

add_test(test-class-memory test_class_memory)