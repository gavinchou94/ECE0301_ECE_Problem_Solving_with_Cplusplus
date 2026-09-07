cmake_minimum_required(VERSION 3.14)
project(problem02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(problem02 problem02.cpp)

if(EXISTS "${PROJECT_SOURCE_DIR}/problem02_bonus.cpp")
    add_executable(problem02_bonus problem02_bonus.cpp)
endif()

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem02.zip"
        --format=zip
        problem02.cpp problem02_bonus.cpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})