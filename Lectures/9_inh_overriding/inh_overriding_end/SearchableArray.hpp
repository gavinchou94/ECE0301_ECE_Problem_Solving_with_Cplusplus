#ifndef SEARCHABLE_ARRAY_HPP
#define SEARCHABLE_ARRAY_HPP

#include "SafeArray.hpp"

class SearchableArray : public SafeArray // all public member functions (except constructors) of SafeArray class are inherited
{
public:
  using SafeArray::SafeArray; // this line tells compiler to use constructors from SafeArray
  bool search(int);           // new method just for SearchableArray
};

#endif