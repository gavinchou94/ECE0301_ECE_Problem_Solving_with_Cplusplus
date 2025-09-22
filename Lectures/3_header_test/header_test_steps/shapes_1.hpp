// This is shapes_1.hpp, it is composed from scratch
// 1. add functions prototype and bodies, originally in header_test_starter.cpp
// 2. include necessary header libraries
// 3. add include guards

#ifndef _SHAPES_HPP // include guard, it prevents multiple inclusion
#define _SHAPES_HPP // It is a good practice to use the same name as the file name

#include <cmath>
#include <iostream>
#include <string>

double conversion(std::string);
double area(double);
double area(double, double);
double area(double, double, double);

// we expect to have a function converting string to double
// "a = 3.14"  -->  3.14
// "r = 2.71"  -->  2.71
double conversion(std::string input_string)
{
    int equals_index = input_string.find("=");

    if (equals_index == std::string::npos)
    {
        std::cout << "Input formatting error" << std::endl;
        return -1;
    }

    std::string number_string = input_string.substr(equals_index + 2, input_string.length());
    double value;
    try
    {
        value = std::stod(number_string);
    }
    catch (std::invalid_argument)
    {
        std::cout << "Invalid input, must be a number" << std::endl;
        return -1;
    }
    return value;
}

double area(double r)
{
    return M_PI * pow(r, 2);
}

double area(double w, double l)
{
    return w * l;
}

double area(double a, double b, double sinC)
{
    return 0.5 * a * b * sinC;
}

#endif // make sure to end the include guard