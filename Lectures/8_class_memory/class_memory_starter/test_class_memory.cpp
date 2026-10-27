#define CATCH_CONFIG_MAIN

#include "SafeArray.hpp"
#include "catch.hpp"

TEST_CASE("Test default construction", "[safearray]")
{
  SafeArray arr;
}

TEST_CASE("Test parameterized construction with overloading []", "[safearray]")
{
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