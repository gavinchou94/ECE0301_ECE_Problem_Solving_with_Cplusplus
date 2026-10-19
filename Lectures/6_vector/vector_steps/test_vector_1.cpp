// This is test_vector_1.cpp
// Changes compared to test_vector_starter.cpp:
// - Adds tests for an empty vector and its size.

#define CATCH_CONFIG_MAIN

#include <vector> // this header file has to be included

#include "catch.hpp"

TEST_CASE("Vector init", "[vector-empty]")
{
  // declare vector of type <int>, <double>
  std::vector<int> vec1;

  // without any modifier after vec1, it is initialized as empty
  REQUIRE(vec1.empty());     // empty() function returns false/true
  REQUIRE(vec1.size() == 0); // vector has size() function that returns an int
}