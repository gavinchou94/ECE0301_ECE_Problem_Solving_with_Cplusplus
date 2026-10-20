cmake_minimum_required(VERSION 3.14)
project(problem07)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES problem07_tests.cpp)
set(SOURCES Database.cpp)
set(HEADERS Database.hpp)

add_executable(problem07_tests ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-problem07 COMMAND problem07_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem07.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem07_submission.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})