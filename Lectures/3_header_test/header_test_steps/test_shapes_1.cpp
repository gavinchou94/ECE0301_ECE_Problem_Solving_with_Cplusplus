// This is test_shapes_1A.cpp
// Changes from test_shapes of starter code
// 1. Test conversion instead of calculating area
// 2. Test both valid and invalid inputs
// 3. include "shapes_1A.hpp" header

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "shapes_1.hpp" // this is needed due to conversion

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