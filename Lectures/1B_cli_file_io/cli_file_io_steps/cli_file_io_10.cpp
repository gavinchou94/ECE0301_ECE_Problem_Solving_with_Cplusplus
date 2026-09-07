// This is cli_file_io_10.cpp
// Changes compared to cli_file_io_9.cpp:
// - Reads lines in the format r = <radius> from input_10.txt.
// - Finds the equals sign and extracts the radius substring.
// - Checks only that an equals sign is present before extracting the radius.

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::string input_file = "../input_10.txt"; // Run via CMake Debug (project status side menu)
  // std::string input_file = "input_10.txt"; // Run via launch.json file

  std::ifstream file_read(input_file);

  if (file_read.fail())
  {
    std::cout << "File input error" << std::endl;
    return EXIT_FAILURE;
  }

  std::string line;

  // Read each line until the stream reaches the end of the file or fails.
  while (getline(file_read, line))
  {
    // find returns the first matching position, or std::string::npos if absent.
    int equals_index = line.find("=");

    if (equals_index == std::string::npos) // Review the purpose of std::string::npos.
    {
      std::cout << "Input formatting error" << std::endl;
      std::cout << "Line should be r = <radius>" << std::endl;
      return EXIT_FAILURE;
    }

    // Assume one space follows the equals sign; skip both and extract the remaining text.
    std::string input = line.substr(equals_index + 2, line.length());
    // substr(start, count) copies up to count characters from start.
    // The copy stops at the end of the string if fewer characters remain.

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
  }

  return EXIT_SUCCESS;
}