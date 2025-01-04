// This is Date_5.hpp
// Changes from Date_4.hpp
// adding static variable

#ifndef _DATE_H
#define _DATE_H

class Date{
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
};

#endif