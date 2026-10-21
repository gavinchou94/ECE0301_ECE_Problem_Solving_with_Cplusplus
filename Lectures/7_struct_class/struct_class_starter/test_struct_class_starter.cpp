#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "Employee.hpp"

TEST_CASE("test class", "[class]")
{
  Employee e1;
  REQUIRE(e1.get_hourly_paid() == 0);
  REQUIRE(e1.get_name() == "");
  REQUIRE(e1.get_starting_date().day == 1);
  REQUIRE(e1.get_starting_date().month == 1);
  REQUIRE(e1.get_starting_date().year == 1900);

  e1.set_name("Tim");
  e1.set_hourly_paid(20);
  Date d{2026, 2, 28};
  e1.set_starting_date(d);
  REQUIRE(e1.get_hourly_paid() == 20);
  REQUIRE(e1.get_name() == "Tim");
  REQUIRE(e1.get_starting_date().day == 28);
  REQUIRE(e1.get_starting_date().month == 2);
  REQUIRE(e1.get_starting_date().year == 2026);

  // Test the struct
  REQUIRE(d.day == 28);
  REQUIRE(d.month == 2);
  REQUIRE(d.year == 2026);

  REQUIRE(e1.get_weekly_paid() == 20 * 40);
  REQUIRE(e1.get_yearly_paid() == 20 * 40 * 52);
}