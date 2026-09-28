// This is test_arrays_2.cpp
// Changes compared to test_arrays_1.cpp:
// - Declares an array variable with a const int size.
// - Displays array elements using the display function in arrays_2.hpp.

#define CATCH_CONFIG_MAIN

#include "arrays_2.hpp"
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

TEST_CASE("Test array printing", "[array-printing]")
{
  // int dim=5; int arr[dim]={0,10,20,30,40}; //Variable-sized arrays may not be initialized.
  const int size = 5; // Size has to be a const int.
  int arr[size] = {0, 10, 20, 30, 40};

  display(arr, size);

  // std::cout << arr[5] << std::endl; // Print an out-of-bounds array element.
}