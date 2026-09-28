// This is arrays_4.hpp
// Changes compared to arrays_2.hpp:
// - Creates swap functions for arrays and strings.
// - Shows the difference between passing by value and passing by reference.

#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>

void display(int[], int); // Learn the function prototype syntax here.
void swap(int[], int, int);
void swap(std::string &, int, int);

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

#endif