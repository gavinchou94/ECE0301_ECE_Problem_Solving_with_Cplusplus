// This is SearchableArray3.cpp
// Changes from SearchableArray2.cpp:
// - Accesses dataptr directly to demonstrate protected members.

#include "SearchableArray3.hpp"

bool SearchableArray::search(int value)
{
  // SearchableArray can use public methods from SafeArray, e.g., get_size()
  for (int i = 0; i < get_size(); i++)
  {
    if (dataptr[i] == value)
    { // dataptr is accessible due to "protected"
      return true;
    }
  }
  return false;
}