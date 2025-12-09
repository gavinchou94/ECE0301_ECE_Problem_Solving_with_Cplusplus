cmake_minimum_required(VERSION 3.10)
project(interface)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_interface1c.cpp SafeArray1.hpp SafeArray1.tpp
	SearchableArray1.hpp SearchableArray1.tpp
        UniqueArray1.hpp UniqueArray1.tpp
        Date.hpp Date.cpp
        Array1.hpp
        catch.hpp)

add_executable(test_interface ${SOURCE})

enable_testing()

add_test(test-interface test_interface)