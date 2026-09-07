// This is cli_file_io_4.cpp
// Changes compared to cli_file_io_3.cpp:
// - Uses std::stod to convert the radius and retains the default of 4.0.
// - Removes the std::cin validation flag.
// Using g++ method: try 10, -10, abcd, and no argument. Conversion exceptions are not yet handled.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
  double radius = 4.0;

  if (argc > 1)
  {
    radius = std::stod(argv[1]);
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