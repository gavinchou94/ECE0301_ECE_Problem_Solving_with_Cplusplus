// This is test_vector_3.cpp
// Changes compared to test_vector_2.cpp:
// - Adds examples of changing vector size with push_back() and pop_back().

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

TEST_CASE("Vector init with size", "[vector-size]")
{
  std::vector<int> vec1(3); // vector size is initialized with ()
  REQUIRE(vec1.size() == 3);
  REQUIRE_FALSE(vec1.empty());

  // In an initialized but not assigned array, data content is undefined
  // but an initialized but not assigned vector object has default content 0
  for (int i = 0; i < vec1.size(); i++)
  {
    REQUIRE(vec1[i] == 0);
  }

  // same as array, [] is used in vector to access/update indexed content
  vec1[0] = 1;
  vec1[1] = 4;
  vec1[2] = 9;

  REQUIRE(vec1[0] == 1);
  REQUIRE(vec1[1] == 4);
  REQUIRE(vec1[2] == 9);

  // two more ways to declare: a size and a fill value, or a copy of another vector
  std::vector<int> vec2(3, 7); // 3 elements, each holding 7
  REQUIRE(vec2[2] == 7);
  std::vector<int> vec3(vec1); // vec3 starts as a copy of vec1
  REQUIRE(vec3[2] == 9);
}

TEST_CASE("Vector updating size via push and pop", "[vector-update]")
{
  std::vector<int> vec1;
  // vec1[0]=4; // this would run into bad-access error since vec1 is still empty
  REQUIRE(vec1.empty());

  // Unlike array, vector object can be easily modified in terms of size
  // no need to start a new vector object
  vec1.push_back(1); // push_back(?) appends one element at the end of vector object
  REQUIRE(vec1.size() == 1);
  REQUIRE(vec1[0] == 1);

  vec1.push_back(4); // push_back(?) can continue modifying vector object
  REQUIRE(vec1.size() == 2);
  REQUIRE(vec1[0] == 1);
  REQUIRE(vec1[1] == 4);

  vec1.pop_back(); // pop_back() removes one element at the end of vector object, no arg required
  REQUIRE(vec1.size() == 1);
  vec1.pop_back();
  REQUIRE(vec1.empty());
  // vec1.pop_back(); // This would run into error when trying to pop_back an empty vector
}