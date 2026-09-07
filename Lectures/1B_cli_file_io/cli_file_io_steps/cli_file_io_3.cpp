// This is cli_file_io_3.cpp
// Changes compared to cli_file_io_2.cpp:
// - Introduces a commented-out assignment from argv[1] to the radius.
// - Checks argc before the example assignment and retains the default radius of 4.0.
// Uncomment the assignment to demonstrate the compiler error: argv[1] is text, not a double.
// Inspect the VS Code Problems tab. Without the argc guard, argv[1] may be absent.
// Step 4 converts the argument explicitly with std::stod.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
  double radius = 4.0;

  if (argc > 1)
  {
    // radius = argv[1]; // Uncomment this line to see the compiler error.
  }

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