cmake_minimum_required(VERSION 3.14)
project(class_memory_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS SafeArray.hpp catch.hpp)

set(SOURCES SafeArray.cpp test_class_memory.cpp)

add_executable(test_class_memory ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-class-memory COMMAND test_class_memory)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/class_memory_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})