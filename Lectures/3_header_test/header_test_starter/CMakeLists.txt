cmake_minimum_required(VERSION 3.14)
project(header_test_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES header_test_starter.cpp)
set(HEADERS )

add_executable(header_test_starter ${SOURCES})

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../header_test_starter.zip"
        --format=zip
        ${SOURCES} test_shapes.cpp catch.hpp CMakeLists.txt input.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})