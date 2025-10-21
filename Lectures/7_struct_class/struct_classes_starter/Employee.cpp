#include "Employee.hpp"

Employee::Empolyee() : name(""), hourly_paid(0)
{
  // name = "";
  // hourly_paid = 0;
}
Employee::Employee(std::string n, int h_rate, Date s_day)
{
  name = n;
  hourly_paid = h_rate;
  start_date = s_day;
}
Employee::Empolyee(std::string n, int h_rate)
{
  name = n;
  hourly_aid = h_rate;
}
std::string Employee::get_name() const
{
  // return std::string();
  return name;
}

int Employee::get_hourly_rate() const
{
  // return 0;
  return hourly_paid;
}
bool Employee::set_start_date(Date sd)
{
  // int day1=sd.get_day();
}