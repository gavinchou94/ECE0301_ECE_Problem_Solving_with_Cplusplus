// This is arrays_5.hpp
// Changes from arrays_4.hpp:
// implement the array copy function

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

// swap two elements in an array
void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1]; // a temp variable is always necessary for exchanging values
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// swap two chars in a string in a directly modified manner
// including the '&' symbol passes the string by reference
// it passes the "address location" of the string variable
// comment lines 31-36, and uncomment below to see another example of passing by value
void swap(std::string& str, int idx1, int idx2)
{
    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}
//void swap(std::string str, int idx1, int idx2) // swap two chars and get a new string, i.e., "passing by value"
//{
//    char temp = str[idx1];
//    str[idx1] = str[idx2];
//    str[idx2] = temp;
//    std::cout << "My string within this function is now: "
//              << str << std::endl; // only the copy is modified within the function, as a local variable.
//}

// for copy, the first argument is const to prevent modification
// values in arrfrom can be accessed, but not modified
// if we made the second argument also const, the compiler will throw an error because arrto elements are modified
void copy(const int arrfrom[], int arrto[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arrto[i] = arrfrom[i]; // the copy function itself just duplicates element value one by one
    }
}

#endif