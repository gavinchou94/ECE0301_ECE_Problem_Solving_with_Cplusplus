// This is test_shapes_4.cpp
// Changes compared to test_shapes_3.cpp:
// - Tests the function stub and global variable.
// - Shows that the global variable is shared within the same TEST_CASE across multiple function calls.

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>

#include "catch.hpp"
#include "shapes_4.hpp"

TEST_CASE("An example description", "[tag]")
{
  std::cout << "Hello from Catch2!" << std::endl;
}

TEST_CASE("Test Conversion", "[conversion]")
{
   //  if (conversion("t = 412") == 412)
   // {
   //   std::cout << "Test passed, we are good to go!" << std::endl;
   // }
  REQUIRE(conversion("t = 412") == 412);
  REQUIRE(conversion("a = 3.15") == 3.15);

  // The line above is compact but harder to debug because it uses a nested function call.
  std::string test_input = "a = 3.15";
  double expected_output = 3.15;
  double actual_output = conversion(test_input); // Good place to add a breakpoint.
  REQUIRE(actual_output == expected_output);
}

TEST_CASE("Test Conversion Invalid Input", "[conversion]")
{
  REQUIRE(conversion("t + 412") == -1); // Missing '='.
  REQUIRE(conversion("t = xyz") == -1); // Invalid string for stod conversion.
}

TEST_CASE("Test Area Circle with Overloaded Functions", "[area]")
{
  REQUIRE(area(1) == M_PI * 1.0 * 1.0);

  double w = 3.0, l = 6.0;
  REQUIRE(area(w, l) == 18.0);

  double a = 3.0, b = 4.0, sinC = 0.5;
  REQUIRE(area(a, b, sinC) == 3); // Two sides and one angle version.

  float c = 5.0;               // 3, 4, 5 makes a right triangle, area = 0.5 * 3 * 4 = 6.
  REQUIRE(area(a, b, c) == 6); // Three sides as real numbers.

  c = 8;   // Make a triangle with a = 3, b = 4, c = 8, which is invalid.
  REQUIRE(area(a, b, c) == -1); // Three sides as real numbers, invalid triangle.

  c = 0.5;
  double c_double = static_cast<double>(c);
  REQUIRE(area(a, b, c_double) == 3); // Two sides and one angle version again.

  int x = 7, y = 24, z = 25;    // 7, 24, 25 makes a right triangle, area = 0.5 * 7 * 24 = 84.
  REQUIRE(area(x, y, z) == 84); // Three sides as integers.
}

TEST_CASE("Test Area with Floating Number Comparisons", "[area]")
{
  double a = 1.0;
  double threshold = 1e-6; // Define a threshold for floating-point comparison.
  double result = 3.1415926 * 1.0 * 1.0;
  REQUIRE(std::abs(result - area(a)) <= threshold);
}

TEST_CASE("Test Area with Default Argument", "[area_with_default_side]")
{
  double w = 5.0;
  REQUIRE(std::abs(area_with_default_side(w) - 5.0 * 10.0) <= 1e-6);

  double l = 6.0;
  REQUIRE(std::abs(area_with_default_side(w, l) - 5.0 * 6.0) <= 1e-6);
}

TEST_CASE("Test sum1 function with passing by value", "[sum]")
{
  int a = 201;
  int b = 1;
  std::string subject = "CE";
  REQUIRE(sum1(a, b, subject) == 202);
  std::cout << "Outside the sum1 function (pass by value): " << subject << a << std::endl;
}

TEST_CASE("Test sum2 function with passing by reference", "[sum2]")
{
  int a = 201;
  int b = 1;
  std::string subject = "CE";
  REQUIRE(sum2(a, b, subject) == 202);
  std::cout << "Outside the sum2 function (pass by reference): " << subject << a << std::endl;
}

TEST_CASE("Test append function", "[append]")
{
  int a = 201;
  int b = 1;
  std::string subject = "CE";
  REQUIRE(append(a, b, subject) == "ECE");
  // Although subject changes inside the function scope through the caller's copy,
  // this function returns subject so the caller can overwrite the old value.
  subject = append(a, b, subject);
  std::cout << "Outside the append function: " << subject << a << std::endl;
}

TEST_CASE("Test calc function stub and GLOBAL variable", "[calc]")
{
  int x = 3, y = 4, z = 5;
  REQUIRE(calc(x, y, z) == true); // Only test whether it returns true.
  // std::cout << "Try to print a" << std::endl;

  REQUIRE(calc(6, 7, 8) == true);
  if (calc(9, 10, 11) == true)
  {
    std::cout << "Calculation result is true" << std::endl;
  }
}