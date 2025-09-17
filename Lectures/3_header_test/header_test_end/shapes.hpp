// Your Name here
#ifndef SHAPES_HPP // these two lines and last line is called header guardian
#define SHAPES_HPP // to avoid multiple inclusion of this header file
                   // it is a good practice to use the file name in uppercase, but not a requirement

#include <string>
#include <iostream>
#include <cmath>

int GLOBAL = 42;

double conversion(std::string);
double area(double);
double area(double, double);
double area_with_default_side(double, double = 10.0);
double area(double, double, double);
double area(double, double, float); // create for sides a, b, c to show ternary
double area(int, int, int);         // create to show static_cast
int sum(int, int);                  // create to test passing by value
int sum2(int &, int);
bool calculations(int a, int b, int c);

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

double area_with_default_side(double w, double l)
{
    return w * l;
}

double area(double a, double b, double sinC)
{
    return 0.5 * a * b * sinC;
}

double area(double a, double b, float c)
{
    double result;

    // assume a<=b<=c;
    double cosC = (pow(a, 2) + pow(b, 2) - pow(c, 2)) * (2.0 * a * b);
    // x = (a>b)? 4:5; that is if a>b then x=4 else x=5
    result = (cosC <= -1) ? -1 : 0.5 * a * b * sqrt(1 - pow(cosC, 2));
    return result;
}

double area(int a, int b, int c)
{
    double cosC = static_cast<double>(a * a + b * b - c * c) / (2 * a * b);
    return 0.5 * a * b * sqrt(1 - pow(cosC, 2));

    // Commonly used static_cast examples:
    // static_case<double>(int_var)
    // static_case<int>(double_var)
    // static_case<int>(char_var)
}

int sum(int a, int b)
{
    int result = a + b;
    a = a + 100;
    std::cout << "a within the sum function is " << a << std::endl;
    return result;
}

int sum2(int &a, int b)
{
    int result = a + b;
    a = a + 100;
    std::cout << "a within the sum2 function is " << a << std::endl;
    return result;
}

bool calculations(int a, int b, int c)
{
    GLOBAL = GLOBAL + 1;
    std::cout << "GLOBAL is " << GLOBAL << std::endl;
    return true;
}

#endif