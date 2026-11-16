// This is UniqueArray3.cpp
// Changes from UniqueArray2.cpp:
// - Implements set() to reject duplicates and calls SafeArray::set() to update the element.

#include <stdexcept>

#include "UniqueArray3.hpp"

void UniqueArray::set(int index, int val)
{
  for (int i = 0; i < get_size(); i++)
  {
    if (get(i) == val) // if SafeArray attribute is "protected", can directly use dataptr[i] as well
    {
      throw std::logic_error("Duplicate value");
    }
  }
  SafeArray::set(index, val);
  // set(index, val) here would recurse forever: lookup finds UniqueArray::set first
}