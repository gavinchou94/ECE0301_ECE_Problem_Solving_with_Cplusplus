// This is the SearchableArray1.hpp
// changes from SearchableArray.hpp:
// 1. inherit SafeArray<int> as a non-template class
// 2. constructor is specified to use SafeArray<int> constructor

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray.hpp"

class SearchableArray: public SafeArray<int> {
    public:
        using SafeArray<int>::SafeArray; 
        bool search(int);
};

#endif