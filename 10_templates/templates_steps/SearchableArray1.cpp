// This is the SearchableArray1.cpp
// changes from SearchableArray.cpp:
// adding SafeArray<int>:: before public method calls

#include "SearchableArray1.hpp"

bool SearchableArray::search(int value)
{
    for(int i=0; i<SafeArray<int>::get_size(); i++){ 
        if (SafeArray<int>::get(i) == value) {
            return true;
        }
    }
    return false;
}