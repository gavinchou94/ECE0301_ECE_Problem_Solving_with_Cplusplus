# This is new CMakeLists.txt
# changes from starter code:
# add a new executable and new test target

cmake_minimum_required(VERSION 3.5)
project(vec_and_class)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_vector test_vector.cpp catch.hpp)
# build a target called test_class for test_class_{1/2/3}.cpp: include four files
add_executable(test_class test_class_1.cpp Employee_1.hpp Employee_1.cpp catch.hpp)
# build a target called test_class for test_class_{4/4b/5/6/7}.cpp: include six files
#add_executable(test_class test_class_7.cpp Employee_7.hpp Employee_7.cpp Date_7.hpp Date_7.cpp catch.hpp)

enable_testing()

add_test(test-vector test_vector)
add_test(test-class test_class)