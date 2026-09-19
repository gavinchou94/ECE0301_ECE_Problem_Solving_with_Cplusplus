// This is test_shapes_1.cpp
// Changes compared to test_shapes.cpp from the starter code:
// - Tests conversion instead of calculating area.
// - Tests both valid and invalid inputs.
// - Includes the shapes_1.hpp header.

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>

#include "catch.hpp"
#include "shapes_1.hpp" // Needed to test conversion.

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