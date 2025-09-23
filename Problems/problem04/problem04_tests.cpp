#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <cmath>

#include "circuits.hpp"

TEST_CASE("Test Current", "[Circuits]")
{
    double resistance = 1000;
    double power = 2.5000;
    REQUIRE(get_current(resistance, power) == sqrt(power / resistance));
}

TEST_CASE("Test Resistance", "[Circuits]")
{
    double current = 0.05;
    double power = 2.5000;
    REQUIRE(get_resistance(current, power) == power / pow(current, 2));
}

TEST_CASE("Test Power", "[Circuits]")
{
    double current = 0.05;
    double resistance = 1000;
    REQUIRE(get_power(current, resistance) == pow(current, 2) * resistance);
}

TEST_CASE("Test getValue Parsing", "[Circuits]")
{
    std::string test_string = "R = 1000.0";
    REQUIRE(get_value(test_string) == 1000.0);
}