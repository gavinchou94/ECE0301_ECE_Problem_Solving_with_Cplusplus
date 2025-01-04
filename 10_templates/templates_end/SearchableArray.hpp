// This is the final version of SearchableArray.hpp

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray.hpp"

template <typename T>
class SearchableArray: public SafeArray<T> {
    public:
        using SafeArray<T>::SafeArray; 
        bool search(T);
};

#include "SearchableArray.tpp"

#endif