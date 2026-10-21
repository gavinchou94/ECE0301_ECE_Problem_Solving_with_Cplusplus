#include "Employee.hpp"

Employee::Employee(std::string n, int hp, Date sd) : name(n), hourly_paid(hp), starting_day(sd)
{
  // name = n;
  // hourly_paid = hp;
  // starting_day = sd;
}

Employee::Employee() : name(""), hourly_paid(0), starting_day({1900, 1, 1})
{
}

std::string Employee::get_name() const
{
  return name;
}

int Employee::get_hourly_paid() const
{
  return hourly_paid;
}

Date Employee::get_starting_date() const
{
  return starting_day;
}

bool Employee::set_name(std::string n)
{
  name = n;
  return true;
}

bool Employee::set_hourly_paid(int hp)
{
  hourly_paid = hp;
  return true;
}

bool Employee::set_starting_date(Date sd)
{
  starting_day = sd;
  return true;
}

int Employee::get_weekly_paid() const
{
  return hourly_paid * 40;
}

int Employee::get_yearly_paid() const
{
  return hourly_paid * 40 * 52;
}