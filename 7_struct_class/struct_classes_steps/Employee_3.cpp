// This is Employee_3.cpp
// Changes from Employee_2.cpp
// implements other methods inside the class

#include "Employee_3.hpp"

// this is the constructor function
Employee::Employee(std::string n, int p, Date d)
{
   name = n; // LHS is attribute, RHS is function args
   hourly_paid = p;
   starting_day = d;
} // as from the name, constructor initializes the object 
// by assigning the args to object's private attributes

// Below is a better way for constructor function: in-line constructor
// Employee::Employee(): name(""), hourly_paid(0), starting_day({1900,1,1})
// {
// }

// this is another constructor function that sets default attributes to be blank,0,{1900,1,1}
Employee::Employee(): name(""), hourly_paid(0), starting_day({1900,1,1})
{
}

std::string Employee::get_name() const
{
    return name; // private attribute name can be used since we are now inside Employee class
}

int Employee::get_hourly_rate() const
{
    return hourly_paid; // private attribute hourly_paid can be used, see above
}

Date Employee::get_starting_date() const
{
    return starting_day; // private attribute starting_day can be used, see above
}

bool Employee::set_name(std::string n)
{
    name = n; // passing the arg to private attribute
    return true; // if success, return true
}

bool Employee::set_hourly_rate(int p)
{
    hourly_paid = p; // same as above
    return true;
}

bool Employee::set_starting_date(Date d)
{
    starting_day = d; // same as above
    return true;
}

int Employee::get_weekly_rate() const // this public function doesn't update private attributes
{
    return hourly_paid*70; // assuming someone is working extremely hard (70 hours/week)
}

int Employee::get_yearly_rate() const // this public function doesn't update private attributes
{
    return get_weekly_rate()*52;
}

// note that member function definition line has class-name:: before function