// This is the SearchableArray1.hpp
// changes from SearchableArray.hpp in starter code:
// 1. inherit from SafeArray<int> to be a non-template class
// 2. constructor is specified to use SafeArray<int> constructor

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray1.hpp"

class SearchableArray : public SafeArray<int>
{
public:
    using SafeArray<int>::SafeArray; // class name should be specfied with template argument
    bool search(int);
};

#endif