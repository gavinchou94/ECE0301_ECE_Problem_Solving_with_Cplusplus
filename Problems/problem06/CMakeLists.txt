cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(problem06)
add_executable(problem06-tests problem06_tests.cpp database.hpp constants.hpp catch.hpp)

enable_testing()

add_test(test-problem06 problem06-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem06_submission.zip" --format=zip
       problem06_tests.cpp database.hpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})