cmake_minimum_required(VERSION 3.14)
project(header_test_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS
    catch.hpp
    shapes_1.hpp test_shapes_1.cpp
    # shapes_2.hpp test_shapes_2.cpp
    # shapes_3.hpp test_shapes_3.cpp
    # shapes_4.hpp test_shapes_4.cpp
)

add_executable(test_main header_test_1.cpp shapes_1.hpp)
add_executable(test_shapes_steps ${STEPS})

enable_testing()