cmake_minimum_required(VERSION 3.14)
project(shape_func_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES shape_func_starter.cpp)
set(HEADERS )

add_executable(test_shape_func ${SOURCES})

enable_testing()
add_test(NAME test-shape-func COMMAND test_shape_func)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/shape_func_starter.zip"
        --format=zip
        ${SOURCES} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})