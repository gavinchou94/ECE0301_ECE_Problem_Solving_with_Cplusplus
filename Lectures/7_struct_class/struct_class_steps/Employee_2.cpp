// This is Employee_2.cpp
// Changes compared to Employee_1.cpp:
// - implements an overloaded constructor with no args
// - implements setter functions

#include "Employee_2.hpp"

Employee::Employee(std::string n, int p, Date d) : name(n), hourly_paid(p), starting_day(d)
{
}

Employee::Employee() : name(""), hourly_paid(0), starting_day({1900, 1, 1})
{
}

std::string Employee::get_name() const
{
  return name; // private attribute name can be used since Employee class private definition is visible
}

int Employee::get_hourly_rate() const
{
  return hourly_paid;
}

Date Employee::get_starting_date() const
{
  return starting_day;
}

bool Employee::set_name(std::string n)
{
  name = n;    // passing the arg to private attribute
  return true; // if success, return true
}

bool Employee::set_hourly_rate(int p)
{
  hourly_paid = p;
  return true;
}

bool Employee::set_starting_date(Date d)
{
  starting_day = d;
  return true;
}