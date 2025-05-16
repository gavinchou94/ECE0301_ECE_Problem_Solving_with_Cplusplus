// This is final version of test_class.cpp
// Clear comments from test_class_7.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Employee.hpp"

TEST_CASE("Class init", "[class]") {
    Date d(2024, OCT, 21); // change to declare an Date object called d
    Employee e1("Ryan", 25, d); // declare an object called e1
    // e1 is constructed using () and args

    REQUIRE(e1.get_name() == "Ryan");
    REQUIRE(e1.get_hourly_rate() == 25);
    REQUIRE(e1.get_starting_date().get_year() == 2024);
    REQUIRE(e1.get_starting_date().get_month() == OCT);
    REQUIRE(e1.get_starting_date().get_month() == 10);
    REQUIRE(e1.get_starting_date().get_day() == 21);

}

TEST_CASE("Class init without info", "[class]") {
    Employee e2; // declare an object called e2 without passing any information

    // test the default attribute of the object e2
    REQUIRE(e2.get_name() == "");
    REQUIRE(e2.get_hourly_rate() == 0);
    REQUIRE(e2.get_starting_date().get_year() == 1900);
    REQUIRE(e2.get_starting_date().get_month() == JAN);
    REQUIRE(e2.get_starting_date().get_day() == 1);

    // use setter functions to modify object attributes
    REQUIRE(e2.set_name("Panther"));
    REQUIRE(e2.set_hourly_rate(1));
    Date d(2024, AUG, 31);
    REQUIRE(e2.set_starting_date(d));

   // test the success of setter functions
    REQUIRE(e2.get_name() == "Panther");
    REQUIRE(e2.get_hourly_rate() == 1);
    REQUIRE(e2.get_starting_date().get_year() == 2024);
    REQUIRE(e2.get_starting_date().get_month() == AUG);
    REQUIRE(e2.get_starting_date().get_day() == 31);

    // test other public functions
    REQUIRE(e2.get_weekly_rate() == 1*70);
    REQUIRE(e2.get_yearly_rate() == 1*70*52);
}

TEST_CASE("Class set date", "[class]"){
    Date start(2024,OCT,23);
    REQUIRE(start.get_year()==2024);
    REQUIRE(start.get_month()==OCT);
    REQUIRE(start.get_day()==23);
    start.set_year(1985);
    start.set_month(JAN);
    start.set_day(1);
    REQUIRE(start.get_year()==1985);
    REQUIRE(start.get_month()==JAN);
    REQUIRE(start.get_day()==1);
}

TEST_CASE("Class set year validation", "[class]"){

    Date start(2024,OCT,23);
    REQUIRE_THROWS_AS(start.set_year(1700),std::invalid_argument);
    REQUIRE_NOTHROW(start.set_year(1901));

    REQUIRE_THROWS_AS(Date d(1500, JAN, 1),std::invalid_argument);
    REQUIRE_NOTHROW(Date d(2020, JAN, 1));
}

TEST_CASE("Class test operator ==", "[class]"){
    Date start(1985,JAN,1);
    Date start2(1985,JAN,1);
    REQUIRE(start.operator==(start2));
    REQUIRE(start==start2); // both statements are good
}

TEST_CASE("Class test non-member operator <", "[class]"){
    Date start(1985,OCT,10);
    Date end1(1990,MAR,3);
    Date end2(1985,NOV,1);
    Date end3(1985,OCT,31);
    REQUIRE(start<end1);
    // REQUIRE(start.operator<(end1)); // this statement would run into error
    REQUIRE(start<end2);
    REQUIRE(start<end3);
    REQUIRE_FALSE(start<start);
}