cmake_minimum_required(VERSION 3.14)
project(header_test_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_SOURCES header_test_starter.cpp)
set(TEST_SOURCES test_shapes.cpp)
set(HEADERS )

add_executable(test_main ${MAIN_SOURCES} ${HEADERS})
add_executable(test_shapes ${TEST_SOURCES} ${HEADERS} catch.hpp)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../header_test_starter.zip"
        --format=zip
        ${MAIN_SOURCES} ${TEST_SOURCES} catch.hpp CMakeLists.txt input.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})