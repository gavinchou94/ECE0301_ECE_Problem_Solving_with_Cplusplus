cmake_minimum_required(VERSION 3.14)
project(problem09)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem09-tests test_image.cpp bitmap.hpp Image.hpp Image.cpp catch.hpp)

enable_testing()
add_test(test-problem09 problem09-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem09_submission.zip" --format=zip
       test_image.cpp Image.hpp Image.cpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})