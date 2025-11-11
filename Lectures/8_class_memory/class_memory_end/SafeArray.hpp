// This is final version of SafeArray.hpp
// Clear some comments from SafeArray5.hpp:

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

    // this is copy constructor
    SafeArray(const SafeArray &);
    // copy constructor is usually recognized by passing a const reference of object of same class

    // Side note here:
    // When an object is passed by value to a function, it first calls the copy constructor backend
    // e.g., when passing c1 to function1(Class c){do something with c},
    // the first step is essentially Class c(c1)

    // this is copy assignment
    SafeArray &operator=(SafeArray s);
    // copy assignment would update LHS, it has to include "&". The ReturnType is SafeArray
    // in args list, object is passed by value to this function operator=()
    // so it's calling copy constructor in the backend

    int get_size() const;
    int operator[](int) const; // overloading [] for SafeArray object to just access the information
    int &operator[](int);      // overloading [] for SafeArray object to update the information
};

SafeArray operator+(const SafeArray &, int); // pass by const reference
SafeArray operator+(int, const SafeArray &); // pass by const reference

#endif

// Note on non-member operator functions:
// Here we implement two non-member operator functions to support
// SafeArray + int and int + SafeArray operations.

// Conventionally, when overloading arithmetic operators (binary operators),
// if the left-hand side (LHS) operand is an object of the class,
// the operator is usually implemented as a non-member function.

// But if the operator is a unary operator,
// the operator is usually implemented as a member function.
// For example, operator++() to add 1 to all elements in SafeArray
// the prototype would be SafeArray &operator++(); implemented inside the class.
// & is needed since it would update the object itself and return *this.

// Its full implementation in .cpp could be like:
// SafeArray &SafeArray::operator++()
// {
//     for (int i = 0; i < size; i++)
//     {
//         dataptr[i] += 1;
//     }
//     return *this;
// }