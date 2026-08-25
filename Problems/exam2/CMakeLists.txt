cmake_minimum_required(VERSION 3.14)
project(exam2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exam2 test_exam2.cpp Exam2.hpp Exam2.cpp catch.hpp)

enable_testing()
add_test(test-exam2 exam2)