cmake_minimum_required(VERSION 3.14)
project(circle_area_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS
    circle_area_2.cpp
    # circle_area_3.cpp
    # circle_area_3b.cpp
    # circle_area_4.cpp
    # circle_area_4b.cpp
    # circle_area_5.cpp
    # circle_area_6.cpp
    # circle_area_7.cpp
    # circle_area_8.cpp
)

add_executable(circle_area_steps ${STEPS})

enable_testing()
add_test(NAME test-circle-area-steps COMMAND circle_area_steps)