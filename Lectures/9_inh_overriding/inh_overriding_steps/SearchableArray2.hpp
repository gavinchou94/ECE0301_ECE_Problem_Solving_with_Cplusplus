// This is SearchableArray2.hpp
// Changes from SearchableArray1.hpp:
// - Defines SearchableArray with public inheritance from SafeArray.
// - Inherits the base constructors and declares search().

#ifndef SEARCHABLE_ARRAY_HPP
#define SEARCHABLE_ARRAY_HPP

#include "SafeArray2.hpp"

class SearchableArray : public SafeArray // all public member functions (except constructors) of SafeArray class are inherited
{
public:
  using SafeArray::SafeArray; // this line tells compiler to use constructors from SafeArray
  // above line also tells how to construct a derived class, same as using the following constructors
  // SearchableArray();
  // SearchableArray(int);
  // SearchableArray(const SearchableArray &);
  bool search(int); // new method just for SearchableArray
};

#endif