#ifndef _FREQUENCY_HPP
#define _FREQUENCY_HPP

#include <fstream>

class Frequency
{
public:
    // provided: max components
    static const int MAX_COMPONENTS_NUM = 1001;

    // TODO: default constructor and constructor with args

    // TODO: accessors

    // provided: assign zero amplitudes to all frequencies
    void zeros();

    // TODO: assign constant amplitudes to all frequencies

    // TODO: gaussian

    // TODO: overloaded operators (==, <=, >>, ^)
    bool operator==(const Frequency &fcomp) const; // first one looks like such

    // provided: exports
    void export_frequency(double freq[], double amps[]) const;
    bool export_csv(const std::string &outfile) const;

private:
    // provided: Cpnt struct, private members
    struct Cpnt
    {
        double frequencies;
        double amplitudes;
    };

    int num_components;
    double increment;
    Cpnt freq_data[MAX_COMPONENTS_NUM];
};

#endif