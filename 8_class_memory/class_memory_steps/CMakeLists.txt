cmake_minimum_required(VERSION 3.5)
project(class_memory)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_class_memory3.cpp SafeArray3.hpp SafeArray3.cpp 
        catch.hpp)

add_executable(test_class_memory ${SOURCE})

enable_testing()

add_test(test-class-memory test_class_memory)