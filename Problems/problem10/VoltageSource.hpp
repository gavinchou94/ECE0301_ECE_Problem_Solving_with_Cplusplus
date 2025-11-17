#ifndef _VOLTAGE_SOURCE_HPP
#define _VOLTAGE_SOURCE_HPP

#include "Component.hpp"

class VoltageSource : public Component
{
    // only define private members not in base class
    // most likely none needed

public:
    using Component::Component;
    double get_voltage() const override;
};

#endif