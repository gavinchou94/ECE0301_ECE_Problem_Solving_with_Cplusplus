// This is Date_6.hpp
// Changes from Date_5.hpp
// 1. adding operator as member function
// 2. adding operator as non-member function

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
        bool operator==(const Date&); // operator usually just takes arg as const reference
};

bool operator<(const Date&, const Date&); //non-member operator, or non-member function

#endif