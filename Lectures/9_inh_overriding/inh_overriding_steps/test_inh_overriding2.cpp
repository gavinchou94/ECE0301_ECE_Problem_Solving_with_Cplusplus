// This is test_inh_overriding2.cpp
// Changes from test_inh_overriding1.cpp
// 1. add test cases of inheritance
// 2. methods of base class and derived class are both available 

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray2.hpp"
#include "SearchableArray2.hpp"
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

TEST_CASE("Test inheritance and search", "[inh]") {
    int size = 5;
    SearchableArray arr(size);

    REQUIRE(arr.get_size()==5);

    for (int i=0; i<size; i++){
        arr.set(i,i);                  // inherited from base class 
        REQUIRE(arr.get(i)==i);        // inherited from base class
        REQUIRE(arr.search(i));        // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));     // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}