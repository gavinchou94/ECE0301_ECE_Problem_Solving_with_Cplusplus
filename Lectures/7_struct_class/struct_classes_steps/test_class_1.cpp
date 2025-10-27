// This is a new test_class_1.cpp
// Note the following items:
// 1. inclusion of "Employee_1.hpp" header
// 2. REQUIRE statements to test object construction

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Employee_1.hpp"

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