// This is new UniqueArray3.hpp
// 1. a derived class method set( , ) is added
// 2. based on "virtual" or not in base class, set() here overrides or redefines set() of base class

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray3.hpp"

class UniqueArray : public SafeArray // all public member functions(except constructors) of SafeArray class are inherited
{
public:
    using SafeArray::SafeArray;
    // above line also tells how to construct a derived class, same as using the following constructors
    // SearchableArray();
    // SearchableArray(int);
    // SearchableArray(const SearchableArray &);

    void set(int, int); // derived class function overriding or redefining base class function
    // If "virtual" is not added to SafeArray base class, this redefines derived class function
    // If "virtual" is added to SafeArray base class, this overrides derived class function
};

#endif