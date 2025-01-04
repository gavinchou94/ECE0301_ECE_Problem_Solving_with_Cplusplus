// This is the final version of SearchableArray.tpp from last exercise

#include "SearchableArray.hpp"

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