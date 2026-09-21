cmake_minimum_required(VERSION 3.14)
project(problem04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_SOURCES problem04.cpp)
set(TEST_SOURCES problem04_tests.cpp)
set(HEADERS circuits.hpp)

add_executable(problem04_main ${MAIN_SOURCES} ${HEADERS})
add_executable(problem04_tests ${TEST_SOURCES} ${HEADERS} catch.hpp)
add_executable(compare_files compare_files.cpp)

enable_testing()
add_test(NAME test-problem04 COMMAND problem04_tests)
add_test(NAME file-input COMMAND problem04_main ${CMAKE_SOURCE_DIR}/tests/input.txt output.txt)
add_test(NAME file-input-compare COMMAND compare_files ${CMAKE_SOURCE_DIR}/tests/output.txt output.txt)
add_test(NAME file-test-input COMMAND problem04_main ${CMAKE_SOURCE_DIR}/tests/test_input.txt test_output.txt)
add_test(NAME file-test-input-compare COMMAND compare_files ${CMAKE_SOURCE_DIR}/tests/test_output.txt test_output.txt)
set_tests_properties(file-input file-input-compare file-test-input file-test-input-compare PROPERTIES RUN_SERIAL TRUE)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem04.zip"
        --format=zip
        ${MAIN_SOURCES} ${TEST_SOURCES} compare_files.cpp ${HEADERS} catch.hpp CMakeLists.txt tests/*
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem04_submission.zip"
        --format=zip
        ${MAIN_SOURCES} ${TEST_SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})