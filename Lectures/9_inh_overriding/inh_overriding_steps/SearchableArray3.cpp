// This is SearchableArray3.cpp
// Changes from SearchableArray2.hpp:
// 1. temporaily switch from using public function get() to directly using member variable
//    to demonstrate the use of "protected" access specifier in base class

#include "SearchableArray3.hpp"

// bool SearchableArray::search(int value)
// {
//     for(int i=0; i<get_size(); i++){
//         if (get(i)==value){
//             return true;
//         }
//     }
//     return false;
// }

bool SearchableArray::search(int value)
{
    for (int i = 0; i < get_size(); i++)
    {
        if (dataptr[i] == value)
        { // dataptr is accessible due to "protected"
            return true;
        }
    }
    return false;
}