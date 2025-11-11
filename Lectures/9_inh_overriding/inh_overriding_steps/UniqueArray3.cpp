// This is new UniqueArray3.cpp
// 1. implement the set function for derived class
// 2. calling base functions get_size(), get(int)
// 3. calling function SafeArray::set( , ), using scope resolution operator

#include "UniqueArray3.hpp"
#include <stdexcept>

void UniqueArray::set(int index, int val)
{
    for (int i = 0; i < get_size(); i++)
    {
        if (get(i) == val) // if SafeArray attribute is "protected", can directly use dataptr[i] as well
        {
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray::set(index, val);
    // using set(index, val) here would cause infinite recursion
    // because it would first call UniqueArray::set( , ), while the recursion never ends

    // Rule: compiler first looks for function in the current class, if not found, then looks in parent class

    // Note that you can also finish the implementation by directly accessing if SafeArray attribute is "protected"
    // but this decreases code reusability and maintainability

    /*
    if (idx < 0 || idx >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    dataptr[index] = val;
    */
}