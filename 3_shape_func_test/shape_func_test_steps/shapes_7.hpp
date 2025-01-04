// This is shapes_7.hpp
// Changes from shapes.cpp of starter code
// 1. add functions prototype and bodies
// 2. include necessary header libraries

#ifndef _SHAPES_HPP
#define _SHAPES_HPP

#include <cmath>
#include <string>

double conversion(std::string);
double area(double);
double area(double, double);
double area(double, double, double);

double conversion(std::string input_string)
{
    double output_number;
    try
    {
        output_number = std::stod(input_string);
    }
    catch (std::invalid_argument)
    {
        return -1;
    }
    return output_number;
}

double area(double r)
{
    return M_PI * pow(r, 2);
}
double area(double w, double l)
{
    return w * l;
}
double area(double a, double b, double angle)
{
    return 0.5 * a * b * sin(angle * M_PI / 180);
}

#endif
