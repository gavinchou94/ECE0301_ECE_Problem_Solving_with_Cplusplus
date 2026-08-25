cmake_minimum_required(VERSION 3.14)
project(vector_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS catch.hpp)

set(SOURCES test_vector_starter.cpp)

add_executable(test_vector ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-vector COMMAND test_vector)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/vector_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})