// This is a new Employee_1.hpp
// Note the following items:
// - header file guards
// - the declaration of struct Date
// - declaration of a class with private attributes and public functions
// - class constructor function and getter functions

#ifndef EMPLOYEE_HPP // this demonstrates how you should write header file
#define EMPLOYEE_HPP // guards to prevent repeated inclusions

#include <string>

struct Date
{
  int year;
  int month;
  int day;
}; // ADT Date is a struct that has three int-type fields: year/month/day

class Employee
{
private: // attributes are typically set as private
  std::string name;
  int hourly_paid;
  Date starting_day; // starting_day attribute is of Date type

public:
  Employee(std::string n, int p, Date d); // a function that shares the same name as the class is called constructor
  std::string get_name() const;
  int get_hourly_rate() const;
  Date get_starting_date() const;
  // The above three get_xxx() functions are called getters, created to access info only
  // These functions don't modify object's private attributes, indicated by "const"
  // These functions don't have args, and their return types are same as corresponding attributes
};

#endif