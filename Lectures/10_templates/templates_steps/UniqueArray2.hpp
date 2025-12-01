// This is the UniqueArray2.hpp
// changes from UniqueArray1.hpp:
// 1. inherit from SafeArray<T> to be a derived template class
// 2. explain where to add T and where not to

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray2.hpp"

template <typename T>                   // declare UniqueArray as a template class
class UniqueArray : public SafeArray<T> // inherit from SafeArray<T>
{
public:
    using SafeArray<T>::SafeArray; // inherit constructors of SafeArray<T>
    void set(int index, T value) override final;
};

#include "UniqueArray2.tpp"

#endif