cmake_minimum_required(VERSION 3.14)
project(exam1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES exam1.cpp)
set(HEADERS exam1.hpp)

add_executable(exam1_tests ${TEST_SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-exam1 COMMAND exam1_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../exam1.zip"
        --format=zip
        ${TEST_SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})