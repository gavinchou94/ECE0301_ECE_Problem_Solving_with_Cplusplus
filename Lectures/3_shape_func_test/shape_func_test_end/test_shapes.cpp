// This is final version of test_shapes.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include "shapes.hpp" // this is needed due to conversion
#include <cmath> // due to abs calculation

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

// This test would fail due to floating numbers
TEST_CASE("Test Circle Area", "[circle-area]")
{
    double test_input = 3.9;
    double expected_output = 3.1415*3.9*3.9;
    double actual_output = area(test_input);

    REQUIRE(actual_output == expected_output);
}

// This test can pass
TEST_CASE("Test Circle Area Error Margin", "[circle-area-error]")
{
    double test_input = 3.9;
    double expected_output = 3.1415*3.9*3.9;
    double actual_output = area(test_input);
    double threshold = 1e-2;

    REQUIRE(std::abs(actual_output-expected_output)<=threshold);
}

// This test would fail due to floating number of sin(30)
TEST_CASE("Test Triangle Area Floating", "[triangle-area-floating]")
{
    double test_input_1 = 3.0, test_input_2 = 4.0, test_input_3 = 30.0;
    double expected_output = 3.0;
    double actual_output = area(test_input_1, test_input_2, test_input_3);

    REQUIRE(actual_output == expected_output);
}

// This test can pass
TEST_CASE("Test Triangle Area Error Margin", "[triangle-area-error]")
{
    double test_input_1 = 3.0, test_input_2 = 4.0, test_input_3 = 30.0;
    double expected_output = 3.0;
    double actual_output = area(test_input_1, test_input_2, test_input_3);
    double threshold = 1e-2;

    REQUIRE(std::abs(actual_output-expected_output)<=threshold);
}
