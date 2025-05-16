// This is SafeArray2.hpp
// No changes from SafeArray1.hpp

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
        int get(int) const;
        void set(int, int);
};

SafeArray operator+(const SafeArray&, int); // pass by const reference
SafeArray operator+(int, const SafeArray&); // pass by const reference

#endif