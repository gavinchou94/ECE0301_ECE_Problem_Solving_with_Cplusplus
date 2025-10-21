#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
#include "Date.hpp"

class Employee{
  private: //set the attributes of a class, private
    std::string name;
    int hourly_paid;
    Date start_date;

  public: //define public functions of a class, API, public
    Empolyee();
    Empolyee(std::string n,);
    Empolyee(std::string n,)
    std::string get_name(); // think this a prototype
    int get_hourly_rate(); // think this a prototype

    
};

#endif