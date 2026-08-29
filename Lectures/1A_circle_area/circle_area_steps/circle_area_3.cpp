// This is circle_area_3.cpp
// Changes compared to circle_area_2.cpp:
// - Introduces the area variable and outputs its value.

#include <iostream>

int main()
{
  int radius = 4;
  const double PI = 3.14159;

  // Calculate and output the area as pi * radius^2.
  double area = PI * radius * radius;
  std::cout << "The area is: ";
  std::cout << area << std::endl;
}