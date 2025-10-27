// This is final version of test_class.cpp
// Clear comments from test_class_7.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Employee.hpp"

TEST_CASE("Class init", "[class]")
{
    Date d(2025, OCT, 20);           // change to declare an Date object called d
    Employee e1("Spiderman", 20, d); // declare an object called e1
    // e1 is constructed using () and args

    REQUIRE(e1.get_name() == "Spiderman");              // e1.name is not possible since it's outside class now
    REQUIRE(e1.get_hourly_rate() == 20);                // getter functions solve such problems
    REQUIRE(e1.get_starting_date().get_year() == 2025); // struct cannot be directly compared via ==
    REQUIRE(e1.get_starting_date().get_month() == OCT); // either ==OCT or ==10 is fine
    REQUIRE(e1.get_starting_date().get_day() == 20);
}

TEST_CASE("Class init without info", "[class]")
{
    Employee e2; // declare an object called e2 without passing any information

    // test the default attribute of the object e2
    REQUIRE(e2.get_name() == "");
    REQUIRE(e2.get_hourly_rate() == 0);
    REQUIRE(e2.get_starting_date().get_year() == 1900);
    REQUIRE(e2.get_starting_date().get_month() == 1);
    REQUIRE(e2.get_starting_date().get_day() == 1);

    // use setter functions to modify object attributes
    REQUIRE(e2.set_name("Tim"));
    REQUIRE(e2.set_hourly_rate(15));
    Date d = {2025, MAY, 1};
    REQUIRE(e2.set_starting_date(d));

    // test the success of setter functions
    REQUIRE(e2.get_name() == "Tim");
    REQUIRE(e2.get_hourly_rate() == 15);
    REQUIRE(e2.get_starting_date().get_year() == 2025);
    REQUIRE(e2.get_starting_date().get_month() == 5); // either ==MAY or ==5 is fine
    REQUIRE(e2.get_starting_date().get_day() == 1);

    // test other public functions
    REQUIRE(e2.get_weekly_rate() == 15 * 70);
    REQUIRE(e2.get_yearly_rate() == 15 * 70 * 52);
}

TEST_CASE("Class set date", "[class]")
{
    Date start(2025, OCT, 22);
    REQUIRE(start.get_year() == 2025);
    REQUIRE(start.get_month() == 10);
    REQUIRE(start.get_day() == 22);
    start.set_year(1985);
    start.set_month(JAN);
    start.set_day(1);
    REQUIRE(start.get_year() == 1985);
    REQUIRE(start.get_month() == 1);
    REQUIRE(start.get_day() == 1);
}

TEST_CASE("Class set year validation", "[class]")
{
    Date start(2025, OCT, 22);
    REQUIRE_THROWS_AS(start.set_year(1700), std::invalid_argument);
    REQUIRE_NOTHROW(start.set_year(1901));

    REQUIRE_THROWS_AS(Date d(1500, JAN, 1), std::invalid_argument);
    REQUIRE_NOTHROW(Date d(2020, JAN, 1));
}

TEST_CASE("Class test operator ==", "[class]")
{
    Date start_day(1985, JAN, 1);
    Date start_day2(1985, JAN, 1);
    REQUIRE(start_day.operator==(start_day2));
    REQUIRE(start_day == start_day2); // both statements are good
}

TEST_CASE("Class test non-member operator <", "[class]")
{
    Date start(1985, OCT, 10);
    Date end1(1990, MAR, 3);
    Date end2(1985, NOV, 1);
    Date end3(1985, OCT, 31);
    REQUIRE(start < end1);
    // REQUIRE(start.operator<(end1)); // this statement would run into error
    // because operator< is non-member function, cannot be called via member-function way
    REQUIRE(start < end2);
    REQUIRE(start < end3);
    REQUIRE_FALSE(start < start);
}

TEST_CASE("Class enum is internally stored as int", "[class]")
{
    Date d(2025, OCT, 27);
    REQUIRE(d.get_month() == 10); // enum MONTH is stored as int internally
    REQUIRE(JAN == 1);
    REQUIRE(MAR == 3);
    REQUIRE(JAN + 4 == MAY);
}