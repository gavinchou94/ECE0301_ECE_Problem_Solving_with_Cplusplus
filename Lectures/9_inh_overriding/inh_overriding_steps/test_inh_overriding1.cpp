// This is test_inh_overriding1.cpp
// Changes from test_inh_overriding.cpp (starter):
// - Tests get() and set() in place of operator[].

#define CATCH_CONFIG_MAIN

#include "SafeArray1.hpp"
#include "SearchableArray1.hpp"
#include "UniqueArray1.hpp"
#include "catch.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  REQUIRE(arr.get_size() == size);
  for (int i = 0; i < size; i++)
  {
    arr.set(i, i);
    REQUIRE(arr.get(i) == i);
  }

  REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
  REQUIRE_THROWS_AS(arr.set(size, 0), std::out_of_range);
}