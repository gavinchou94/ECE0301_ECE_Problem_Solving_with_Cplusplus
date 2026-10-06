cmake_minimum_required(VERSION 3.14)
project(pointers_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES test_pointers.cpp)
set(HEADERS pointers.hpp)

add_executable(test_pointers ${SOURCES} ${HEADERS} catch.hpp)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../pointers_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})