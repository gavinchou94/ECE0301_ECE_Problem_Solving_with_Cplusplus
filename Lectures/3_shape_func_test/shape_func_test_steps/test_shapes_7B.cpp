// This is test_shapes_7B.cpp
// Changes from test_shapes_7A.cpp
// add more TEST_CASE to test conversion, invalid-conversion, triangle/rectangle area

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

TEST_CASE("Test Invalid Conversion", "[invalid-conversion]")
{
    std::string test_input = "abcd";
    double expected_output = -1;
    double actual_output = conversion(test_input);

    REQUIRE(actual_output == expected_output);
}

TEST_CASE("Test Triangle Area", "[triangle-area]")
{
    double test_input_1 = 3, test_input_2 = 4, test_input_3 = 90;
    double expected_output = 6;
    double actual_output = area(test_input_1, test_input_2, test_input_3);

    REQUIRE(actual_output == expected_output);
}

TEST_CASE("Test Rectangle Area", "[rectangle-area]")
{
    double test_input_1 = 3, test_input_2 = 4;
    double expected_output = 12;
    double actual_output = area(test_input_1, test_input_2);

    REQUIRE(actual_output == expected_output);
}