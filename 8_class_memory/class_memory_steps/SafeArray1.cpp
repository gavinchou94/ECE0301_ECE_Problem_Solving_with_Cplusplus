// This is new SafeArray1.cpp
// It implements two constructors and getter function

#include "SafeArray1.hpp"
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