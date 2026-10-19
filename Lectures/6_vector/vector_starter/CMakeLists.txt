cmake_minimum_required(VERSION 3.14)
project(vector_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES test_vector_starter.cpp)
set(HEADERS)

add_executable(test_vector ${SOURCES} ${HEADERS} catch.hpp)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../vector_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})