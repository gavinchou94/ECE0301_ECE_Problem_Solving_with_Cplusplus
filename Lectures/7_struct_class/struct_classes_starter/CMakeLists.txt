cmake_minimum_required(VERSION 3.14)
project(struct_classes_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS catch.hpp)

set(SOURCES test_vector.cpp)

add_executable(test_struct_classes ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-struct-classes COMMAND test_struct_classes)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/struct_classes_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})