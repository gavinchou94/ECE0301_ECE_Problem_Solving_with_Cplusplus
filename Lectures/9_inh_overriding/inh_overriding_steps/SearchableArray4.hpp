// This is SearchableArray4.cpp
// No changes from SearchableArray3.hpp

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray4.hpp"

class SearchableArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        bool search(int);
};

#endif