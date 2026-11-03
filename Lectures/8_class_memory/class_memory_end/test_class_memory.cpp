#define CATCH_CONFIG_MAIN

#include "SafeArray.hpp"
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

}

TEST_CASE("Test copy constructor and copy assignment operator with deep copying", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  arr[0] = 1;
  arr[1] = 4;

  SafeArray arr2(arr);  // arr2 uses copy construction.
  SafeArray arr3 = arr; // arr3 uses copy construction.
  SafeArray arr4(7);
  arr4 = arr3; // arr4 uses copy assignment.

  // Compare behavior with and without the custom copy-assignment operator.

  int test[] = {1, 4, 0, 0, 0};
  for (int i = 0; i < size; i++)
  {
    REQUIRE(arr2[i] == test[i]);
    REQUIRE(arr3[i] == test[i]); // Check the copy-constructor result.
    REQUIRE(arr4[i] == test[i]); // Check the copy-assignment result.
  }
  REQUIRE(arr4.get_size() == 5); // Check the copy-assignment result.

  arr[0] = 10; // Change arr to check that the copies remain unchanged.
  arr[1] = 40;

  for (int i = 0; i < size; i++)
  {
    REQUIRE(arr2[i] == test[i]); // Deep copy keeps arr2 unchanged when arr changes.
    REQUIRE(arr3[i] == test[i]); // Deep copy keeps arr3 unchanged when arr changes.
    REQUIRE(arr4[i] == test[i]); // Deep copy keeps arr4 unchanged when arr changes.
  }
}

TEST_CASE("Test non-member arithmetic operator overloading", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  arr[0] = 1;
  arr[1] = 4;

  SafeArray arr2 = arr + 100;
  SafeArray arr3 = 100 + arr;

  int test[] = {101, 104, 100, 100, 100};
  for (int i = 0; i < size; i++)
  {
    REQUIRE(arr2[i] == test[i]);
    REQUIRE(arr3[i] == test[i]);
  }
}