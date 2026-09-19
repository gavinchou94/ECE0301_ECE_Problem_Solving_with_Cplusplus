// This is shapes_1.hpp
// Changes compared to header_test_starter.cpp:
// - Adds the function prototypes and function bodies that were originally in header_test_starter.cpp.
// - Includes the needed header libraries.
// - Adds include guards.

#ifndef SHAPES_HPP // Include guard; it prevents multiple inclusion.
#define SHAPES_HPP // Use the same name as the file name when possible.

#include <cmath>
#include <iostream>
#include <string>

double conversion(std::string);
double area(double);
double area(double, double);
double area(double, double, double);

// Convert a labeled string to a double.
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

// Two sides and one angle version.
double area(double a, double b, double sinC)
{
  return 0.5 * a * b * sinC;
}

#endif // End the include guard.