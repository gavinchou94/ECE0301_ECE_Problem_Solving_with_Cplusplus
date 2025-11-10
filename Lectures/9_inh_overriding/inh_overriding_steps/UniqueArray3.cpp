// This is new UniqueArray3.cpp
// 1. implement the set function for derived class
// 2. calling base functions get_size(), get(int)
// 3. calling function SafeArray::set( , ), using scope resolution operator

#include "UniqueArray3.hpp"
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