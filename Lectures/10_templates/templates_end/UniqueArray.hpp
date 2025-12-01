// This is final version of UniqueArray.hpp

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

template <typename T>                   // declare UniqueArray as a template class
class UniqueArray : public SafeArray<T> // inherit from SafeArray<T>
{
public:
    using SafeArray<T>::SafeArray; // inherit constructors of SafeArray<T>
    void set(int index, T value) override final;
};

#include "UniqueArray.tpp"

#endif