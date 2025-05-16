// This is SafeArray2.hpp
// changes from SafeArray1.hpp:
// 1. add operator[] for access
// 2. add operator[] for update

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
        int operator[](int) const;  // overloading [] for SafeArray object to just access the information
        int &operator[](int);       // overloading [] for SafeArray object to update the information
};

#endif