// This is final version of SearchableArray.cpp
// No changes from SearchableArray4.hpp:

#include "SearchableArray.hpp"

bool SearchableArray::search(int value)
{
    for(int i=0; i<get_size(); i++){ 
        if (get(i)==value){
            return true;
        }
    }
    return false;
}