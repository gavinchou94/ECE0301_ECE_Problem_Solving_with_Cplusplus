cmake_minimum_required(VERSION 3.14)
project(inh_overriding_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES test_inh_overriding.cpp SafeArray.cpp SearchableArray.cpp UniqueArray.cpp)
set(HEADERS SafeArray.hpp SearchableArray.hpp UniqueArray.hpp)

add_executable(test_inh_overriding ${SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-inh-overriding COMMAND test_inh_overriding)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../inh_overriding_starter.zip"
        --format=zip
        ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})