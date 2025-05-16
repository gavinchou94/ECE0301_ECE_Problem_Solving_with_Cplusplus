#include <stdexcept>
#include "Date.hpp"

// Minimum valid year for a Date object
const int Date::min_year = 1900;

Date::Date(int y, MONTH m, int d): month(m), day(d)
{
    set_year(y); // calling set_year() to validate and set the year, will throw an exception if the year is invalid
}

int Date::get_year() const
{
    return year;
}

MONTH Date::get_month() const
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

bool Date::set_month(MONTH m)
{
    month = m;
    return true;
}

bool Date::set_day(int d)
{
    day = d;
    return true;
}

bool Date::operator==(const Date &d)
{
    return year == d.year && month == d.month && day == d.day;
}

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