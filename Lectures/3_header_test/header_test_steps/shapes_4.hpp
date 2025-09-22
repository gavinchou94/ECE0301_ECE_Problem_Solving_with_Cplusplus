// This is shapes_4.hpp
// Changes from shapes_3.hpp
// 1. add stub function calc to demonstrate function stub
// 2. add GLOBAL variable to demonstrate

#ifndef _SHAPES_HPP
#define _SHAPES_HPP

#include <cmath>
#include <iostream>
#include <string>

// GLOBAL variable example
int GLOBAL = 42;

double conversion(std::string);
double area(double);
double area(double, double);
double area_with_default_side(double, double = 10.0);
// DON'T use same function names to confuse default argument with overloaded functions
double area(double, double, double);
double area(double, double, float); // create for sides a, b, c to show ternary
double area(int, int, int);         // create to show static_cast
int sum(int, int);                  // create to test function passing by value
int sum2(int &, int);               // create to test function passing by reference
bool calc(int, int, int);           // create to test function stub and GLOBAL variable

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
  // call with one argument, the other argument will take default value
  // e.g., area_with_default_side(5.0) will be treated as area_with_default(5,10)

  // call with two arguments, both arguments will take the provided values
  // e.g., area_with_default_side(5.0,6.0) will be treated as exactly as area(5.0,6.0)
}

double area(double a, double b, double sinC)
{
  return 0.5 * a * b * sinC;
}

// Another overloaded function example with different parameter types
// this function is not used in main program, but provided here for demonstration purpose
// c is side length, a,b are two other side lengths
double area(double a, double b, float c)
{
  double result;
  // assume a<=b<=c
  // Math derivation suggests if a+b<=c, the following formula will return <=-1
  double cosC = (pow(a, 2) + pow(b, 2) - pow(c, 2)) * (2.0 * a * b);

  // Syntax: condition ? value_if_true : value_if_false
  // e.g., x = (a>b)? 4:5; that is if a>b then x=4 else x=5
  result = (cosC <= -1) ? -1 : 0.5 * a * b * sqrt(1 - pow(cosC, 2));
  // we use -1 to indicate invalid result
  return result;
}

// Another overloaded function example with different parameter types
// this function is not used in main program, but provided here for demonstration purpose
// a,b,c are three integer side lengths
double area(int a, int b, int c)
{
  // using (a * a + b * b - c * c) / (2 * a * b) directly will cause integer division issue
  // static_cast<double> converts integer to double and comes to the rescue
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

bool calc(int a, int b, int c)
{
  // function stub example
  // assuming that we will implement this function later
  // for now, just return true to get the program compiled

  GLOBAL = GLOBAL + 1; // no need to declare GLOBAL since it's declared in the beginning of the file
  std::cout << "GLOBAL is now " << GLOBAL << std::endl;
  return true;
}

#endif