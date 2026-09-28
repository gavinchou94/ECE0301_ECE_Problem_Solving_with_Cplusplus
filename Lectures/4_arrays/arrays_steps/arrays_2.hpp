// This is arrays_2.hpp
// Changes compared to arrays_starter.hpp:
// - Creates a display function.

#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>

void display(int[], int); // Learn the function prototype syntax here.

// Display each element in an array.
// When passing an array to a function, also pass the array size.
void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << std::endl;
  }
}

#endif