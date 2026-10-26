// This is a new test_class_1.cpp
// Note the following items:
// - inclusion of "Employee_1.hpp" header
// - REQUIRE statements to test object construction
#define CATCH_CONFIG_MAIN

#include "Employee_1.hpp"
#include "catch.hpp"

TEST_CASE("Class init", "[class]")
{
  Date d = {2026, 10, 21};
  Employee e1("Panther", 20, d); // declare an object called e1
  // e1 is constructed using () and args

  REQUIRE(e1.get_name() == "Panther");          // e1.name is not possible since it's outside class now
  REQUIRE(e1.get_hourly_rate() == 20);          // getter functions solve such problems
  REQUIRE(e1.get_starting_date().year == 2026); // struct cannot be directly compared via ==
  REQUIRE(e1.get_starting_date().month == 10);
  REQUIRE(e1.get_starting_date().day == 21);
}