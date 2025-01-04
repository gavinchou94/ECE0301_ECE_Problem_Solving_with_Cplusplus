// This is the UniqueArray2.hpp
// changes from UniqueArray1.hpp:
// 1. inherit SafeArray<T> as a derived template class
// 2. change to include UniqueArray2.tpp at the end of the file

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

template <typename T>
class UniqueArray: public SafeArray<T>
{
    public:
        using SafeArray<T>::SafeArray; // inherit constructors
        void set(int index, T value) override final;
};

#include "UniqueArray2.tpp"

#endif