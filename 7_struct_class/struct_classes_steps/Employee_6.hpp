// This is Employee_6.hpp
// Changes from Employee_5.hpp:
// updating header file

#ifndef _EMPLOYEE_H // this demonstrates how you should write header file
#define _EMPLOYEE_H // guards to prevent repeated inclusions

#include <string>
#include "Date_6.hpp" // this is needed for starting_day private attribute

// struct Date{
//     int year;
//     int month;
//     int day;
// }; // Date is no longer a struct, it is a class now

class Employee{

    private: // attributes are typically set as private
        std::string name;
        int hourly_paid;
        Date starting_day;

    public: // public member function are methods that give APIs to code outside class
        Employee(std::string n, int p, Date d); // a function that shares the same name as the class is called constructor
        Employee(); // function of the identical name but with different arg list is called overloaded function
        std::string get_name() const;
        int get_hourly_rate() const;
        Date get_starting_date() const;
        bool set_name(std::string);
        bool set_hourly_rate(int);
        bool set_starting_date(Date);
        int get_weekly_rate() const;
        int get_yearly_rate() const; // create some other public member functions that do some calculations
};

#endif