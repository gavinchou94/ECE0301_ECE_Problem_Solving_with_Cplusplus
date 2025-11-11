// This is final version of UniqueArray.hpp

#ifndef _UNIQUE_ARRAY_HPP
#define _UNIQUE_ARRAY_HPP

#include "SafeArray.hpp"

class UniqueArray : public SafeArray
{
public:
    using SafeArray::SafeArray;
    void set(int, int) override final;
    // If "virtual" is not added to SafeArray base class, this "override" would cause compile error
    // "virtual" in SafeArray base class is a must, "override" in derived class is optional but recommended

    // "final" is optional but using it prevents further overriding in UniqueArray's child classes
    // it is also okay by using "virtual void set(int, int) override final;"
};

#endif