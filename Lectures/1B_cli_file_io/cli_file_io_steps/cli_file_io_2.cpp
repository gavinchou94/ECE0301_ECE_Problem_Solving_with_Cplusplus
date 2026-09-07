// This is cli_file_io_2.cpp
// Changes compared to cli_file_io_1.cpp:
// - Introduces argc and argv and displays the argument count and first two entries.
// - Replaces console input with a placeholder radius of 4.0.
// Run with a radius argument (g++ method) to inspect argv[1]. Argument-count validation is added later.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) // argc includes the program name; argv contains pointers to argument strings.
{
  std::cout << "argc is " << argc << std::endl;
  std::cout << "argv[0] is " << argv[0] << std::endl;
  std::cout << "argv[1] is " << argv[1] << std::endl;

  double radius = 4.0;

  // good() checks stream state; it does not validate command-line arguments.
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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
  }

  return EXIT_SUCCESS;
}