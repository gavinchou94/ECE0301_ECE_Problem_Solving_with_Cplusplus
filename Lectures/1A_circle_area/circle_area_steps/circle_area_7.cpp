// This is circle_area_7.cpp
// Changes compared to circle_area_6.cpp:
// - Checks that the input is numeric before using it.
// - Validates input before calculating the area so invalid input exits early.
// Try entering 4, -4, and abcd to compare the results.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main()
{
  double radius;

  // Read the radius.
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  if (!std::cin.good()) // cin.good() would check whether cin input matches the desired data type
                        // dot notation, and function with () suggests that this is a member function of the object cin,
                        // for now you can just remember it
                        // The "!" operator negates the boolean value, so if cin.good() is false, !cin.good() is true
  {
    std::cout << "Invalid input type" << std::endl;
    return EXIT_FAILURE;
  }
  else if (radius < 0)
  {
    std::cout << "Invalid radius, must be non-negative" << std::endl;
    return EXIT_FAILURE;
  }

  double area = M_PI * std::pow(radius, 2);
  std::cout << "The area is: ";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << std::endl;

  return EXIT_SUCCESS;
}