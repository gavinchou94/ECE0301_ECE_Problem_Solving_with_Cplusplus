// This is SafeArray4.hpp
// changes from SafeArray3.hpp:
// 1. add copy assignment
// 2. add note about copy-swap-idiom

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

#endif

// Note on copy-swap-idiom:
// In the copy assignment operator above, we use copy-swap-idiom:
// 1. passing by value: SafeArray s (this would call copy constructor to create a copy of RHS object)
// 2. swap the member variables of this object with the copy object's member variables
// 3. return *this

// This approach would automatically handle self-assignment case and
// also free old memory properly when the copy object goes out of scope.
// this object's old memory is now owned by the copy object after swap,
// so when copy object gets destructed (i.e., once this operator=() function finishes)
// these old memory would be freed properly.

// Everything has two sides though, the downside of copy-swap-idiom is
// that it would create a copy of RHS object first, which might be expensive if the object is large.