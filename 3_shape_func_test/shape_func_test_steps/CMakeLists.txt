cmake_minimum_required(VERSION 3.5)
project(shape_func_test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shape_area_functions shape_area_functions_starter.cpp shapes_7.hpp)
add_executable(test_shapes test_shapes_7C.cpp shapes_7.hpp catch.hpp)

enable_testing()

add_test(test-shapes test_shapes)
