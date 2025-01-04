// This is new UniqueArray3.hpp
// 1. a derived class method set( , ) is added
// 2. based on "virtual" or not in base class, this one overrides or redefines base class

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray3.hpp"

class UniqueArray: public SafeArray{
    public:
        // all public member functions(except constructors) of SafeArray class are inherited
        
        using SafeArray::SafeArray; 
        // above is how to construct a derived class, same as using the following two lines
        // SearchableArray();
        // SearchableArray(int);
        
        void set(int, int);         //overridden derived class function
        //if "virtual" is not added to SafeArray base class, 
        //this simply redefines derived class function
};

#endif