// This is cli_file_io_1.cpp
// Changes compared to cli_file_io_starter.cpp:
// - Replaces the repeated calculation with a single console input.
// - Introduces Boolean flags for input validation and requires a positive radius.
// - Displays the radius and area with two decimal places.
// For CMake debugging, use the Chapter 3.2 workflow and configure launch.json.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main()
{
  double radius;
  std::cout << "Enter radius: ";
  std::cin >> radius;

  // good() is true only when no stream-state error flags are set.
  bool isNumber = std::cin.good();
  bool isPositive = (radius > 0);

  if (!isNumber)
  {
    std::cout << "Invalid radius, must be a number" << std::endl;
    return EXIT_FAILURE;
  }
  else if (!isPositive)
  {
    std::cout << "Invalid radius, " << radius;
    std::cout << " should be positive" << std::endl;
    return EXIT_FAILURE;
  }
  else
  {
    // Calculate and output the area as pi * radius^2.
    double area = M_PI * pow(radius, 2);
    std::cout << "Radius is : ";
    // With fixed notation, setprecision controls digits after the decimal point.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
  }

  return EXIT_SUCCESS;
}