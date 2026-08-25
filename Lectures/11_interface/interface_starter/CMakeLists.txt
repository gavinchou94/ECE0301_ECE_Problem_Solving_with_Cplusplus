cmake_minimum_required(VERSION 3.14)
project(interface_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    Array.hpp
    Date.hpp
    SafeArray.hpp SafeArray.tpp
    SearchableArray.hpp SearchableArray.tpp
    UniqueArray.hpp UniqueArray.tpp
    catch.hpp
)

set(SOURCES test_interface.cpp Date.cpp)

add_executable(test_interface ${SOURCES} ${HEADERS})
enable_testing()
add_test(NAME test-interface COMMAND test_interface)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/interface_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})