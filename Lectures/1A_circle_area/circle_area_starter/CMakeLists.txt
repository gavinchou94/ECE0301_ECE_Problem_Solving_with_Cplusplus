cmake_minimum_required(VERSION 3.14)
project(circle_area_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES circle_area_starter.cpp)
set(HEADERS )

add_executable(test_circle_area ${SOURCES})

enable_testing()
add_test(NAME test-circle-area COMMAND test_circle_area)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../circle_area_starter.zip"
        --format=zip
        ${SOURCES} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})