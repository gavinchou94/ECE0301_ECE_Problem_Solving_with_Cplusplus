// This is test_class_memory2.cpp
// Changes from test_class_memory1.cpp:
// - Tests reading elements with [].
// - Tests updating elements with [].

#define CATCH_CONFIG_MAIN

#include "SafeArray2.hpp"
#include "catch.hpp"

TEST_CASE("Test default construction", "[safearray]")
{
  SafeArray arr;
  REQUIRE(arr.get_size() == 0);
}

TEST_CASE("Test parameterized construction with overloading []", "[safearray]")
{
  int size = 5;
  SafeArray arr2(size);

  for (int i = 0; i < size; i++)
  {
    // REQUIRE(arr2.dataptr[i]==0); // Error: dataptr is private.
    REQUIRE(arr2[i] == 0); // Read this element through operator[].
  }
  REQUIRE(arr2.get_size() == 5);
}

TEST_CASE("Test overloading [] for modification purposes", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  arr[0] = 1; // Confirm arr[] can appear on the left side of an assignment.
  arr[1] = 4;

  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 4);
  REQUIRE(arr[2] == 0);
  REQUIRE(arr[3] == 0);
  REQUIRE(arr[4] == 0);

  REQUIRE_THROWS_AS(arr[-1], std::out_of_range);
  REQUIRE_THROWS_AS(arr[-1] = 5, std::out_of_range);

  // Uncomment these lines to test the compiler-generated copy constructor.
  // It shallow-copies dataptr, so the objects share one array.
  // Their destructors then delete the same array more than once, causing a segmentation fault.
  // Removing the destructor avoids the double delete but leaks the array.
  // A deep-copy constructor gives each object its own array.
  // SafeArray arr2(arr);
  // SafeArray arr3 = arr;

}

TEST_CASE("Test copy constructor and copy assignment operator with deep copying", "[safearray]")
{
}

TEST_CASE("Test non-member arithmetic operator overloading", "[safearray]")
{
}