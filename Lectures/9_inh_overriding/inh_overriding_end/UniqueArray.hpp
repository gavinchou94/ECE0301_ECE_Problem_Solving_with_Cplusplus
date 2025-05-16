// This is final version of UniqueArray.hpp

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

class UniqueArray: public SafeArray{
    public:
        using SafeArray::SafeArray; 
        void set(int, int) override final;
};

#endif