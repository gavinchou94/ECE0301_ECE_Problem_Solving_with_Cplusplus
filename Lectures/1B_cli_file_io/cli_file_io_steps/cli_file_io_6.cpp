// This is cli_file_io_6.cpp
// Changes compared to cli_file_io_5.cpp:
// - Replaces digit-by-digit validation with std::stod and a try-catch block.
// - Handles std::invalid_argument when conversion cannot begin.
// std::stod accepts signs and decimal points and may accept a numeric prefix such as 12b.
// Out-of-range conversions are not handled in this example.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
  double radius = 4.0;

  if (argc > 1)
  {
    // Attempt conversion and handle an invalid argument in the catch block.
    try
    {
      radius = std::stod(argv[1]);
    }
    catch (std::invalid_argument)
    {
      std::cout << "Invalid radius, must be a number" << std::endl;
      return EXIT_FAILURE;
    }
  }

  bool isPositive = (radius > 0);

  if (!isPositive)
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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
  }

  return EXIT_SUCCESS;
}