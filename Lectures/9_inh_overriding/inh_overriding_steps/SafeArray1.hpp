// This is SafeArray1.hpp
// Changes from starter code of SafeArray.hpp
// 1. change [] const to get() for accessing
// 2. change &[] to set ( , ) for updating

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

        // this is copy assignment
        SafeArray &operator=(SafeArray);

        int get_size() const;
        //int operator[](int) const;  // overloading [] for SafeArray object to just access the information
        int get(int) const;           // change [] to get() for SafeArray object to access
        //int &operator[](int);       // overloading [] for SafeArray object to update the information
        void set(int, int);           // change [] to set( , ) for SafeArray object to update
};

SafeArray operator+(const SafeArray&, int); // pass by const reference
SafeArray operator+(int, const SafeArray&); // pass by const reference

#endif