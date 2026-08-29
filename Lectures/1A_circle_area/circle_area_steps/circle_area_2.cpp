// This is circle_area_2.cpp
// Changes compared to circle_area_starter.cpp:
// - Introduces the radius variable and the PI constant.

#include <iostream>

int main()
{
  int radius = 4;
  const double PI = 3.14159;

  // Calculate and output the area as pi * radius^2.
  std::cout << "The area is: ";
  std::cout << PI * radius * radius << std::endl;
}