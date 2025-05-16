// This is Employee_2.hpp
// Changes from Employee_1.hpp:
// 1. another overloaded constructor that takes no args
// 2. addition of setter functions in public methods

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
        // The above three set_xxx() functions are called setters, created to modify private attributes
        // These functions take args of corresponding attributes and return true/false
};

#endif