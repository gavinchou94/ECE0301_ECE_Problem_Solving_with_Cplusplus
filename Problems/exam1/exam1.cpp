#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "exam1.hpp"

// Use this section when writing Catch2 tests.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("Your Exam 1 test case 1", "[exam1]")
{
    // Placeholder test.
    int course = 301;
    int course_copy = 201 + 100;
    std::cout << "Good luck with ECE " << course << std::endl;
    REQUIRE(course == course_copy);
}
TEST_CASE("Your Exam 1 test case 2", "[exam1]")
{
    // Placeholder test.
}

// Use this section when writing a regular program instead of Catch2 tests.
// int main()
// {
//   std::cout << "Good luck!" << std::endl;
//   return 0;
// }