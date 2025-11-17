cmake_minimum_required(VERSION 3.10)
project(templates)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_templates.cpp SafeArray.hpp SafeArray.cpp
        SearchableArray.hpp SearchableArray.cpp
        UniqueArray.hpp UniqueArray.cpp
        catch.hpp)

add_executable(test_templates ${SOURCE})

enable_testing()

add_test(test_templates test_templates)