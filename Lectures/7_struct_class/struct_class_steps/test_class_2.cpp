// This is test_class_2.cpp
// Changes compared to test_class_1.cpp:
// - adding testing cases of default constructor without arg info
// - adding testing cases of setter functions
#define CATCH_CONFIG_MAIN

#include "Employee_2.hpp"
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

TEST_CASE("Class init without info", "[class]")
{
  Employee e2; // declare an object called e2 without passing any information

  // test the default attribute of the object e2
  REQUIRE(e2.get_name() == "");
  REQUIRE(e2.get_hourly_rate() == 0);
  REQUIRE(e2.get_starting_date().year == 1900);
  REQUIRE(e2.get_starting_date().month == 1);
  REQUIRE(e2.get_starting_date().day == 1);

  // use setter functions to modify object attributes
  REQUIRE(e2.set_name("Tim"));
  REQUIRE(e2.set_hourly_rate(15));
  Date d = {2026, 5, 1};
  REQUIRE(e2.set_starting_date(d));

  // test the success of setter functions
  REQUIRE(e2.get_name() == "Tim");
  REQUIRE(e2.get_hourly_rate() == 15);
  REQUIRE(e2.get_starting_date().year == 2026);
  REQUIRE(e2.get_starting_date().month == 5);
  REQUIRE(e2.get_starting_date().day == 1);
}