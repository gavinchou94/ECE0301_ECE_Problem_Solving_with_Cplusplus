cmake_minimum_required(VERSION 3.14)
project(problem08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem08-tests test_frequency.cpp Frequency.hpp Frequency.cpp catch.hpp)

enable_testing()
add_test(test-problem08 problem08-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem08_submission.zip" --format=zip
       test_frequency.cpp Frequency.hpp Frequency.cpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})