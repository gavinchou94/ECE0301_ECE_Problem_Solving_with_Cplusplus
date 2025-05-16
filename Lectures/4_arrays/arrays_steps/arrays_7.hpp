// This is arrays_7.hpp
// Changes from arrays_6.hpp:
// 1. implement binary search
// 2. show how recursive is conducted using base cases and recursive calls

#ifndef _ARRAYS_HPP
#define _ARRAYS_HPP

#include <iostream>
#include "constants.hpp"

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

// binary search is more efficient than linear search, but requires a sorted array
// the search space is divided in half with each recursive call to binary_search
bool binary_search(const int arr[], int val, int start, int end)
{
    // assume arr is sorted
    // recursive functions have to include base cases (the termination conditions)

    // Base case 1: check middle value, if middle is val, return true
    int middle = (start + end) / 2;
    if (arr[middle] == val)
    {
        return true;
    }

    // Base case 2: search range is narrowed down to just 2 elements
    if (end == start+1)
    {
        return false;
    }

    // if middle is > val, search lower half
    if (arr[middle] > val)
    {
        return binary_search(arr, val, start, middle);
    }

    // if middle is < val, search upper half
    if (arr[middle] < val)
    {
        return binary_search(arr, val, middle, end);
    }

    return false;
}

#endif