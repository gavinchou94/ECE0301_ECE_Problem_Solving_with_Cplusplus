cmake_minimum_required(VERSION 3.14)
project(arrays_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS arrays.hpp catch.hpp constants.hpp)

set(SOURCES test_arrays.cpp)

add_executable(test_arrays ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-arrays COMMAND test_arrays)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/arrays_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})