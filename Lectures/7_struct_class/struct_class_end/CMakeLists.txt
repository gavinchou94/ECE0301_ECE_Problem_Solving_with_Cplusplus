cmake_minimum_required(VERSION 3.14)
project(struct_class_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES test_struct_class.cpp Employee.cpp Date.cpp)
set(HEADERS Employee.hpp Date.hpp)

add_executable(test_struct_class ${SOURCES} ${HEADERS} catch.hpp)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../struct_class_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})