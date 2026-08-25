cmake_minimum_required(VERSION 3.14)
project(pointers_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    test_pointers_1.cpp
    # test_pointers_2.cpp
    # test_pointers_3.cpp
    # test_pointers_4.cpp
    # pointers_5.hpp test_pointers_5.cpp
    # pointers_6.hpp test_pointers_6.cpp
    # pointers_7.hpp test_pointers_7.cpp
)

add_executable(test_pointers ${STEPS})

enable_testing()
add_test(NAME test-pointers COMMAND test_pointers)