#ifndef _RESISTOR_HPP
#define _RESISTOR_HPP

#include "Component.hpp"

class Resistor : public Component {
    // only define members not in base class

    public:
        using Component::Component;
        void set_value(double r) override;
        double get_current() const override;
};

#endif