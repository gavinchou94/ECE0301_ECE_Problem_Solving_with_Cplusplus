// This is final version of SafeArray.hpp
// Clear some comments from SafeArray5.hpp:

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
        SafeArray &operator=(SafeArray s);

        int get_size() const;
        int operator[](int) const;  // overloading [] for SafeArray object to just access the information
        int &operator[](int);       // overloading [] for SafeArray object to update the information
};

SafeArray operator+(const SafeArray&, int); // pass by const reference
SafeArray operator+(int, const SafeArray&); // pass by const reference

#endif