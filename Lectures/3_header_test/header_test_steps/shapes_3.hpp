// This is shapes_3.hpp
// Changes compared to shapes_2.hpp:
// - Adds two functions to test passing by value and passing by reference.
// - Adds a function with a default argument example.

#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <cmath>
#include <iostream>
#include <string>

double conversion(std::string);
double area(double);
double area(double, double);
double area_with_default_side(double, double = 10.0);
// Do not use the same function name here because the default argument can be confused with an overload.
double area(double, double, double);
double area(double, double, float); // Create for sides a, b, c to show the ternary operator.
double area(int, int, int);         // Create to show static_cast.
int sum1(int, int, std::string);                 // Create to test passing by value.
int sum2(int &, int, std::string &);               // Create to test passing by reference.
std::string append(int, int, std::string); 

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

double area_with_default_side(double w, double l)
{
  return w * l;
  // Call with one argument; the other argument uses the default value.
  // e.g., area_with_default_side(5.0) is treated as area_with_default_side(5.0, 10.0).

  // Call with two arguments; both arguments use the provided values.
  // e.g., area_with_default_side(5.0, 6.0) uses exactly those two values.

  // Why not name this function area with one default argument?
  // For example: double area(double w, double l = 10.0) { xxx
  // }
  // This would confuse the compiler with double area(double) when calling area(5.0).
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

int sum1(int a, int b, std::string subject)
{
  int result = a + b;
  a = a + 100;
  subject = "E" + subject;
  std::cout << "Within the sum1 function (pass by value) : " << subject << a << std::endl;
  return result;
}

int sum2(int &a, int b, std::string &subject)
{
  int result = a + b;
  a = a + 100;
  subject = "E" + subject;
  std::cout << "Within the sum2 function (pass by reference) : " << subject << a << std::endl;
  return result;
}

std::string append(int a, int b, std::string subject)
{
  int result = a + b;
  a = a + 100;
  subject = "E" + subject;
  std::cout << "Within the append function: " << subject << a << std::endl;
  return subject;
}

#endif