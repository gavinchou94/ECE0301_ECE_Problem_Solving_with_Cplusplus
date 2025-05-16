cmake_minimum_required(VERSION 3.10)
project(templates)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_templates.cpp SafeArray.hpp SafeArray.tpp
        SearchableArray.hpp SearchableArray.tpp
        UniqueArray.hpp UniqueArray.tpp
        Date.hpp Date.cpp
        catch.hpp)

add_executable(test_templates ${SOURCE})

enable_testing()

add_test(test_templates test_templates)