#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <fstream>
#include <string>

// Frequency class declaration.
class Frequency
{
public:
  // Provided: maximum number of frequency components.
  static const int MAX_COMPONENTS_NUM = 1001;

  // Other public functions go here.

  // Equal to operator (declaration given).
  bool operator==(const Frequency &fcomp) const;

  // Provided: assign zero amplitudes to all frequencies.
  void zeros();

  // Provided: exports.
  void export_frequency(double freq[], double amps[]) const;
  bool export_csv(const std::string &outfile) const;

private:
  // Provided: Cpnt struct and private members. Do not change these.
  struct Cpnt
  {
    double frequencies;
    double amplitudes;
  };

  int num_components;
  double increment;
  Cpnt freq_data[MAX_COMPONENTS_NUM];

  // Other private members go here.
};

#endif