// This is the SearchableArray2.hpp
// changes from SearchableArray1.hpp:
// 1. inherit SafeArray<T> as a template derived class
// 2. change to include SearchableArray2.tpp at the end of the file

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray.hpp"

template <typename T>
class SearchableArray: public SafeArray<T> {
    public:
        using SafeArray<T>::SafeArray; 
        bool search(T);
};

#include "SearchableArray2.tpp"

#endif