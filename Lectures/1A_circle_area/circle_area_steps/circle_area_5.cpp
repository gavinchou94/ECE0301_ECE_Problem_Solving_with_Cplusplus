// This is circle_area_5.cpp
// Changes compared to circle_area_4b.cpp:
// - Reads the radius from the console instead of fixing it at 4.

#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
  int radius;

  // Read the radius.
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  // Calculate and output the area as pi * radius^2.
  double area = M_PI * std::pow(radius, 2);
  std::cout << "The area is: ";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << std::endl;
}