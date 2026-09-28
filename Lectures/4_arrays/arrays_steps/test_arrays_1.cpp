// This is test_arrays_1.cpp
// Changes compared to test_arrays_starter.cpp:
// - Declares an array variable and verifies its indexing.

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

TEST_CASE("Test array indexing", "[array-index]")
{
  // int arr[]; // Not allowed, size is not specified.
  // int arr[] = {0,10,20,30,40}; // Size is inferred
  // int arr[4] = {0,10,20,30,40}; // Bad example, mismatched size.
  // int arr[5]; // Valid but uninitialized.
  int arr[5] = {0, 10, 20, 30, 40}; // Make sure the initializer matches the size.

  // One way to test indexing one by one.
  // REQUIRE(arr[0]==0);
  // REQUIRE(arr[1]==10);
  // REQUIRE(arr[2]==20);
  // REQUIRE(arr[3]==30);
  // REQUIRE(arr[4]==40);

  // Another way to test indexing using a for-loop.
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(arr[i] == 10 * i);
  }

  // int test = arr[5]; // Test access out of bounds; this is undefined behavior.
}