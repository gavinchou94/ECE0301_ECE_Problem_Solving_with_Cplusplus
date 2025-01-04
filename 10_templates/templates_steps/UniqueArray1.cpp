// This is the UniqueArray1.cpp
// changes from UniqueArray.cpp:
// adding SafeArray<int>:: before public method calls

#include "UniqueArray1.hpp"
#include <stdexcept>

// Sets the value at the specified index, ensuring no duplicate values exist in the array.
// Throws a logic_error if the value already exists in the array.
void UniqueArray::set(int index, int val)
{
    for (int i = 0; i < SafeArray<int>::get_size(); i++){
        if (SafeArray<int>::get(i) == val){
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray<int>::set(index, val); // using set(index, val) here would cause infinite recursion
}