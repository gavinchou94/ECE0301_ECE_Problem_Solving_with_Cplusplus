// This is the final version of UniqueArray.hpp from last exercise

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray1.hpp"

template <typename T>
class UniqueArray: public SafeArray<T>
{
    public:
        using SafeArray<T>::SafeArray; // inherit constructors
        void set(int index, T value) override final;
};

#include "UniqueArray.tpp"

#endif