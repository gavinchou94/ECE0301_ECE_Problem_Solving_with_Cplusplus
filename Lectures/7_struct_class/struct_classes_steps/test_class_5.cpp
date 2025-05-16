// This is test_class_5.cpp
// Changes from test_class_4b.cpp
// 1. test throw exception of setting year

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Employee_5.hpp"

TEST_CASE("Class init", "[class]") {
    Date d(2024, 10, 21); // change to declare an Date object called d
    Employee e1("Ryan", 25, d); // declare an object called e1
    // e1 is constructed using () and args

    REQUIRE(e1.get_name() == "Ryan"); // e1.name is not possible since it's outside class now
    REQUIRE(e1.get_hourly_rate() == 25); //getter functions solve such problems
    REQUIRE(e1.get_starting_date().get_year() == 2024); // struct cannot be directly compared via ==
    REQUIRE(e1.get_starting_date().get_month() == 10);
    REQUIRE(e1.get_starting_date().get_day() == 21);

}

TEST_CASE("Class init without info", "[class]") {
    Employee e2; // declare an object called e2 without passing any information

    // test the default attribute of the object e2
    REQUIRE(e2.get_name() == "");
    REQUIRE(e2.get_hourly_rate() == 0);
    REQUIRE(e2.get_starting_date().get_year() == 1900);
    REQUIRE(e2.get_starting_date().get_month() == 1);
    REQUIRE(e2.get_starting_date().get_day() == 1);

    // use setter functions to modify object attributes
    REQUIRE(e2.set_name("Panther"));
    REQUIRE(e2.set_hourly_rate(1));
    Date d(2024, 8, 31);
    REQUIRE(e2.set_starting_date(d));

   // test the success of setter functions
    REQUIRE(e2.get_name() == "Panther");
    REQUIRE(e2.get_hourly_rate() == 1);
    REQUIRE(e2.get_starting_date().get_year() == 2024);
    REQUIRE(e2.get_starting_date().get_month() == 8);
    REQUIRE(e2.get_starting_date().get_day() == 31);

    // test other public functions
    REQUIRE(e2.get_weekly_rate() == 1*70);
    REQUIRE(e2.get_yearly_rate() == 1*70*52);
}

TEST_CASE("Class set date", "[class]"){
    Date start(2024,10,23);
    REQUIRE(start.get_year()==2024);
    REQUIRE(start.get_month()==10);
    REQUIRE(start.get_day()==23);
    start.set_year(1985);
    start.set_month(1);
    start.set_day(1);
    REQUIRE(start.get_year()==1985);
    REQUIRE(start.get_month()==1);
    REQUIRE(start.get_day()==1);
}

TEST_CASE("Class set year validation", "[class]"){

    Date start(2024,10,23);
    REQUIRE_THROWS_AS(start.set_year(1700),std::invalid_argument);
    REQUIRE_NOTHROW(start.set_year(1901));

    REQUIRE_THROWS_AS(Date d(1500, 1, 1),std::invalid_argument);
    REQUIRE_NOTHROW(Date d(2020, 1, 1));
}