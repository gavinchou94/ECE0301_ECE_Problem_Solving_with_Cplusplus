// This is arrays_6.hpp
// Changes compared to arrays_5.hpp:
// - Implements 1D array search by comparing elements one by one.
// - Implements 2D array search with nested for-loops.
// - Uses COLS from constants.hpp.

#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>

#include "constants.hpp"

void display(int[], int); // Learn the function prototype syntax here.
void swap(int[], int, int);
void swap(std::string &, int, int);
void copy(const int[], int[], int);
bool search(const int[], int, int);
bool search2D(const int[][COLS], int, int);

// Display each element in an array.
// When passing an array to a function, also pass the array size.
void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << std::endl;
  }
}

// Swap two elements in an array.
void swap(int arr[], int idx1, int idx2)
{
  int temp = arr[idx1]; // A temp variable is necessary for exchanging values.
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
}

// Swap two characters in a string by modifying the original string.
// Including the '&' symbol passes the string by reference.
// It passes the address of the string variable.
// Comment out the version above and uncomment the one below to see passing by value.
void swap(std::string &str, int idx1, int idx2)
{
  char temp = str[idx1];
  str[idx1] = str[idx2];
  str[idx2] = temp;
}
// void swap(std::string str, int idx1, int idx2) // Swap two characters and get a new string, i.e., passing by value.
//{
//     char temp = str[idx1];
//     str[idx1] = str[idx2];
//     str[idx2] = temp;
//     std::cout << "My string within this function is now: "
//               << str << std::endl; // only the copy is modified within the function, as a local variable.
// }

// for copy, the first argument is set to be const to prevent modification
// values in arrfrom can be accessed, but not modified
// if we made the second argument also const, the compiler will throw an error because arrto elements are modified
void copy(const int arrfrom[], int arrto[], int size)
{
  for (int i = 0; i < size; i++)
  {
    arrto[i] = arrfrom[i]; // the copy function itself just duplicates element value one by one
  }
}

// search if any element in arr[] equals to val using a linear for-loop
// size has to be passed to this search function
// arr[] is const since it won't be modified
bool search(const int arr[], int val, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == val)
    {
      return true;
    }
  }
  return false;
}

// search if any element in 2D array equals to val
// 2D array (matrix) arguments must have the num at the second bracket provided, it's the maximum matrix column allowed.
// We defined COLS in constants.hpp to make sure that COLS is consistent across all
bool search2D(const int mat[][COLS], int val, int rows)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < COLS; c++)
    {
      if (mat[r][c] == val)
      {
        return true;
      }
    }
  }
  return false;
}

#endif