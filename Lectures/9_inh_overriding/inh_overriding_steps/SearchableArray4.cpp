// This is SearchableArray4.cpp
// Changes from SearchableArray3.cpp:
// - Uses get() again because dataptr is private.

#include "SearchableArray4.hpp"

bool SearchableArray::search(int value)
{
  // SearchableArray can use public methods from SafeArray, e.g., get_size()
  for (int i = 0; i < get_size(); i++)
  {
    if (get(i) == value)
    {
      return true;
    }
  }
  return false;
}