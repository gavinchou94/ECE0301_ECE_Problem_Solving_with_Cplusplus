// This is test_shapes_7A.cpp
// Changes from test_shapes of starter code
// 1. change TEST_CASE to test conversion
// 2. include "shapes_7.hpp" header
// Test default Cmake debug to make test_shapes the target, not launch.json
// Review results in debug console

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "shapes_7.hpp" // this is needed due to conversion

TEST_CASE("Test Conversion", "[conversion]")
{
    std::string test_input = "4.5";
    double expected_output = 4.5;
    double actual_output = conversion(test_input);

    REQUIRE(actual_output == expected_output);
}