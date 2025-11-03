#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray.hpp"
#include "SearchableArray.hpp"
#include "UniqueArray.hpp"

TEST_CASE("Test SafeArray size construction and access using []", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i=0; i<size; i++) {
        arr[i]=i;
        REQUIRE(arr[i] == i);
    }

    REQUIRE_THROWS_AS(arr[size], std::out_of_range);
    REQUIRE_THROWS_AS(arr[size]=0, std::out_of_range);
}