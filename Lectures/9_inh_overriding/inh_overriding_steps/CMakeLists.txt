cmake_minimum_required(VERSION 3.10)
project(inh_overriding)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# change to SafeArrayX.hpp and SafeArrayX.cpp to see different steps
# match names with child class names and test_inh_overridingX.cpp
set(SOURCE test_inh_overriding4.cpp SafeArray4.hpp SafeArray4.cpp 
        SearchableArray4.hpp SearchableArray4.cpp
        UniqueArray4.hpp UniqueArray4.cpp
        catch.hpp)

add_executable(test_inh_overriding ${SOURCE})

enable_testing()

add_test(test-inh-overriding test_inh_overriding)