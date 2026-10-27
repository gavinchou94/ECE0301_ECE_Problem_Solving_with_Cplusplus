cmake_minimum_required(VERSION 3.14)
project(problem08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES test_frequency.cpp)
set(SOURCES Frequency.cpp)
set(HEADERS Frequency.hpp)

add_executable(problem08_tests ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-problem08 COMMAND problem08_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem08.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS} read_freq_plot.m catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem08_submission.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})