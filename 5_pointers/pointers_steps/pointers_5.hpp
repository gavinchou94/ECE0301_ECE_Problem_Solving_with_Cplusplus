// This is pointers_5.hpp
// Changes from pointers_starter.hpp:
// filled in the function body of copy(), add comments to explain the prototype

#ifndef _POINTERS_HPP
#define _POINTERS_HPP

/**
 * Copies the contents of the given integer array into a new array.
 *
 * @param arr The original array to copy.
 * @param size The number of elements in the array.
 * @return A pointer to the newly allocated array that contains the copied elements.
 */
int * copy(const int * arr, const int size){
    // function returns a ptr, therefore return type is "int * "
    // first argument is a ptr to an int array, const is added due to unmodified feature
    // second argument is size, also const

    int * arrcopy = new int[size];
    for (int i=0; i<size; i++){
        arrcopy[i]=arr[i];
    } 
    return arrcopy;

}

/**
 * Appends a new integer value to the end of the given array.
 *
 * @param arr Reference to the pointer of the array to which the new value should be appended.
 * @param newval The new integer value to append to the array.
 * @param size Reference to the integer representing the current size of the array; will be updated after appending.
 */
void append(int*& arr, const int newval, int& size)
{

}

#endif