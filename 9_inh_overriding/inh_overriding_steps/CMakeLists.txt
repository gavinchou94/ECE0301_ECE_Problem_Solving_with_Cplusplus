cmake_minimum_required(VERSION 3.5)
project(inh_overriding)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_inh_overriding1.cpp SafeArray1.hpp SafeArray1.cpp 
        SearchableArray.hpp SearchableArray.cpp
        UniqueArray.hpp UniqueArray.cpp
        catch.hpp)

add_executable(test_inh_overriding ${SOURCE})

enable_testing()

add_test(test-inh-overriding test_inh_overriding)