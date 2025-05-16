// This is the SearchableArray2.tpp
// changes from SearchableArray1.cpp:
// SafeArray<T>:: instead of SafeArray<int>::

#include "SearchableArray2.hpp"

template <typename T>
bool SearchableArray<T>::search(T value)
{
    for(int i=0; i<SafeArray<T>::get_size(); i++){ 
        if (SafeArray<T>::get(i) == value) {
            return true;
        }
    }
    return false;
}