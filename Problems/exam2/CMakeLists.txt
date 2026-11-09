cmake_minimum_required(VERSION 3.14)
project(exam2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES test_exam2.cpp)
set(SOURCES Exam2.cpp)
set(HEADERS Exam2.hpp)

add_executable(exam2_tests ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp)

enable_testing()
add_test(NAME test-exam2 COMMAND exam2_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../exam2.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})