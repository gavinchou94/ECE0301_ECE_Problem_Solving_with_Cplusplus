// This is template class version of SafeArray1.hpp
// changing from the starter code of SafeArray.hpp
// 1. add <typename T> to class, and explain where to add T and where not to
// 2. change array int elements to T elements
// 3. include SafeArray1.tpp at the end of the file

#ifndef _SAFE_ARRAY_HPP
#define _SAFE_ARRAY_HPP

template <typename T>
class SafeArray // no T here: a template argument list is not allowed in a declaration of a primary template
{
private:
    T *dataptr; // pointer to the array of T type
    int size;   // size of the array stays as int

public:
    SafeArray();          // default constructor
    SafeArray(int);       // parameterized constructor
    virtual ~SafeArray(); // destructor

    // This is copy constructor
    SafeArray(const SafeArray<T> &); // add <T> to the argument type

    // This is copy assignment
    SafeArray<T> &operator=(SafeArray<T>); // add <T> to the argument type

    int get_size() const;     // return size, stays as int
    T get(int) const;         // return T type
    virtual void set(int, T); // pass T type as second argument, set index to value
};

template <typename T>                            // this is non-member function, so we need to add <T> here
SafeArray<T> operator+(const SafeArray<T> &, T); // element-wise addition, return type is SafeArray<T>
                                                 // argument is also SafeArray<T>

template <typename T>
SafeArray<T> operator+(T, const SafeArray<T> &); // same as above

#include "SafeArray1.tpp" // include the template implementation file

#endif