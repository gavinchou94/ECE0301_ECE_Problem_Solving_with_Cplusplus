cmake_minimum_required(VERSION 3.14)
project(problem06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES problem06_tests.cpp)
set(HEADERS database.hpp constants.hpp)

add_executable(problem06_tests ${TEST_SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-problem06 COMMAND problem06_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem06.zip"
        --format=zip
        ${TEST_SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem06_submission.zip"
        --format=zip
        ${TEST_SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})