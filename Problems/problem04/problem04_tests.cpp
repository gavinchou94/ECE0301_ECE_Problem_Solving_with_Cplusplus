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

TEST_CASE("Test get_current()", "[Circuits]")
{
    double resistance = 500;
    double power = 1.7500;
    REQUIRE(get_current(resistance, power) == sqrt(power / resistance));
}

TEST_CASE("Test get_resistance()", "[Circuits]")
{
    double current = 0.1;
    double power = 5.2500;
    REQUIRE(get_resistance(current, power) == power / pow(current, 2));
}

TEST_CASE("Test get_power()", "[Circuits]")
{
    double current = 0.25;
    double resistance = 1050;
    REQUIRE(get_power(current, resistance) == pow(current, 2) * resistance);
}
TEST_CASE("Test getValue()", "[Circuits]")
{
    std::string test_string = "R = 2500.0";
    REQUIRE(get_value(test_string) == 2500.0);
}
TEST_CASE("Test invalid getValue()", "[Circuits]")
{
    std::string invalid_string1 = "R = r";
    REQUIRE(get_value(invalid_string1) == -1);

    std::string invalid_string2 = "R  1500";
    REQUIRE(get_value(invalid_string2) == -1);
}
TEST_CASE("Test negative get_current()", "[Circuits]")
{
    double resistance = -500;
    double power = -1.7500;
    if (resistance < 0)
    {
        REQUIRE(get_current(resistance, power) == -1);
    }
    else if (power < 0)
    {
        REQUIRE(get_current(resistance, power) == -1);
    }
    else
    {
        REQUIRE(get_current(resistance, power) == sqrt(power / resistance));
    }
}

TEST_CASE("Test negative get_resistance()", "[Circuits]")
{
    double current = -0.1;
    double power = -5.2500;
    if (current < 0)
    {
        REQUIRE(get_resistance(current, power) == -1);
    }
    else if (power < 0)
    {
        REQUIRE(get_resistance(current, power) == -1);
    }
    else
    {
        REQUIRE(get_resistance(current, power) == power / pow(current, 2));
    }
}

TEST_CASE("Test negative get_power()", "[Circuits]")
{
    double current = -0.25;
    double resistance = -1050;
    if (current < 0)
    {
        REQUIRE(get_power(current, resistance) == -1);
    }
    else if (resistance < 0)
    {
        REQUIRE(get_power(current, resistance) == -1);
    }
    else
    {
        REQUIRE(get_power(current, resistance) == pow(current, 2) * resistance);
    }
}
TEST_CASE("Test divider_power()", "[Circuits]")
{
    double resistance1 = 500, resistance2 = 1000;
    double source_power = 2.5000;
    REQUIRE(get_divider_power(source_power, resistance1, resistance2) == source_power * (resistance2 / (resistance1 + resistance2)));
}

TEST_CASE("Test invalid divider_power()", "[Circuits]")
{
    double resistance1 = -250, resistance2 = -2000;
    double source_power = -1.3000;
    if (resistance1 < 0)
    {
        REQUIRE(get_divider_power(source_power, resistance1, resistance2) == -1);
    }
    else if (resistance2 < 0)
    {
        REQUIRE(get_divider_power(source_power, resistance1, resistance2) == -1);
    }
    else if (source_power < 0)
    {
        REQUIRE(get_divider_power(source_power, resistance1, resistance2) == -1);
    }
    else
    {
        REQUIRE(get_divider_power(source_power, resistance1, resistance2) == source_power * (resistance2 / (resistance1 + resistance2)));
    }
}