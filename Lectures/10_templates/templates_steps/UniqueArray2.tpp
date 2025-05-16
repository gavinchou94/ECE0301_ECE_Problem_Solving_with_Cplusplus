// This is the UniqueArray2.cpp
// changes from UniqueArray1.cpp:
// adding SafeArray<T>:: before public method calls

#include "UniqueArray2.hpp"
#include <stdexcept>

// Sets the value at the specified index, ensuring no duplicate values exist in the array.
// Throws a logic_error if the value already exists in the array.
template <typename T>
void UniqueArray<T>::set(int index, T val)
{
    for (int i = 0; i < SafeArray<T>::get_size(); i++){
        if (SafeArray<T>::get(i) == val){
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray<T>::set(index, val); // using set(index, val) here would cause infinite recursion
}