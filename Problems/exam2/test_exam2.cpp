#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "catch.hpp"
#include "Exam2.hpp"

TEST_CASE("Your Exam 2 test case", "[exam2]")
{
    int course = 301;
    int course_copy = 201 + 100;
    int exam = 201 / 100;
    std::cout << "Good luck with ECE " << course;
    std::cout << " Exam " << exam << std::endl;
    REQUIRE(course == course_copy);

    SampleClass sample;
    sample.displayMessage();
}