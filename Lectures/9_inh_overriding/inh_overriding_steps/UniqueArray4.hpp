// This is UniqueArray4.hpp
// Add "override" at Line 12 since it expects to override base class function
// "override" reaffirms the "virtual" at Line 27 of SafeArray4.hpp
// "final" is an indicator that UniqueArray::set() cannot be overridden in its children classes

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray4.hpp"

class UniqueArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        void set(int, int) override final;
};

#endif