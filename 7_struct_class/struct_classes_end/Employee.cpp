// This is final version of Employee.cpp
// Clear comments from Employee_7.cpp

#include "Employee.hpp"

// this is the constructor function
Employee::Employee(std::string n, int p, Date d): starting_day(d)
{
   name = n; // LHS is attribute, RHS is function args
   hourly_paid = p;
}

// this is another constructor function that sets default attributes to be blank,0,{1900,1,1}
Employee::Employee(): name(""), hourly_paid(0), starting_day(Date::min_year,JAN,1)
{
}

std::string Employee::get_name() const
{
    return name;
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
    name = n;
    return true;
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
    return hourly_paid*70;
}

int Employee::get_yearly_rate() const
{
    return get_weekly_rate()*52;
}