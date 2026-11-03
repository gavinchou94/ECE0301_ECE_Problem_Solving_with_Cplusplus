// This is a new SafeArray1.cpp
// This version:
// - Implements two constructors, a destructor, and get_size().

#include <algorithm>
#include <stdexcept>

#include "SafeArray1.hpp"

SafeArray::SafeArray() : size(0), dataptr(nullptr)
{
  // size = 0;
  // dataptr = nullptr;
}

SafeArray::SafeArray(int s) : size(s) // Initialize size here.
{
  dataptr = new int[size]; // Allocate an array for dataptr.
  for (int i = 0; i < size; i++)
  {
    dataptr[i] = 0; // Initialize this element to zero.
  }
}

SafeArray::~SafeArray()
{
  delete[] dataptr;
}

int SafeArray::get_size() const // The const qualifier means this getter does not modify the object.
{
  return size;
}