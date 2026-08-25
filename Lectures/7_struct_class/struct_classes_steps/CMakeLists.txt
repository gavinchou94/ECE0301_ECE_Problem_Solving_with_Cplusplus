cmake_minimum_required(VERSION 3.14)
project(struct_classes_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS catch.hpp
    Employee_1.hpp Employee_1.cpp test_class_1.cpp
    # Employee_2.hpp Employee_2.cpp test_class_2.cpp
    # Employee_3.hpp Employee_3.cpp test_class_3.cpp
    # Employee_4.hpp Employee_4.cpp Date_4.hpp Date_4.cpp test_class_4.cpp
    # Employee_4.hpp Employee_4.cpp Date_4.hpp Date_4.cpp test_class_4b.cpp
    # Employee_5.hpp Employee_5.cpp Date_5.hpp Date_5.cpp test_class_5.cpp
    # Employee_6.hpp Employee_6.cpp Date_6.hpp Date_6.cpp test_class_6.cpp
    # Employee_7.hpp Employee_7.cpp Date_7.hpp Date_7.cpp test_class_7.cpp
)

add_executable(test_struct_classes ${STEPS})

enable_testing()
add_test(NAME test-struct-classes COMMAND test_struct_classes)