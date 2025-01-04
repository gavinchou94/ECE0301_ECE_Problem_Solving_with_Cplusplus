// This is SafeArray.tpp, changed from SafeArray.cpp of the starter code
// 1. add <typename T> to all function names
// 2. change int to T in the function definitions

#include "SafeArray.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>
SafeArray<T>::SafeArray() : size(0), dataptr(nullptr) // add <T> to the class name, same as below
{
}

template <typename T>
SafeArray<T>::SafeArray(int s) : size(s)
{
    dataptr = new T[size];
    for (int i=0; i<size; i++){
        dataptr[i] = T(); // default value of T, requires default constructor if T is a class
    }
}

template <typename T>
SafeArray<T>::~SafeArray()
{
    delete [] dataptr;
}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T> &s) // add <T> to the class name
{
    size = s.size;
    dataptr = new T[size];
    for (int i=0; i<size; i++){
        dataptr[i]=s.dataptr[i];
    }
}

template <typename T>
SafeArray<T> & SafeArray<T>::operator=(SafeArray<T> s)
{
    std::swap(size, s.size);
    std::swap(dataptr, s.dataptr); // this requires <algorithm>
    return *this;
    // Using copy-and-swap idiom: 1. Pass by value, 2. Swap with the copy, 3. Return *this
}

template <typename T>
int SafeArray<T>::get_size() const
{
    return size;
}

// int SafeArray::operator[](int idx) const
// {
//     if (idx<0 || idx>=size){
//         throw std::out_of_range("Index out of range");
//     }
//     return dataptr[idx];
// }

template <typename T>
T SafeArray<T>::get(int idx) const
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}

// int & SafeArray::operator[](int idx)
// {
//     if (idx<0 || idx>=size){
//         throw std::out_of_range("Index out of range");
//     }
//     return dataptr[idx];
// }

template <typename T>
void SafeArray<T>::set(int idx, T val)
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    dataptr[idx]=val;
}

// implement a non-member operator overloading function
template <typename T>
SafeArray<T> operator+(const SafeArray<T> &a, T b)
{
    SafeArray<T> result(a.get_size());  // element-wise adding b
    for (int i=0; i<result.get_size(); i++){
        result.set(i, a.get(i)+b);
    }
    return result;
}

template <typename T>
SafeArray<T> operator+(T a, const SafeArray<T> &b)
{
    return operator+(b,a);
}