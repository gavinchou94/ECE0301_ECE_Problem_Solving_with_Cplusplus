// This is final version of UniqueArray.cpp
// No changes from UniqueArray4.cpp

#include "UniqueArray.hpp"
#include <stdexcept>

void UniqueArray::set(int index, int val)
{
    for (int i=0; i<get_size(); i++){
        if (get(i) == val){
            throw std::logic_error("Duplicate value");
        }
    }
    SafeArray::set(index, val); // using set(index, val) here would cause infinite recursion
}