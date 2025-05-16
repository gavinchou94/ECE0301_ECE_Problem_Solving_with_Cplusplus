cmake_minimum_required(VERSION 3.10)
project(problem08)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_frequency test_frequency.cpp Frequency.hpp Frequency.cpp catch.hpp)

enable_testing()

add_test(test-frequency test_frequency)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem08.zip" --format=zip
       test_frequency.cpp frequency.hpp frequency.cpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})