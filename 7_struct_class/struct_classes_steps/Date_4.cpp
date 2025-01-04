// This is a new Date_4.cpp
// Note the following items:
// 1. Date is no longer a struct, it is now a class
// 2. A typical class .cpp file implements constructor, getters, setters

#include "Date_4.hpp"

Date::Date(int y, int m, int d): year(y), month(m), day(d)
{
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