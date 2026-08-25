cmake_minimum_required(VERSION 3.14)
project(templates_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    Date.hpp
    SafeArray.hpp SafeArray.tpp
    SearchableArray.hpp SearchableArray.tpp
    UniqueArray.hpp UniqueArray.tpp
    catch.hpp
)

set(SOURCES Date.cpp test_templates.cpp)

add_executable(test_templates ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-templates COMMAND test_templates)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/templates_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})