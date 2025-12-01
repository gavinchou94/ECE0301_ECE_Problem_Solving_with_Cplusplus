// This is final version of SearchableArray.hpp

#ifndef _SEARCHABLE_ARRAY_HPP
#define _SEARCHABLE_ARRAY_HPP

#include "SafeArray.hpp"

template <typename T>                       // declare SearchableArray as a template class
class SearchableArray : public SafeArray<T> // inherit from SafeArray<T>
{
public:
    using SafeArray<T>::SafeArray; // inherit constructors of SafeArray<T>
    bool search(T);
};

#include "SearchableArray.tpp"

#endif