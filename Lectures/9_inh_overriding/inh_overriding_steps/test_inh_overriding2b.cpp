// This is test_inh_overriding2b.cpp
// Changes from test_inh_overriding2.cpp:
// - Adds TrackedArray to demonstrate private inheritance, member initialization, and constructor and destructor order.

#define CATCH_CONFIG_MAIN

#include <iostream>

#include "SafeArray2.hpp"
#include "SearchableArray2.hpp"
#include "UniqueArray2.hpp"
#include "catch.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]")
{
  int size = 5;
  SafeArray arr(size);

  REQUIRE(arr.get_size() == size);
  for (int i = 0; i < size; i++)
  {
    arr.set(i, i);
    REQUIRE(arr.get(i) == i);
  }

  REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
  REQUIRE_THROWS_AS(arr.set(size, 0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]")
{
  int size = 5;
  SearchableArray arr(size); // use constructor inherited from SafeArray

  REQUIRE(arr.get_size() == 5);

  for (int i = 0; i < size; i++)
  {
    arr.set(i, i);            // inherited from base class
    REQUIRE(arr.get(i) == i); // inherited from base class
    REQUIRE(arr.search(i));   // derived class method
  }

  REQUIRE_FALSE(arr.search(-2));                         // derived class method
  REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test derived class constructor and destructor", "[inh]")
{
  // one more derived class: inheritance access, the member initializer list,
  // and the order of constructors and destructors
  class TrackedArray : private SafeArray
  {
  public:
    TrackedArray(int n) : SafeArray(n), count_of_zero(get_size()) // SafeArray(n) sets n zeros first
    {
      std::cout << "TrackedArray constructor" << std::endl;
    }

    ~TrackedArray() // runs first; ~SafeArray runs after it
    {
      std::cout << "TrackedArray destructor" << std::endl;
    }

    int get_count_of_zero() const { return count_of_zero; }

  private:
    int count_of_zero;
  };

  std::cout << "Testing order:" << std::endl;
  std::cout << "Build and destroy a TrackedArray:" << std::endl;
  {
    TrackedArray tarr(3);
    REQUIRE(tarr.get_count_of_zero() == 3); // the SafeArray part was built first
    // REQUIRE(tarr.get_size() == 3);       // private inheritance: SafeArray's public methods cannot be used here
  } // end of scope: ~TrackedArray runs, then ~SafeArray
}