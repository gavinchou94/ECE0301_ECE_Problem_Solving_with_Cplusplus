// This is test_shapes_3.cpp
// Changes from test_shapes_2.cpp
// 1. test function passing by value vs passing by reference
// 2. std::cout inside and outside the functions (passed by value) to see the difference
// 3. test function with default argument

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "shapes_3.hpp"

TEST_CASE("Test Conversion", "[conversion]")
{
    std::string test_input = "a = 3.15";
    double expected_output = 3.15;
    double actual_output = conversion(test_input);
    REQUIRE(actual_output == expected_output);

    REQUIRE(conversion("t = 412") == 412);
}

TEST_CASE("Test Conversion Invalid Input", "[conversion]")
{
    REQUIRE(conversion("t + 412") == -1); // missing '='
    REQUIRE(conversion("t = xyz") == -1); // invalid string for stod conversion
}

TEST_CASE("Test Area Circle with Overloaded Functions", "[area]")
{
    REQUIRE(area(1) == M_PI * 1.0 * 1.0); // area of circle with r = 1

    double w = 3.0, l = 6.0;
    REQUIRE(area(w, l) == 18.0); // area of rectangle with w = 3, l = 6

    double a = 3.0, b = 4.0, sinC = 0.5;
    REQUIRE(area(a, b, sinC) == 3); // area of triangle with a = 3, b = 4, sinC = 0.5

    float c = 5.0;               // 3,4,5 makes a right triangle, area = 0.5*3*4=6
    REQUIRE(area(a, b, c) == 6); // calling double area(double a, double b, float c)

    c = 8.0; // make a triangle with a=3,b=4,c=8, which is invalid
    REQUIRE(area(a, b, c) == -1);

    int x = 7, y = 24, z = 25;    // 7,24,25 makes a right triangle, area = 0.5*7*24=84
    REQUIRE(area(x, y, z) == 84); // calling double area(int a, int b, int c)
}

TEST_CASE("Test Area with Floating Number Comparisons", "[area]")
{
    double a = 1.0;
    double threshold = 1e-3;
    double result = 3.14159 * 1.0 * 1.0;
    REQUIRE(std::abs(result - area(a)) <= threshold);
}

TEST_CASE("Test sum function with passing by value", "[sum]")
{
    int a = 301;
    int b = 1;
    REQUIRE(sum(a, b) == 302);
    std::cout << "a outside the sum function is " << a << std::endl;
}

TEST_CASE("Test sum2 function with passing by reference", "[sum2]")
{
    int a = 301;
    int b = 1;
    REQUIRE(sum2(a, b) == 302);
    std::cout << "a outside the sum2 function is " << a << std::endl;
}

TEST_CASE("Test Area with Default Argument", "[area_with_default_side]")
{
    double w = 5.0;
    REQUIRE(area_with_default_side(w) == 50.0); // l will take default value of 10.0

    double l = 6.0;
    REQUIRE(area_with_default_side(w, l) == 30.0); // l will take provided value of 6.0
}