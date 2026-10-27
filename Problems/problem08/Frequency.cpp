#include "Frequency.hpp"

#include <cmath>
#include <stdexcept>

// Default constructor.

// Constructor with the number of components and the increment.

// Accessors.

// Provided: assign zero amplitudes to all frequencies.
void Frequency::zeros()
{
  for (int i = 0; i < num_components; i++)
  {
    freq_data[i].frequencies = static_cast<double>(i) * increment;
    freq_data[i].amplitudes = 0.0;
  }
}

// Assign a constant amplitude to all frequencies.

// Set the amplitude of one frequency component.

// Gaussian spectrum.

// Equal to operator.
bool Frequency::operator==(const Frequency &fcomp) const
{
  return true;
}

// Smaller or equal operator.

// Far greater than operator.

// Multiply operator.

// Number of Frequency objects created.

// Provided: exports.
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