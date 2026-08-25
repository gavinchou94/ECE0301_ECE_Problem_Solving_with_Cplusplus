cmake_minimum_required(VERSION 3.14)
project(templates_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    SafeArray1.hpp SafeArray1.tpp SearchableArray1.hpp SearchableArray1.cpp UniqueArray1.hpp UniqueArray1.cpp test_templates1.cpp
    # SafeArray2.hpp SafeArray2.tpp SearchableArray2.hpp SearchableArray2.tpp UniqueArray2.hpp UniqueArray2.tpp test_templates2a.cpp
    # SafeArray2.hpp SafeArray2.tpp SearchableArray2.hpp SearchableArray2.tpp UniqueArray2.hpp UniqueArray2.tpp test_templates2b.cpp
    # SafeArray2.hpp SafeArray2.tpp SearchableArray2.hpp SearchableArray2.tpp UniqueArray2.hpp UniqueArray2.tpp Date2c.hpp Date2c.cpp test_templates2c.cpp
)

add_executable(test_templates ${STEPS})

enable_testing()
add_test(NAME test-templates COMMAND test_templates)