cmake_minimum_required(VERSION 3.14)
project(0_hello_world)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES hello_world_cmake.cpp)

add_executable(hello_world_cmake ${SOURCES})

enable_testing()
add_test(NAME test-hello-world-cmake COMMAND test_hello_world_cmake)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../0_hello_world.zip"
        --format=zip
        ${SOURCES} CMakeLists.txt hello_world.cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})