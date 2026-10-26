// This is Date_7.hpp
// Changes compared to Date_6.hpp:
// - set private attribute to be enum type MONTH, instead of int type
// - change all return types of month from int to MONTH

#ifndef DATE_HPP
#define DATE_HPP

enum MONTH
{
  JAN = 1,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
};

class Date
{
private:
  int year;
  MONTH month;
  int day;

public:
  Date(int y, MONTH m, int d);
  int get_year() const;
  MONTH get_month() const;
  int get_day() const;
  bool set_year(int);
  bool set_month(MONTH);
  bool set_day(int);
  static const int min_year;
  bool operator==(const Date &) const; // operator usually just takes arg as const reference
};

bool operator<(const Date &, const Date &); // non-member operator, or non-member function

#endif