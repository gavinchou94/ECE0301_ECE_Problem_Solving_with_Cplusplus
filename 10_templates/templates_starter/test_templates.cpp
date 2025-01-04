#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"

TEST_CASE("Test default construction of SafeArray", "[template]") {
    SafeArray arr;
    REQUIRE(arr.get_size() == 0);
}