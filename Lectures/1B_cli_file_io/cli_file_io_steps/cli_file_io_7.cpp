// This is cli_file_io_7.cpp
// Changes compared to cli_file_io_6.cpp:
// - Requires exactly one user-supplied radius argument.
// - Displays usage guidance when the argument count is incorrect.
// - Exits early for an invalid radius before calculating the area.
// Using g++ method: try 10, 12b, abcd, and no argument to compare the results.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <radius>" << std::endl;
    return EXIT_FAILURE;
  }

  double radius;

  try
  {
    radius = std::stod(argv[1]);
  }
  catch (std::invalid_argument)
  {
    std::cout << "Invalid radius, must be a number" << std::endl;
    return EXIT_FAILURE;
  }

  bool isPositive = (radius > 0);

  if (!isPositive)
  {
    std::cout << "Invalid radius, " << radius;
    std::cout << " should be positive" << std::endl;
    return EXIT_FAILURE;
  }

  // Calculate and output the area as pi * radius^2.
  double area = M_PI * pow(radius, 2);
  std::cout << "Radius is : ";
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << radius << std::endl;
  std::cout << "Area is : " << area << std::endl;

  return EXIT_SUCCESS;
}