// This is a new test_class_memory1.cpp
// This version:
// - Tests the constructors and get_size().
// - Notes that the stored elements cannot be checked yet.

#define CATCH_CONFIG_MAIN

#include "SafeArray1.hpp"
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
    // REQUIRE(arr2[i]==0);         // Error: operator[] has not been added yet.
  }
  REQUIRE(arr2.get_size() == 5);
}

TEST_CASE("Test overloading [] for modification purposes", "[safearray]")
{
}

TEST_CASE("Test copy constructor and copy assignment operator with deep copying", "[safearray]")
{
}

TEST_CASE("Test non-member arithmetic operator overloading", "[safearray]")
{
}