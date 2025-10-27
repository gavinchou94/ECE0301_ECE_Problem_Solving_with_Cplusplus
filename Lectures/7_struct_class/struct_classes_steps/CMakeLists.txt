# This is new CMakeLists.txt
# changes from starter code:
# add a new executable and new test target

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(struct_and_class)
add_executable(test_vector test_vector.cpp catch.hpp)
# build a target called test_class for test_class_{1/2/3}.cpp: include four files
add_executable(test_class test_class_1.cpp Employee_1.hpp Employee_1.cpp catch.hpp)
# build a target called test_class for test_class_{4/4b/5/6/7}.cpp: include six files
#add_executable(test_class test_class_4.cpp Employee_4.hpp Employee_4.cpp Date_4.hpp Date_4.cpp catch.hpp)

enable_testing()

add_test(test-vector test_vector)
add_test(test-class test_class)