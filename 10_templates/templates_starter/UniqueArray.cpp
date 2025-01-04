#include "UniqueArray.hpp"
#include <stdexcept>

// Sets the value at the specified index, ensuring no duplicate values exist in the array.
// Throws a logic_error if the value already exists in the array.
void UniqueArray::set(int index, int val)
{
    for (int i = 0; i < get_size(); i++){
        if (get(i) == val){
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray::set(index, val); // using set(index, val) here would cause infinite recursion
}