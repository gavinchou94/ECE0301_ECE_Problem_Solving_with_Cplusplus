#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector-empty]")
{
    // declare vector of type <int>, <double>
    std::vector<int> vec1;

    // without any modifier after vec1, it is initialized as empty
    REQUIRE(vec1.empty());
    REQUIRE(vec1.size() == 0);
}

TEST_CASE("Vector init with size", "[vector-size]")
{
}

TEST_CASE("Vector updating size via push and pop", "[vector-update]")
{
}

TEST_CASE("Vector insert and erase", "[vector-insert-erase]")
{
}

TEST_CASE("Vector indexing via []", "[vector-index]")
{
}

TEST_CASE("Vector indexing via at", "[vector-index]")
{
}

TEST_CASE("Vector of other data type and ADT", "[vector-ADT]")
{
}