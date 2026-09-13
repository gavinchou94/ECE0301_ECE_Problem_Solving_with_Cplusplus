cmake_minimum_required(VERSION 3.14)
project(problem03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem03 problem03.cpp)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem03.zip"
        --format=zip
        problem03.cpp CMakeLists.txt input.txt test_input.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})