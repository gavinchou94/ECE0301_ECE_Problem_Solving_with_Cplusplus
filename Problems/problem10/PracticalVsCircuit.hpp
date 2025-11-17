#ifndef _PRACTICALVSCIRCUIT_HPP
#define _PRACTICALVSCIRCUIT_HPP

#include "VoltageDivider.hpp"

class PracticalVsCircuit : public VoltageDivider
{
private:
  // TODO: little to no here, only add private ones when necessary
public:
  PracticalVsCircuit(double vs, double rs, double rl);
  virtual double get_source_voltage() const override;
  void set_load(double rl);
  double get_load_power() const;
  bool maximum_power_transfer(double rl);
};

#endif