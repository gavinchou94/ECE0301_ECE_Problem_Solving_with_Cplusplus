cmake_minimum_required(VERSION 3.10)
project(problem04)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(problem04-main problem04.cpp circuits.hpp)
add_executable(problem04-tests problem04_tests.cpp circuits.hpp catch.hpp)
add_executable(compare-files compare_files.cpp)

enable_testing()

add_test(test-problem04 problem04-tests)
add_test(NAME file-input COMMAND problem04-main ${CMAKE_SOURCE_DIR}/tests/input.txt output.txt)
add_test(NAME file-input-compare COMMAND compare-files ${CMAKE_SOURCE_DIR}/tests/output.txt output.txt)
add_test(NAME file-test_input COMMAND problem04-main ${CMAKE_SOURCE_DIR}/tests/test_input.txt test_output.txt)
add_test(NAME file-test_input-compare COMMAND compare-files ${CMAKE_SOURCE_DIR}/tests/test_output.txt test_output.txt)
set_tests_properties(file-input file-input-compare file-test_input file-test_input-compare PROPERTIES RUN_SERIAL TRUE)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem04.zip" --format=zip
       problem04.cpp problem04_tests.cpp circuits.hpp
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})