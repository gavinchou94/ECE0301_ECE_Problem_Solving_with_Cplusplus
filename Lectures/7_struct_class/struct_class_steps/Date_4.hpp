// This is a new Date_4.hpp
// Note the following items:
// - header file guards
// - typical private attributes and public functions (constructors, getters, setters)

#ifndef DATE_HPP
#define DATE_HPP

class Date
{
private:
  int year;
  int month;
  int day;

public:
  Date(int y, int m, int d);
  int get_year() const;
  int get_month() const;
  int get_day() const;
  bool set_year(int);
  bool set_month(int);
  bool set_day(int);
};

#endif