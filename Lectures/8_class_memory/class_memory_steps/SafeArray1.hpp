// This is new SafeArray1.hpp
// create the SafeArray class with two private member variables
// and constructor, and a getter function
// Note that one member variable is a ptr

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

        int get_size() const;
};

#endif