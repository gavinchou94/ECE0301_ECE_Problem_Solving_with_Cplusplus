// This is test_class_3.cpp
// Changes from test_class_2.cpp
// adding testing cases of some public functions

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Employee_3.hpp"

TEST_CASE("Class init", "[class]")
{
    Date d = {2025, 10, 20};
    Employee e1("Spiderman", 20, d); // declare an object called e1
    // e1 is constructed using () and args

    REQUIRE(e1.get_name() == "Spiderman");        // e1.name is not possible since it's outside class now
    REQUIRE(e1.get_hourly_rate() == 20);          // getter functions solve such problems
    REQUIRE(e1.get_starting_date().year == 2025); // struct cannot be directly compared via ==
    REQUIRE(e1.get_starting_date().month == 10);
    REQUIRE(e1.get_starting_date().day == 20);
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
    Date d = {2025, 5, 1};
    REQUIRE(e2.set_starting_date(d));

    // test the success of setter functions
    REQUIRE(e2.get_name() == "Tim");
    REQUIRE(e2.get_hourly_rate() == 15);
    REQUIRE(e2.get_starting_date().year == 2025);
    REQUIRE(e2.get_starting_date().month == 5);
    REQUIRE(e2.get_starting_date().day == 1);

    // test other public functions
    REQUIRE(e2.get_weekly_rate() == 15 * 70);
    REQUIRE(e2.get_yearly_rate() == 15 * 70 * 52);
}