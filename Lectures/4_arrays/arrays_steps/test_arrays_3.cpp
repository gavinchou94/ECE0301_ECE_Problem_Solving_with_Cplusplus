// This is test_arrays_3.cpp
// Changes compared to test_arrays_2.cpp:
// - Tests consecutive array addresses and out-of-bounds access.

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
  // int dim=5; int arr[dim]={0,10,20,30,40}; //Variable-sized objects may not be initialized.
  const int size = 5; // Size has to be a const int.
  int arr[size] = {0, 10, 20, 30, 40};

  display(arr, size);

  // std::cout << arr[5] << std::endl; // Print an out-of-bounds array element.
}

TEST_CASE("Test array addressing", "[array-addressing]")
{
  const int size = 5;
  int arr[size] = {0, 10, 20, 30, 40};

  // Take a look at how arr is stored in memory.
  std::cout << arr << std::endl;     // print a hexadecimal addr for first element, supposing X
  std::cout << arr[0] << std::endl;  // print the first element, which is 0
  std::cout << &arr[0] << std::endl; // print the addr of the first element, '&' is the addr symbol, shall be X
  std::cout << arr[1] << std::endl;  // print the second element, which is 10
  std::cout << &arr[1] << std::endl; // print the addr of the second element, shall be X+4 (since size(int)=4)

  double arr_d[2] = {10.0, 20.0};
  std::cout << &arr_d[0] << " " << &arr_d[1] << std::endl; // print two address

  // std::cout << arr[8] <<std::endl;   // arr[8] won't give error, but arr[8] accesses data that is illegal
}