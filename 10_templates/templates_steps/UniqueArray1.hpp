// This is the UniqueArray1.hpp
// changes from UniqueArray.hpp:
// 1. inherit SafeArray<int> as a non-template class
// 2. constructor is specified to use SafeArray<int> constructor

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

class UniqueArray: public SafeArray<int>
{
    public:
        using SafeArray<int>::SafeArray; // inherit constructors
        void set(int index, int value) override final;
};

#endif