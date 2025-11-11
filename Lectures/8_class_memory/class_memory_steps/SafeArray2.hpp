// This is SafeArray2.hpp
// changes from SafeArray1.hpp:
// 1. add operator[] for access
// 2. add operator[] for update

#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

class SafeArray
{
private:
    int *dataptr;
    int size;

public:
    SafeArray();
    SafeArray(int);
    ~SafeArray(); // has to include this due to dataptr

    int get_size() const;
    int operator[](int) const; // overloading [] for SafeArray object to just access the information
    int &operator[](int);      // overloading [] for SafeArray object to update the information
};

#endif

// Notation on prototype of int &operator[](int):

// First "int" is the return type, which says this function would return an int.
// "&" means it would return a reference, so that it can be used on LHS for update.
// operator[] means we are overloading the [] operator for SafeArray class
// (int) means this function takes one int argument, which is the index inside []

// The prototype is different from int operator[](int) const so it can be compiled correctly.