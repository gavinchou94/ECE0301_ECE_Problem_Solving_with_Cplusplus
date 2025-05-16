// This is SearchableArray3.cpp
// No changes from SearchableArray2.hpp

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray3.hpp"

class SearchableArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        bool search(int);
};

#endif