#define CATCH_CONFIG_MAIN

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

// Uncomment this part if doing catch test
#include "catch.hpp"
#include "exam1.hpp"
TEST_CASE("Your Exam 1 test cases", "[exam1]")
{
    // just a placeholder
    int course = 301;
    int course_copy = 201 + 100;
    std::cout << "Good luck with ECE " << course << std::endl;
    REQUIRE(course == course_copy);
}

// Uncomment this part if doing regular coding
// int main(){
//     cout << "Good luck!" << endl;
//     return 0;
// }