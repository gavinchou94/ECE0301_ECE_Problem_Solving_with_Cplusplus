// This is circle_area_6.cpp
// Changes compared to circle_area_5.cpp:
// - Changes the radius type to double to accept decimal values.
// - Uses an if-else statement to require a non-negative radius.
// - Uses EXIT_SUCCESS and EXIT_FAILURE for readable exit statuses.
// Try entering both 4 and -4 to compare the results.

#include <cmath>
#include <cstdlib> // For EXIT_SUCCESS and EXIT_FAILURE.
#include <iomanip>
#include <iostream>

int main()
{
  double radius;

  // Read the radius.
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  if (radius >= 0)
  {
    // Calculate and output the area as pi * radius^2.
    double area = M_PI * std::pow(radius, 2);
    std::cout << "The area is: ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << area << std::endl;
  }
  else
  {
    std::cout << "Radius must be non-negative!" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}