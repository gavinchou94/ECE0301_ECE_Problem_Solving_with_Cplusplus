cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(templates)
set(SOURCE test_templates1.cpp SafeArray1.hpp SafeArray1.tpp
        SearchableArray1.hpp SearchableArray1.cpp
        UniqueArray1.hpp UniqueArray1.cpp
        catch.hpp)

# set(SOURCE test_templates2a.cpp SafeArray2.hpp SafeArray2.tpp
#         SearchableArray2.hpp SearchableArray2.tpp
#         UniqueArray2.hpp UniqueArray2.tpp
#         catch.hpp)

# set(SOURCE test_templates2b.cpp SafeArray2.hpp SafeArray2.tpp
#         SearchableArray2.hpp SearchableArray2.tpp
#         UniqueArray2.hpp UniqueArray2.tpp
#         catch.hpp)

# set(SOURCE test_templates2c.cpp SafeArray2.hpp SafeArray2.tpp
#         SearchableArray2.hpp SearchableArray2.tpp
#         UniqueArray2.hpp UniqueArray2.tpp
#         Date2c.hpp Date2c.cpp
#         catch.hpp)

add_executable(test_templates ${SOURCE})

enable_testing()

add_test(test_templates test_templates)