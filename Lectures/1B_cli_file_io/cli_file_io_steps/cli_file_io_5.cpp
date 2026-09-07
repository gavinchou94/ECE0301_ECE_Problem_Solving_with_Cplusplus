// This is cli_file_io_5.cpp
// Changes compared to cli_file_io_4.cpp:
// - Introduces an indexed for loop and std::isdigit to check each character.
// - Rejects characters other than digits before converting the input.
// Using g++ method: try 10, 12b, abcd, -10, and 10.0. Signs and decimal points fail the digit check.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string> // For std::string and std::stod.

int main(int argc, char *argv[])
{
  double radius = 4.0;

  if (argc > 1)
  {
    std::string input = argv[1];

    // Check each character before converting the input.
    for (int i = 0; i < input.length(); i++)
    {
      if (!std::isdigit(input[i]))
      {
        std::cout << "Invalid radius, must be a number" << std::endl;
        return EXIT_FAILURE;
      }
    }
    // Review the for loop, std::isdigit(), and the string length() method.

    radius = std::stod(input);
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