cmake_minimum_required(VERSION 3.14)
project(header_test_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HEADERS catch.hpp shapes.hpp)

set(SOURCES test_shapes.cpp)

add_executable(test_header_test ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-header-test COMMAND test_header_test)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/header_test_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})