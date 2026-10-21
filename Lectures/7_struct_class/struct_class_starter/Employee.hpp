#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

struct Date
{
  int year;
  int month;
  int day;
};

class Employee
{
private:
  std::string name;
  int hourly_paid;
  Date starting_day;

public:
  // constructor prototypes
  Employee(std::string, int, Date);
  Employee();

  // function propotypes
  std::string get_name() const;
  int get_hourly_paid() const;
  Date get_starting_date() const;

  // function propotypes
  bool set_name(std::string);
  bool set_hourly_paid(int);
  bool set_starting_date(Date);

  // some calculation
  int get_weekly_paid() const;
  int get_yearly_paid() const;
};

#endif