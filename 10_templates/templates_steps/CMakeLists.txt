cmake_minimum_required(VERSION 3.10)
project(templates)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE test_templates1.cpp SafeArray.hpp SafeArray.tpp
        SearchableArray1.hpp SearchableArray1.cpp
        UniqueArray1.hpp UniqueArray1.cpp
        Date.hpp Date.cpp
        catch.hpp)

# set(SOURCE test_templates2a.cpp SafeArray.hpp SafeArray.tpp
#         SearchableArray2.hpp SearchableArray2.tpp
#         UniqueArray2.hpp UniqueArray2.tpp
#         Date.hpp Date.cpp
#         catch.hpp)

add_executable(test_templates ${SOURCE})

enable_testing()

add_test(test_templates test_templates)