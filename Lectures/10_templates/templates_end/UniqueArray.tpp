// This is final version of UniqueArray.tpp

#include "UniqueArray.hpp"
#include <stdexcept>

// Sets the value at the specified index, ensuring no duplicate values exist in the array.
// Throws a logic_error if the value already exists in the array.
template <typename T>                      // add template definition
void UniqueArray<T>::set(int index, T val) // add <T> to the class name before ::, not to the function name
                                           // also change argument type to T
{
    for (int i = 0; i < SafeArray<T>::get_size(); i++) // cannot just use get_size() here, need to specify the class name with <T>
    {
        if (SafeArray<T>::get(i) == val) // cannot just use get(i) here, need to specify the class name with <T>
                                         // requires operator== for type T, especially when T is a user-defined type
        {
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray<T>::set(index, val); // using set(index, val) here would cause infinite recursion
}
// note that SafeArray<T>::get_size(), SafeArray<T>::get(i) can also be UniqueArray<T>::xxx
// but cannot change SafeArray<T>::set(index, val) to UniqueArray<T>::set(index, val)
// because UniqueArray<T>::set(index, val) would cause infinite recursion