// This is Employee_3.hpp
// Changes from Employee_2.hpp:
// other methods inside the class that don't modify private attributes

#ifndef _EMPLOYEE_H // this demonstrates how you should write header file
#define _EMPLOYEE_H // guards to prevent repeated inclusions

#include <string>

struct Date{
    int year;
    int month;
    int day;
}; // ADT Date is a struct that has three int-type fields: year/month/day

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