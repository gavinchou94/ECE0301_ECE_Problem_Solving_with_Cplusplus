// This is SafeArray3.hpp
// changes from SafeArray2.hpp:
// 1. add copy constructor
// 2. add note about object passed by value to a function

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

        int get_size() const;
        int operator[](int) const;  // overloading [] for SafeArray object to just access the information
        int &operator[](int);       // overloading [] for SafeArray object to update the information
};

#endif