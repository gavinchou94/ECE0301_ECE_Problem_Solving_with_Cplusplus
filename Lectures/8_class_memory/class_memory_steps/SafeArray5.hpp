// This is SafeArray5.hpp
// changes from SafeArray4.hpp:
// add two non-member operator functions

#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

class SafeArray {
    private:
        int * dataptr;
        int size;
    
    public:
        SafeArray();
        SafeArray(int);
        ~SafeArray(); // has to include this due to dataptr

        // this is copy constructor
        SafeArray(const SafeArray&); 
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
        int operator[](int) const;  // overloading [] for SafeArray object to just access the information
        int &operator[](int);       // overloading [] for SafeArray object to update the information
};

SafeArray operator+(const SafeArray&, int); // pass by const reference
SafeArray operator+(int, const SafeArray&); // pass by const reference

#endif