#include "Frequency.hpp"

#include <stdexcept>
#include <cmath>

// TODO: default constructor and constructor with args

// TODO: accessors

// provided: assign zero amplitudes to frequencies
void Frequency::zeros()
{
    for (int i = 0; i < num_components; i++)
    {
        freq_data[i].frequencies = static_cast<double>(i) * increment;
        freq_data[i].amplitudes = 0.0;
    }
}

// TODO: assign constant amplitudes to all frequencies

// TODO: gaussian build-up

bool Frequency::operator==(const Frequency &fcomp) const
{
    // TODO: overloaded operators
    return true;
}

// provided: exports
void Frequency::export_frequency(double freq[], double amps[]) const
{
    for (int i = 0; i < num_components; i++)
    {
        freq[i] = freq_data[i].frequencies;
        amps[i] = freq_data[i].amplitudes;
    }
}

bool Frequency::export_csv(const std::string &outfile) const
{
    std::ofstream filewrite(outfile + ".csv");
    if (!filewrite.fail())
    {
        filewrite << "w, |F(w)|" << std::endl;
        for (int i = 0; i < num_components; i++)
        {
            filewrite << freq_data[i].frequencies << ", " << freq_data[i].amplitudes << std::endl;
        }
        // Close file
        filewrite.close();
        return true;
    }
    return false;
}