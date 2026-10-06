// This is pointers_5.hpp
// Changes compared to pointers_starter.hpp:
// - Fills in the body of copy().
// - Adds comments to explain the function prototype.

#ifndef POINTERS_HPP
#define POINTERS_HPP

/**
 * Copy arr into a brand-new array and return a pointer to it.
 * @param arr   the array to copy (read-only)
 * @param size  how many elements
 * @return      pointer to the new array
 */
int *copy(const int *arr, const int size)
{
  // int *        return type: hands back a pointer to the new array
  // const int *  arr is read-only: the function may read the source but not change it
  // const int    size is copied in; const keeps that local copy from changing
  int *arrcopy = new int[size];
  for (int i = 0; i < size; i++)
  {
    arrcopy[i] = arr[i];
  }
  return arrcopy;
}

#endif