#define CATCH_CONFIG_MAIN

#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"
#include "catch.hpp"

TEST_CASE("Test default construction of SafeArray", "[template]")
{
  SafeArray arr;
  REQUIRE(arr.get_size() == 0);
}