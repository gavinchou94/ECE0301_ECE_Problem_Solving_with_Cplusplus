// This is test_inh_overriding1.cpp
// Changes from starter code of test_inh_overriding.cpp
// 1. changing to testing get() and set(), instead of []

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray1.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i=0; i<size; i++) {
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
}