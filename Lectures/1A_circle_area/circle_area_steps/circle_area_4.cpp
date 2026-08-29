// This is circle_area_4.cpp
// Changes compared to circle_area_3.cpp:
// - Formats the area with five decimal places.

#include <iomanip> // For std::fixed and std::setprecision.
#include <iostream>

int main()
{
  int radius = 4;
  const double PI = 3.14159;

  // Calculate and output the area as pi * radius^2.
  double area = PI * radius * radius;
  std::cout << "The area is: ";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << std::endl;
}