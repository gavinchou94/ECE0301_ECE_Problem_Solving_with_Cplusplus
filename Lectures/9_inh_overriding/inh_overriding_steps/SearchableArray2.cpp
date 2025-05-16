// This is new SearchableArray2.cpp
// 1. implement the new method added for derived class SearchableArray
// 2. due to "using" line in .hpp file, no need to implement constructor
// 3. get_size() and get(int) functions are inherited

#include "SearchableArray2.hpp"

bool SearchableArray::search(int value)
{
    //SearchableArray can use public method from SafeArray, e.g., get_size()
    for(int i=0; i<get_size(); i++){ 
        if (get(i)==value){        //same as above, get() is available to use
            return true;
        }
    }
    return false;
}