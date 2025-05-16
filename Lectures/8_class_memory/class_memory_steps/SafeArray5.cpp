// This is SafeArray5.cpp
// Changes from SafeArray4.cpp:
// implements two non-member functions

#include "SafeArray5.hpp"
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
// if there is no ptr member variable in the class, no need build this, e.g., Date d1(d2) works!
SafeArray::SafeArray(const SafeArray &s)
{
    size = s.size;                       // give arr2.size to size of this new arr1 object
    dataptr = new int[size];             // assign dataptr a new dynamically allocated ptr
    for (int i=0; i<size; i++){
        dataptr[i]=s.dataptr[i];         // construct dataptr here using element-wise copy from arr2.dataptr
    }
}

// to use "arr1 = arr2", this copy assignment operator has to be built since dataptr is a pointer
// if there is no ptr member variable in the class, no need build this, e.g., Date d1 = d2 works!
SafeArray & SafeArray::operator=(SafeArray s)
{
    size = s.size;
    std::swap(dataptr, s.dataptr); // this requires <algorithm>

    // int * tempptr = dataptr;
    // dataptr = s.dataptr;
    // s.dataptr = tempptr;

    return *this;
    // 1.copy-2.swap-idiom: 1.passing by value, 2.swap with others, 3.return *this
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

// implement a non-member operator overloading function
SafeArray operator+(const SafeArray &a, int b)
{
    SafeArray result(a.get_size());  // element-wise adding b
    for (int i=0; i<result.get_size(); i++){
        result[i] = a[i]+b;
    }
    return result;
}

SafeArray operator+(int a, const SafeArray &b)
{
    return operator+(b,a);
}