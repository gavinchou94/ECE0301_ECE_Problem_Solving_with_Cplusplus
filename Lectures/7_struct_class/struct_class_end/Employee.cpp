#include "Employee.hpp"

Employee::Employee(std::string n, int p, Date d) : name(n), hourly_paid(p), starting_day(d)
{
}

Employee::Employee() : name(""), hourly_paid(0), starting_day(Date::min_year, JAN, 1)
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

int Employee::get_weekly_rate() const
{
  return hourly_paid * 70; // assuming someone is working extremely hard (70 hours/week)
}

int Employee::get_yearly_rate() const
{
  return get_weekly_rate() * 52;
}