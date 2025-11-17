#ifndef _CURRENT_SOURCE_HPP
#define _CURRENT_SOURCE_HPP

#include "Component.hpp"

class CurrentSource : public Component
{
    // only define private members not in base class
    // most likely none needed

public:
    using Component::Component;
    double get_current() const override;
};

#endif