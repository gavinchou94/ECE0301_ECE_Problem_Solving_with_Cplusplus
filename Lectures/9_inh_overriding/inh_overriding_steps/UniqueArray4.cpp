// This is UniqueArray4.cpp
// No changes from UniqueArray3.cpp

#include <stdexcept>

#include "UniqueArray4.hpp"

void UniqueArray::set(int index, int val)
{
  for (int i = 0; i < get_size(); i++)
  {
    if (get(i) == val)
    {
      throw std::logic_error("Duplicate value");
    }
  }
  SafeArray::set(index, val);
}