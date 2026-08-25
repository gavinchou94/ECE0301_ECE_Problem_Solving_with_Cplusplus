cmake_minimum_required(VERSION 3.14)
project(arrays_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    test_arrays_1.cpp
    # arrays_2.hpp test_arrays_2.cpp
    # arrays_2.hpp test_arrays_3.cpp
    # arrays_4.hpp test_arrays_4.cpp
    # arrays_5.hpp test_arrays_5.cpp
    # arrays_6.hpp constants.hpp test_arrays_6.cpp
    # arrays_7.hpp constants.hpp test_arrays_7.cpp
)

add_executable(test_arrays ${STEPS})

enable_testing()
add_test(NAME test-arrays COMMAND test_arrays)