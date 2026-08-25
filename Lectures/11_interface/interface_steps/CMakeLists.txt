cmake_minimum_required(VERSION 3.14)
project(interface_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp Date.hpp Date.cpp Array1.hpp SafeArray1.hpp SafeArray1.tpp SearchableArray1.hpp SearchableArray1.tpp UniqueArray1.hpp UniqueArray1.tpp
    test_interface1a.cpp
    # test_interface1b.cpp
    # test_interface1c.cpp
)

add_executable(test_interface ${STEPS})

enable_testing()
add_test(NAME test-interface COMMAND test_interface)