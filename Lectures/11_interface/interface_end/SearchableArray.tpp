// This is final version of SearchableArray.tpp

#include "SearchableArray.hpp"

template <typename T>                    // add template definition
bool SearchableArray<T>::search(T value) // add <T> to the class name before ::, not to the function name
                                         // also change argument type to T
{
    for (int i = 0; i < SafeArray<T>::get_size(); i++) // cannot just use get_size() here, need to specify the class name with <T>
    {
        if (SafeArray<T>::get(i) == value) // cannot just use get(i) here, need to specify the class name with <T>
                                           // requires operator== for type T, especially when T is a user-defined type
        {
            return true;
        }
    }
    return false;
} // note that SafeArray<T>::get_size(), SafeArray<T>::get(i) can also be SearchableArray<T>::get_size(), SearchableArray<T>::get(i)