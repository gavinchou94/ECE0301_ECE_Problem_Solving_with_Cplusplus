cmake_minimum_required(VERSION 3.14)
project(shape_func_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS
    shape_func_1.cpp
    # shape_func_2.cpp
    # shape_func_3.cpp
    # shape_func_4.cpp
    # shape_func_5.cpp
    # shape_func_6.cpp
)

add_executable(test_shape_func ${STEPS})

enable_testing()