// This is UniqueArray3.hpp
// Changes from UniqueArray2.hpp:
// - Defines UniqueArray and declares set(), which overrides the virtual base method.

#ifndef UNIQUE_ARRAY_HPP
#define UNIQUE_ARRAY_HPP

#include "SafeArray3.hpp"

class UniqueArray : public SafeArray // all public member functions (except constructors) of SafeArray class are inherited
{
public:
  using SafeArray::SafeArray;
  // above line also tells how to construct a derived class, same as using the following constructors
  // UniqueArray();
  // UniqueArray(int);
  // UniqueArray(const UniqueArray &);

  void set(int, int); // derived class function overriding or redefining base class function
                      // If "virtual" is not added to SafeArray base class, this redefines base class function
                      // If "virtual" is added to SafeArray base class, this overrides base class function
};

#endif