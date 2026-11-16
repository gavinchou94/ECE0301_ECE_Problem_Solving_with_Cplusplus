#ifndef UNIQUE_ARRAY_HPP
#define UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

class UniqueArray : public SafeArray // all public member functions (except constructors) of SafeArray class are inherited
{
public:
  using SafeArray::SafeArray;
  // above line also tells how to construct a derived class, same as using the following constructors
  // UniqueArray();
  // UniqueArray(int);
  // UniqueArray(const UniqueArray &);

  void set(int, int) override final; // derived class function overriding base class function
                                     // If "virtual" is not added to SafeArray base class, "override" makes this a compile error
                                     // If "virtual" is added to SafeArray base class, this overrides base class function
};

#endif