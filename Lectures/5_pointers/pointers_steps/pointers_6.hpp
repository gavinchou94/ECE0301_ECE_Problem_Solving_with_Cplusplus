// This is pointers_6.hpp
// Changes compared to pointers_5.hpp:
// - Fills in the body of append().
// - Adds comments to explain the function prototype.
// - Places delete inside and outside the function.

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

/**
 * Append newval to arr, growing it by one.
 * @param arr    pointer to the array, updated to the new one
 * @param newval the value to add
 * @param size   current length, updated after appending
 */
void append(int *&arr, const int newval, int &size)
{
  // void       returns nothing; the changes travel through the reference parameters
  // int *&     & means "reference to": arr is a reference to the caller's pointer, not a copy,
  //            so re-pointing arr to the new bigger array is seen by the caller too
  // const int  newval is copied in and read-only
  // int &      size is a reference: updating it here updates the caller's size
  int *old_arr = arr;        // keep the old array so we can copy from it

  arr = new int[size + 1];   // a bigger array; arr now points here
  for (int i = 0; i < size; i++)
  {
    arr[i] = old_arr[i];     // copy the old values over
  }
  arr[size] = newval;        // put the new value in the last slot
  size++;

  delete[] old_arr;          // free the old array; do NOT delete arr, the caller still uses it
}

#endif