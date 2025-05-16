// This is Date_6.cpp
// Changes from Date_5.cpp
// 1. implements member function for operator == 
// 2. implements non-member function for operator <

#include "Date_6.hpp"
#include <stdexcept> // this is required for throw

const int Date::min_year = 1900;

Date::Date(int y, int m, int d): month(m), day(d)
{
    set_year(y); // calling set_year() would also trigger throw exception
}

int Date::get_year() const
{
    return year;
}

int Date::get_month() const
{
    return month;
}

int Date::get_day() const
{
    return day;
}

bool Date::set_year(int y)
{
    if (y<min_year){
        throw std::invalid_argument{"invalid year"};
    }
    year = y;
    return true;
}

bool Date::set_month(int m)
{
    month = m;
    return true;
}

bool Date::set_day(int d)
{
    day = d;
    return true;
}

// customed operator == for class Date to directly compare two objects
// :: to indicate it is a member function
// can use get_year(), or directly .year
bool Date::operator==(const Date &d)
{
    //if (year == d.get_year() && month == d.get_month() && day == d.get_day())
    if (year == d.year && month == d.month && day == d.day)
    {
        return true;
    }
    return false;
}

// customed operator < for class Date to directly compare two objects
// not having :: indicates that it is a non-member function
// should use get_year(), not .year
bool operator<(const Date &d1, const Date &d2)
{
    if (d1.get_year() < d2.get_year()){
        return true;
    }
    if (d1.get_year() == d2.get_year() && d1.get_month() < d2.get_month()){
        return true;
    }
    if (d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month() && d1.get_day() < d2.get_day()){
        return true;
    }
    return false;
}