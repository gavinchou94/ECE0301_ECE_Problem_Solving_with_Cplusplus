// This is final version of pointers.hpp, clear comments from pointers_7.hpp

#ifndef _POINTERS_HPP
#define _POINTERS_HPP

/**
 * Copies the contents of the given integer array into a new array.
 *
 * @param arr The original array to copy.
 * @param size The number of elements in the array.
 * @return A pointer to the newly allocated array that contains the copied elements.
 */
int* copy(const int* arr, const int size)
{
    // function returns a ptr, therefore return type is "int * "
    // first argument is a ptr to an int array, const is added due to unmodified feature
    // second argument is size, also const

    int* arrcopy = new int[size];
    for (int i = 0; i < size; i++)
    {
        arrcopy[i] = arr[i];
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
void append(int* & arr, const int newval, int& size)
{
    // function doesn't return anything, so return type is "void"
    // first argument is arr ptr, pointing to the original array, so it is "int*"
    // first argument (hex address) needs to hold the change outside append() scope, so it is "&"
    // second argument is the new value to be appended, const is added to protect
    // third argument is the size, needs to be updated outside scope, so it is "int &"

    int* old_arr = arr; // use a ptr-copy style keep a copy as old_arr

    arr = new int[size + 1]; // assign arr to be a new dynamically allocated array ptr of size+1

    // element-wise copy for the first n=size element
    for (int i = 0; i < size; i++)
    {
        arr[i] = old_arr[i];
    }

    // assign newval to the last element
    arr[size] = newval;

    // size is updated too
    size++;

    // deallocate old_arr, which essentially erase where the original arr[] is stored
    delete [] old_arr;

    // Here you shouldn't "delete [] arr;" since the arr is used outside the scope, indicated by "&" in front of arr
}


// Try to return a ptr from a function without passing a ptr: the ptr points to dynamically allocated array
int* pointer_test_dy()
{
    int* int_dy = new int[4]{30, 20, 10, 0};
    return int_dy; // int_dy points to dynamically allocated chunk of memory
}

// Try to return a ptr from a function without passing a ptr: the ptr points to static array
int* pointer_test_st()
{
    int int_st[4] = {3, 2, 1, 0};
    return int_st; // BAD RETURN: int_st points to a local array which is not accessible outside function scope.
}

#endif
