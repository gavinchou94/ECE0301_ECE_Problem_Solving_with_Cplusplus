// This is Date2c.hpp file, change from Date.hpp of the starter code is:
// 1. Add a default constructor, which sets the date to Jan 1, min_year
// 2. Make sure we have == operator for Date class
// 3. If needed, implement custom copy constructor and assignment operator

#ifndef _DATE_H
#define _DATE_H

enum MONTH {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

class Date{
    private:
        int year;
        MONTH month;
        int day;
    public:
        Date();
        Date(int y, MONTH m, int d);
        int get_year() const;
        MONTH get_month() const;
        int get_day() const;
        bool set_year(int);
        bool set_month(MONTH);
        bool set_day(int);
        static const int min_year;
        bool operator==(const Date&);
};

bool operator<(const Date&, const Date&);

#endif