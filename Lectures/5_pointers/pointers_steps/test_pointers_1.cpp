// This is test_pointers_1.cpp
// Changes compared to test_pointers_starter.cpp:
// - Adds test cases for pointer basics and stack vs. dynamic arrays.
// - Declares arrays using pointers and dynamically allocated memory.

#define CATCH_CONFIG_MAIN

#include <iostream>

#include "catch.hpp"

TEST_CASE("Test pointer basics in stack memory", "[ptr-stack]")
{
  int a = 5;                                             // normal int variable
  int *a_ptr = &a;                                       // a_ptr borrows a: it holds a's address but owns nothing
  std::cout << "a_ptr prints: " << a_ptr << std::endl;   // this will be a hex address
  std::cout << "*a_ptr prints: " << *a_ptr << std::endl; // use dereference to get the value of a

  int *another_ptr = &a;                  // another pointer variable pointing to a
  (*a_ptr)++;                             // using * on ptr is same as a itself, so this increments a by 1
  std::cout << *a_ptr << std::endl;       // should be 6
  std::cout << *another_ptr << std::endl; // should also be 6
  std::cout << a << std::endl;            // should also be 6

  // a lives on the stack and cleans up itself;
  // a_ptr borrowed it, so there is nothing to delete

  int fix_arr[3] = {10, 20, 30};     // an array name "fix_arr" is fixed to its own memory
  std::cout << fix_arr << std::endl; // the name reads as an address
  fix_arr[0]++;                      // {11, 20, 30}
  fix_arr[1]++;                      // {11, 21, 30}, since fix_arr[n] is equivalent to *(fix_arr + n)

  int other_arr[3] = {1, 2, 3};
  // fix_arr = other_arr; // error: invalid array assignment, the array name cannot be re-pointed
  int *p = fix_arr; // p borrows fix_arr; p now points to first element of fix_arr
  p = other_arr;    // fine since the pointer can move, the array name cannot.
  p[0]++;           // increments other_arr[0] to 2

  // To summarize: the pointer holds an address; the array name is an address.
}

TEST_CASE("Test pointer and array initialization in dynamic memory", "[ptr-dynamic]")
{
  int *b_ptr = new int(7);                                   // b_ptr owns one unnamed int in dynamic memory
  std::cout << "b_ptr prints: " << b_ptr << std::endl;       // this will be a hex address
  std::cout << "*b_ptr prints: " << *b_ptr << std::endl;     // dereference b_ptr to get the owned value

  int *another_ptr = b_ptr;                  // another_ptr points to the same int as b_ptr
  (*b_ptr)++;                                // dereference b_ptr and increment the owned int
  std::cout << *b_ptr << std::endl;          // should be 8
  std::cout << *another_ptr << std::endl;    // should also be 8

  // The unnamed int lives in dynamic memory and does not clean up itself;
  // b_ptr owns it, so b_ptr must eventually delete it

  int size = 5;
  int *arr = new int[size]{0, 1, 2, 3, 4};  // arr owns a dynamic array whose size is known at run time
                                            // Here, size is a variable evaluated at run time.
                                            // Recall that a fixed array on the stack must have a const size declarator.
                                            // int fix_arr[size] = {0, 1, 2, 3, 4}; // cannot compile
  std::cout << arr << std::endl;            // the pointer holds the address of its first element
  arr[0]++;                                 // {1, 1, 2, 3, 4}
  arr[1]++;                                 // {1, 2, 2, 3, 4}, since arr[n] is equivalent to *(arr + n)

  int *arr2 = new int[size]{1, 2, 3, 4, 5}; // arr2 owns a different dynamic array
  // arr = arr2; // legal, but bad: arr would lose access to its owned content
  int *p = arr; // p borrows arr; p now points to the first element of arr
  p = arr2;     // fine since a pointer can move; arr still owns its original allocation
  p[0]++;       // increments arr2[0] to 2
  p[0]--;       // undo it, so arr2 is {1, 2, 3, 4, 5} again

  // To summarize: b_ptr owns one int; arr and arr2 each own a dynamic array.

  int *arr3;            // create another pointer
  arr3 = new int[size]; // This pointer links to (also owns) a different dynamically allocated array without initialization
                        // add a breakpoint in above line to view arr3 as a pointer (hex address)

  for (int i = 0; i < size; i++)
  {
    arr3[i] = i + 1;
    REQUIRE(arr3[i] == i + 1);
  } // assign arr3 content; using a dynamic array is almost the same as using a fixed array

  double *db_ptr = new double(3.14);
  double *db_arr_ptr = new double[3]{3.14, 3.15, 3.16};
}