#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shapes.hpp"

TEST_CASE("Test conversion")
{
    REQUIRE(conversion("a = 3.15") == 3.15);
    REQUIRE(conversion("t = 412") == 412);
    REQUIRE(conversion("t + 412") == -1);
    REQUIRE(conversion("t = xyz") == -1);
}

TEST_CASE("Test overloaded functions: area")
{
    double a = 1.0;
    double threshold = 1e-3;
    double result = 3.14159 * 1.0 * 1.0;
    REQUIRE(std::abs(result - area(a)) <= threshold);

    double w = 3, l = 6;
    REQUIRE(area(w, l) == 18.0);

    a = 3.0;
    double b = 4.0;
    double sinC = 0.5;
    REQUIRE(area(a, b, sinC) == 3.0);

    a = 3.0;
    b = 4.0;
    float c = 5.0;
    REQUIRE(area(a, b, c) == 6.0);
}

TEST_CASE("Test sum function with passing by value")
{
    int a = 301;
    int b = 1;
    REQUIRE(sum(a, b) == 302);
    std::cout << "a outside the sum function is " << a << std::endl;
}

TEST_CASE("Test sum2 function with passing by ref")
{
    int a = 301;
    int b = 1;
    REQUIRE(sum2(a, b) == 302);
    std::cout << "a outside the sum2 function is " << a << std::endl;
}

TEST_CASE("Test functions with default arguments and global variable")
{
    double a = 1.0;
    REQUIRE(area(a) == M_PI);

    double w = 3, l = 6;
    REQUIRE(area(w, l) == 18.0);

    REQUIRE(area_with_default_side(w) == 30.0);

    int x = 3, y = 4, z = 5;
    REQUIRE(calculations(x, y, z) == true);
}