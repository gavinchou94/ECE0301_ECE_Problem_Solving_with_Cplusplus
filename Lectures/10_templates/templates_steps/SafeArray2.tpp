// This is template class version of SafeArray2.tpp
// no change from SafeArray1.tpp, just match version numbering

#include "SafeArray2.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>                                 // this is a template definition, so we need to add <T> here
SafeArray<T>::SafeArray() : size(0), dataptr(nullptr) // add <T> to the class name before ::, not to the constructor name
{
}

template <typename T>                    // this is a template definition, so we need to add <T> here
SafeArray<T>::SafeArray(int s) : size(s) // add <T> to the class name before ::, not to the constructor name
{
    dataptr = new T[size];
    for (int i = 0; i < size; i++)
    {
        dataptr[i] = T(); // T() is default value of data type T, requires default constructor if T is a user-defined type
                          // e.g., int() = 0, double() = 0.0, std::string() = ""
    }
}

template <typename T>
SafeArray<T>::~SafeArray() // add <T> to the class name, not to the destructor name
{
    delete[] dataptr;
}

template <typename T>                          // this is a template definition, so we need to add <T> here
SafeArray<T>::SafeArray(const SafeArray<T> &s) // add <T> to the class name before ::, not to the constructor name
                                               // also add <T> to the argument type
{
    size = s.size;
    dataptr = new T[size];
    for (int i = 0; i < size; i++)
    {
        dataptr[i] = s.dataptr[i]; // might require custom assignment operator for type T
    }
}

template <typename T>                                 // this is a template definition, so we need to add <T> here
SafeArray<T> &SafeArray<T>::operator=(SafeArray<T> s) // add <T> to the class name before ::, not to the operator function name
                                                      // also add <T> to the argument type and return type
{
    std::swap(size, s.size);
    std::swap(dataptr, s.dataptr); // this requires <algorithm>
    return *this;
    // Using copy-and-swap idiom: 1. Pass by value, 2. Swap with the copy, 3. Return *this
}

template <typename T>              // this is a template definition, so we need to add <T> here
int SafeArray<T>::get_size() const // add <T> to the class name before ::, not to the function name
{
    return size;
}

template <typename T>              // this is a template definition, so we need to add <T> here
T SafeArray<T>::get(int idx) const // add <T> to the class name before ::, not to the function name
                                   // also change return type to T
{
    if (idx < 0 || idx >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}

template <typename T>                  // this is a template definition, so we need to add <T> here
void SafeArray<T>::set(int idx, T val) // add <T> to the class name before ::, not to the function name
                                       // also change second argument type to T
{
    if (idx < 0 || idx >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    dataptr[idx] = val; // might require custom operator= for type T
}

// implement a non-member operator overloading function
template <typename T>                              // this is a template definition, so we need to add <T> here
SafeArray<T> operator+(const SafeArray<T> &a, T b) // non-member function, no need to use :: anyway
                                                   // add <T> to return type and argument types
{
    SafeArray<T> result(a.get_size());          // element-wise adding b
    for (int i = 0; i < result.get_size(); i++) // use public interface
    {
        result.set(i, a.get(i) + b); // require operator+ for type T
    }
    return result;
}

template <typename T>                              // this is a template definition, so we need to add <T> here
SafeArray<T> operator+(T a, const SafeArray<T> &b) // non-member function, no need to use :: anyway
                                                   // add <T> to return type and argument types
{
    return operator+(b, a);
}