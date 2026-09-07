// This is cli_file_io_8.cpp
// Changes compared to cli_file_io_7.cpp:
// - Opens input_8.txt with an input file stream and checks for failure.
// - Uses a placeholder radius string before introducing file reading.
// Run from the steps directory so input_8.txt can be found.

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::string input_file = "input_8.txt";

  std::ifstream file_read(input_file); // Equivalent to declaring file_read, then calling file_read.open(input_file).

  if (file_read.fail())
  {
    std::cout << "File input error" << std::endl;
    return EXIT_FAILURE;
  }

  std::string input = "4.0";
  double radius;

  try
  {
    radius = std::stod(input);
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
  std::cout << std::fixed << std::setprecision(2);
  std::cout << radius << std::endl;
  std::cout << "Area is : " << area << std::endl;

  return EXIT_SUCCESS;
}