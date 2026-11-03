#include <algorithm>
#include <stdexcept>

#include "SafeArray.hpp"

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

// A copy constructor is needed to give each SafeArray its own array.
// Classes without pointer members can usually use the compiler-generated copy constructor.
SafeArray::SafeArray(const SafeArray &s)
{
  size = s.size;           // Copy the source object's size.
  dataptr = new int[size]; // Allocate an array for dataptr.
  for (int i = 0; i < size; i++)
  {
    dataptr[i] = s.dataptr[i]; // Copy this element from the source array.
  }
}

// A copy-assignment operator is needed to give each SafeArray its own array.
// Classes without pointer members can usually use the compiler-generated copy-assignment operator.
SafeArray &SafeArray::operator=(SafeArray s)
{
  size = s.size;
  std::swap(dataptr, s.dataptr); // Swap the array pointers.

  // int * tempptr = dataptr;
  // dataptr = s.dataptr;
  // s.dataptr = tempptr;

  return *this;
  // Copy-swap: copy the right-hand side, swap members, and return *this.
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

// Add b to each element of a.
SafeArray operator+(const SafeArray &a, int b)
{
  SafeArray result(a.get_size()); // Add b to each element.
  for (int i = 0; i < result.get_size(); i++)
  {
    result[i] = a[i] + b;
  }
  return result;
}

SafeArray operator+(int a, const SafeArray &b)
{
  return operator+(b, a);
}