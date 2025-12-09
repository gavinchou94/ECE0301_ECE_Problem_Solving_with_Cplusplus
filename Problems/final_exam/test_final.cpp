#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>

#include "catch.hpp"
#include "Final.hpp"

TEST_CASE("Your Final Exam test case 1", "[final]")
{
    int course = 301;
    int course_copy = 201 + 100;
    std::cout << "Good luck with Final Exam of ECE " << course << std::endl;
    REQUIRE(course == course_copy);
}

TEST_CASE("Your Final Exam test case 2", "[final]")
{
    Final_v1 obj1;
    REQUIRE(obj1.some_func() == 0);

    Final_v2<std::string> obj2;
    REQUIRE(obj2.another_func() == ""); // Default value of std::string is ""

    // object of abstract class type "Final_v3" is not allowed:
    // Final_v3 obj3;
}