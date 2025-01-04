// This is SafeArray2.cpp
// Changes from SafeArray1.cpp:
// 1. implement operator[] for access
// 2. implement operator[] for update 

#include "SafeArray2.hpp"
#include<stdexcept>
#include<algorithm>

SafeArray::SafeArray() : size(0), dataptr(nullptr)
{
    //size = 0;
    //dataptr = nullptr;
}

SafeArray::SafeArray(int s) : size(s)  // construct size here
{
    dataptr = new int[size];           // assign dataptr a new dynamically allocated ptr
    for (int i=0; i<size; i++){
        dataptr[i]=0;                  // construct dataptr here
    }
}

SafeArray::~SafeArray()
{
    delete [] dataptr;
}

int SafeArray::get_size() const // as always, getter function has "const" at the end
{
    return size;
}

// this would only access information using []
// int SafeArray::operator[](int idx) const
// {
//     if (idx<0 || idx>=size){
//         throw std::out_of_range("Index out of range");
//     }
//     return dataptr[idx];
// }

int & SafeArray::operator[](int idx)
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}