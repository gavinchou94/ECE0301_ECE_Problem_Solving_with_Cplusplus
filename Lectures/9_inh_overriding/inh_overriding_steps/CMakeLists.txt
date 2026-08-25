cmake_minimum_required(VERSION 3.14)
project(inh_overriding_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    SafeArray1.hpp SafeArray1.cpp SearchableArray1.hpp SearchableArray1.cpp UniqueArray1.hpp UniqueArray1.cpp test_inh_overriding1.cpp
    # SafeArray2.hpp SafeArray2.cpp SearchableArray2.hpp SearchableArray2.cpp UniqueArray2.hpp UniqueArray2.cpp test_inh_overriding2.cpp
    # SafeArray3.hpp SafeArray3.cpp SearchableArray3.hpp SearchableArray3.cpp UniqueArray3.hpp UniqueArray3.cpp test_inh_overriding3.cpp
    # SafeArray3.hpp SafeArray3.cpp SearchableArray3.hpp SearchableArray3.cpp UniqueArray3.hpp UniqueArray3.cpp test_inh_overriding3b.cpp
    # SafeArray3.hpp SafeArray3.cpp SearchableArray3.hpp SearchableArray3.cpp UniqueArray3.hpp UniqueArray3.cpp test_inh_overriding3c.cpp
    # SafeArray3.hpp SafeArray3.cpp SearchableArray3.hpp SearchableArray3.cpp UniqueArray3.hpp UniqueArray3.cpp test_inh_overriding3d.cpp
    # SafeArray4.hpp SafeArray4.cpp SearchableArray4.hpp SearchableArray4.cpp UniqueArray4.hpp UniqueArray4.cpp test_inh_overriding4.cpp
)

add_executable(test_inh_overriding ${STEPS})

enable_testing()
add_test(NAME test-inh-overriding COMMAND test_inh_overriding)