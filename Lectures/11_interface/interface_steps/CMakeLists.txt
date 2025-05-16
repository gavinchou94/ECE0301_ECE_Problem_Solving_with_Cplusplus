cmake_minimum_required(VERSION 3.10)
project(interface)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_interface1a.cpp SafeArray1.hpp SafeArray1.tpp
	SearchableArray.hpp SearchableArray.tpp
        UniqueArray.hpp UniqueArray.tpp
        Date.hpp Date.cpp
        Array.hpp
        catch.hpp)

add_executable(test_interface ${SOURCE})

enable_testing()

add_test(test-interface test_interface)