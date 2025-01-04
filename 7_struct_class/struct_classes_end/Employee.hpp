// This is final version of Employee.hpp
// clear some comments of Employee_7.hpp

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
#include "Date.hpp" // this is needed for starting_day private attribute

class Employee{

    private: // attributes are typically set as private
        std::string name;
        int hourly_paid;
        Date starting_day;

    public: // public member function are methods that give APIs to code outside class
        Employee(std::string n, int p, Date d);
        Employee();
        std::string get_name() const;
        int get_hourly_rate() const;
        Date get_starting_date() const;
        bool set_name(std::string);
        bool set_hourly_rate(int);
        bool set_starting_date(Date);
        int get_weekly_rate() const;
        int get_yearly_rate() const;
};

#endif