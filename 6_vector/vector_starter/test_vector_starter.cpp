#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector]") {
    //declare vector of type <int>, <double>
    std::vector<int> vec1;
    REQUIRE(true);
}