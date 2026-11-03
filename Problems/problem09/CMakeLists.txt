cmake_minimum_required(VERSION 3.14)
project(problem09)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES test_image.cpp)
set(SOURCES Image.cpp)
set(HEADERS Image.hpp)

add_executable(problem09_tests ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-problem09 COMMAND problem09_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem09.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS} bitmap.hpp smiley.bmp bonus_test.bmp catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem09_submission.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})