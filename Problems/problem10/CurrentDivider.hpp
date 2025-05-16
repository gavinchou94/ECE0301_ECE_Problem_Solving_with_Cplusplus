#ifndef _CURRENT_DIVIDER_HPP
#define _CURRENT_DIVIDER_HPP

#include "Network.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"

class CurrentDivider : public Network {

    private:
        // TODO: little to no here, only add private ones when necessary

    public:
        CurrentDivider(double c, double res[], int num_res);
        int get_num_resistors() const;
        double get_source_current() const;
        double get_resistance(int idx) const;
        double get_resistor_voltage() const;
        double get_resistor_current(int idx) const;

        void set_source_current(double c);
        void set_resistance(int idx, double r);

};

#endif
