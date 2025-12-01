// This is the SearchableArray2.hpp
// changes from SearchableArray1.hpp:
// 1. inherit SafeArray<T> to be a template derived class
// 2. explain where to add T and where not to

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray2.hpp"

template <typename T>                       // declare SearchableArray as a template class
class SearchableArray : public SafeArray<T> // inherit from SafeArray<T>
{
public:
    using SafeArray<T>::SafeArray; // inherit constructors of SafeArray<T>
    bool search(T);
};

#include "SearchableArray2.tpp"

#endif