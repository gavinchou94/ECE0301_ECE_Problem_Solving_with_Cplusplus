// This is new SearchableArray2.hpp
// 1. "public" at Line 10 describes access permission to base class
// 2. "public" at Line 11 describes object's permission to this derived class
// 3. "using" at Line 15 tells compiler how to construct a derived class
// 4. add a new method just for this derived class SearchableArray

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray2.hpp"

class SearchableArray: public SafeArray{
    public:
        // all public member functions(except constructors) of SafeArray class are inherited
        
        using SafeArray::SafeArray; 
        // above is how to construct a derived class, same as using the following two lines
        // SearchableArray();
        // SearchableArray(int);
        bool search(int);
};

#endif