// This is circle_area_4b.cpp
// Changes compared to circle_area_4.cpp:
// - Uses M_PI and squares the radius with std::pow.

#include <cmath> // For M_PI and std::pow.
#include <iomanip>
#include <iostream>

int main()
{
  int radius = 4;

  // Calculate and output the area as pi * radius^2.
  double area = M_PI * std::pow(radius, 2);
  std::cout << "The area is: ";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << std::endl;
}