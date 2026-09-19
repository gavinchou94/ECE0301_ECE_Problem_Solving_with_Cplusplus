// This is shapes_2.hpp
// Changes compared to shapes_1.hpp:
// - Adds two overloaded area functions.
// - Shows examples of the ternary operator and static_cast.

#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <cmath>
#include <iostream>
#include <string>

double conversion(std::string);
double area(double);
double area(double, double);
double area(double, double, double);
double area(double, double, float); // Create for sides a, b, c to show the ternary operator.
double area(int, int, int);         // Create to show static_cast.

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

// Another overloaded function example with different parameter types.
// This function is not used in the main program; it is provided for demonstration.
// c is one side length; a and b are the other side lengths.
// Three sides as real numbers.
double area(double a, double b, float c)
{
  double result;
  // Assume a <= b <= c.
  // The math suggests that if a + b <= c, the following formula will return <= -1.
  double cosC = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b);

  // Syntax: condition ? value_if_true : value_if_false.
  // e.g., x = (a > b) ? 4 : 5; if a > b, then x = 4; otherwise, x = 5.
  result = (cosC <= -1) ? -1 : 0.5 * a * b * sqrt(1 - pow(cosC, 2));
  // Use -1 to indicate an invalid result.
  return result;
}

// Another overloaded function example with different parameter types.
// This function is not used in the main program; it is provided for demonstration.
// a, b, and c are three integer side lengths.
// Three sides as integers.
double area(int a, int b, int c)
{
  // Using (a * a + b * b - c * c) / (2 * a * b) directly would cause integer division.
  // static_cast<double> converts an integer to a double.
  double cosC = static_cast<double>(a * a + b * b - c * c) / (2 * a * b);
  return 0.5 * a * b * sqrt(1 - pow(cosC, 2));

  // Commonly used static_cast examples:
  // static_cast<double>(int_var)
  // static_cast<int>(double_var)
  // static_cast<int>(char_var)
}

#endif