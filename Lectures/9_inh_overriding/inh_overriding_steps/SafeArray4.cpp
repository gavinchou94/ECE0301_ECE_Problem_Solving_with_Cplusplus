// This is SafeArray4.cpp
// No changes from SafeArray3.cpp

#include "SafeArray4.hpp"
#include<stdexcept>
#include<algorithm>

SafeArray::SafeArray() : size(0), dataptr(nullptr)
{
}

SafeArray::SafeArray(int s) : size(s)
{
    dataptr = new int[size];
    for (int i=0; i<size; i++){
        dataptr[i]=0;
    }
}

SafeArray::~SafeArray()
{
    delete [] dataptr;
}

SafeArray::SafeArray(const SafeArray &s)
{
    size = s.size;
    dataptr = new int[size];
    for (int i=0; i<size; i++){
        dataptr[i]=s.dataptr[i];
    }
}

SafeArray & SafeArray::operator=(SafeArray s)
{
    size = s.size;
    std::swap(dataptr, s.dataptr); // this requires <algorithm>
    return *this;
    // 1.copy-2.swap-idiom: 1.passing by value, 2.swap with others, 3.return *this
}

int SafeArray::get_size() const
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

int SafeArray::get(int idx) const
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

void SafeArray::set(int idx, int val)
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    dataptr[idx]=val;
}

// implement a non-member operator overloading function
SafeArray operator+(const SafeArray &a, int b)
{
    SafeArray result(a.get_size());  // element-wise adding b
    for (int i=0; i<result.get_size(); i++){
        result.set(i, a.get(i)+b);
    }
    return result;
}

SafeArray operator+(int a, const SafeArray &b)
{
    return operator+(b,a);
}