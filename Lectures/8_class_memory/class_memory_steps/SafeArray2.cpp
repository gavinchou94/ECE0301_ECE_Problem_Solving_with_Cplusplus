// This is SafeArray2.cpp
// Changes from SafeArray1.cpp:
// - Adds operator[] for reading.
// - Adds operator[] for writing.

#include <algorithm>
#include <stdexcept>

#include "SafeArray2.hpp"

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

// Read an element using [].
int SafeArray::operator[](int idx) const
{
  if (idx < 0 || idx >= size)
  {
    throw std::out_of_range("Index out of range");
  }
  return dataptr[idx];
}

int &SafeArray::operator[](int idx)
{
  if (idx < 0 || idx >= size)
  {
    throw std::out_of_range("Index out of range");
  }
  return dataptr[idx];
}