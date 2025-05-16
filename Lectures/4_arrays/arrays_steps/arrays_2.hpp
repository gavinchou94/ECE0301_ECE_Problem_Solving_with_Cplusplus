// This is arrays_2.hpp
// Changes from arrays_starter.hpp:
// create a display function

#ifndef _ARRAYS_HPP
#define _ARRAYS_HPP

#include <iostream>

// display each element in an array
// when passing arr to functions, always pass size of array too!
void display(int arr[], int size) // learn the function prototype syntax here
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

#endif