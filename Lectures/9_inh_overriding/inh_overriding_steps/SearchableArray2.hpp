// This is new SearchableArray2.hpp
// 1. "public" at class declaration line describes access permission to base class
// 2. "public" at inside derived class describes client's permission to this derived class
// 3. "using" line tells compiler how to construct a derived class
// 4. add a new method just for this derived class SearchableArray

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray2.hpp"

class SearchableArray : public SafeArray // all public member functions(except constructors) of SafeArray class are inherited
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