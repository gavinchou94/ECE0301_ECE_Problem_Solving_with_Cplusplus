cmake_minimum_required(VERSION 3.14)
project(inh_overriding_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS SafeArray.hpp SearchableArray.hpp UniqueArray.hpp catch.hpp)

set(SOURCES SafeArray.cpp SearchableArray.cpp UniqueArray.cpp test_inh_overriding.cpp)

add_executable(test_inh_overriding ${SOURCES} ${HEADERS})

enable_testing()
add_test(NAME test-inh-overriding COMMAND test_inh_overriding)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/inh_overriding_end.zip"
        --format=zip
        ${SOURCES} ${HEADERS} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})