cmake_minimum_required(VERSION 3.14)
project(class_memory_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    SafeArray1.hpp SafeArray1.cpp test_class_memory1.cpp
    # SafeArray2.hpp SafeArray2.cpp test_class_memory2.cpp
    # SafeArray3.hpp SafeArray3.cpp test_class_memory3.cpp
    # SafeArray4.hpp SafeArray4.cpp test_class_memory4.cpp
    # SafeArray5.hpp SafeArray5.cpp test_class_memory5.cpp
)

add_executable(test_class_memory ${STEPS})

enable_testing()
add_test(NAME test-class-memory COMMAND test_class_memory)