// This is circle_area_3b.cpp
// Changes compared to circle_area_3.cpp:
// - Demonstrates that storing the area as an int truncates its decimal places.
// - Notes that integer division also truncates: 1 / 2 is 0, while 1 / 2.0 is 0.5.

#include <iostream>

int main()
{
  int radius = 4;
  const double PI = 3.14159;

  // Calculate and output the area as pi * radius^2.
  int area = PI * radius * radius;
  std::cout << "The area is: ";
  std::cout << area << std::endl;
}