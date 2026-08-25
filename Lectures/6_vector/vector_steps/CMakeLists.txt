cmake_minimum_required(VERSION 3.14)
project(vector_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    test_vector_1.cpp
    # test_vector_2.cpp
    # test_vector_3.cpp
    # test_vector_4.cpp
    # test_vector_5.cpp
    # test_vector_6.cpp
    # test_vector_7.cpp
)

add_executable(test_vector ${STEPS})

enable_testing()
add_test(NAME test-vector COMMAND test_vector)