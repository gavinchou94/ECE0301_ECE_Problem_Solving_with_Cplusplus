// This is SearchableArray4.cpp
// Changes from SearchableArray3.hpp:
// switch back to function get()

#include "SearchableArray4.hpp"

bool SearchableArray::search(int value)
{
    for(int i=0; i<get_size(); i++){ 
        if (get(i)==value){
            return true;
        }
    }
    return false;
}