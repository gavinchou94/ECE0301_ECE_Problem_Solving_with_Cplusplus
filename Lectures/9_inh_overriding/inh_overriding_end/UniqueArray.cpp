#include <stdexcept>

#include "UniqueArray.hpp"

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

  // using set(index, val) here would cause infinite recursion
  // because it would first call UniqueArray::set( , ), while the recursion never ends

  // Rule: compiler first looks for function in the current class, if not found, then looks in parent class
}