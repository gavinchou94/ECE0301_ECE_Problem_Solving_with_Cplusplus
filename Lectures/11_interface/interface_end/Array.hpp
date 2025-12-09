// This file is expected to contain the declaration of the Array class (a re-based class, pure virtual)
// SafeArray class is now derived from Array class

#ifndef _ARRAY_HPP
#define _ARRAY_HPP

template <typename T>
class Array // pure virtual (interface) class
{
public:                               // don't forget the public access specifier
    virtual int get_size() const = 0; // virtual with = 0 makes it a pure virtual function
    virtual T get(int) const = 0;     // virtual with = 0 makes it a pure virtual function
    virtual void set(int, T) = 0;     // virtual with = 0 makes it a pure virtual function
};

#endif