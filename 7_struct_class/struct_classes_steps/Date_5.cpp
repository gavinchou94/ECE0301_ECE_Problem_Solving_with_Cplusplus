// This is Date_5.cpp
// Changes from Date_4.cpp
// 1. define the static variable as public class member
// 2. setter function arg validation via throwing exception
// 3. calling set_year() in constructor

#include "Date_5.hpp"
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