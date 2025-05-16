// This is SafeArray3.cpp
// Changes from SafeArray2.cpp:
// implement copy constructor

#include "SafeArray3.hpp"
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

// to use "SafeArray arr1(arr2)", this copy constructor has to be built since dataptr is a pointer
// if there is no ptr member variable in the class, no need build this, Date d1(d2) works!
SafeArray::SafeArray(const SafeArray &s)
{
    size = s.size;                       // give arr2.size to size of this new arr1 object
    dataptr = new int[size];             // assign dataptr a new dynamically allocated ptr
    for (int i=0; i<size; i++){
        dataptr[i]=s.dataptr[i];         // construct dataptr here using element-wise copy from arr2.dataptr
    }
}

int SafeArray::get_size() const // as always, getter function has "const" at the end
{
    return size;
}

// this would only access information using []
int SafeArray::operator[](int idx) const
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}

int & SafeArray::operator[](int idx)
{
    if (idx<0 || idx>=size){
        throw std::out_of_range("Index out of range");
    }
    return dataptr[idx];
}