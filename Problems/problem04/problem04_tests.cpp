#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>

#include "circuits.hpp"

TEST_CASE("Test Current", "[Circuits]")
{
    double resistance = 1000;
    double voltage = 5.000;
    REQUIRE(get_current(resistance, voltage) == voltage / resistance);
}

TEST_CASE("Test Resistance", "[Circuits]")
{
    double current = 0.005;
    double voltage = 5.000;
    REQUIRE(get_resistance(current, voltage) == voltage / current);
}

TEST_CASE("Test Voltage", "[Circuits]")
{
    double current = 0.005;
    double resistance = 1000;
    REQUIRE(get_voltage(current, resistance) == current * resistance);
}

TEST_CASE("Test getValue Parsing", "[Circuits]")
{
    std::string test_string = "R = 1000.0";
    REQUIRE(get_value(test_string) == 1000.0);
}