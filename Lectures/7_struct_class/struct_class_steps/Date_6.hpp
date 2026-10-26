// This is Date_6.hpp
// Changes compared to Date_5.hpp:
// - overloading operator as member function
// - overloading operator as non-member function

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
  static const int min_year;
  bool operator==(const Date &) const; // operator usually just takes arg as const reference
};

bool operator<(const Date &, const Date &); // non-member operator, or non-member function

#endif