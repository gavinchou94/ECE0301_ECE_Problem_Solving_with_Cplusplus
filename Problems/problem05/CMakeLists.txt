cmake_minimum_required(VERSION 3.10)
project(problem05)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem05-tests problem05_tests.cpp solver.hpp constants.hpp catch.hpp)

enable_testing()

add_test(test-problem05 problem05-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem05_submission.zip" --format=zip
       problem05_tests.cpp solver.hpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})