// This is cli_file_io_9.cpp
// Changes compared to cli_file_io_8.cpp:
// - Reads the input file one line at a time with getline.
// - Converts each line to a radius with std::stod.
// - Uses ../input_9.txt or input_9.txt relative to the working directory.
// Run from a build directory inside the steps directory to resolve the ../ paths.
// Compare input_9.txt with input_9b.txt; std::stod may accept trailing letters.
// For CMake debugging, use the Chapter 3.2 workflow and configure launch.json.

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::string input_file = "../input_9.txt"; // Run via CMake Debug (project status side menu)
  // std::string input_file = "input_9.txt"; // Run via launch.json file

  std::ifstream file_read(input_file);

  if (file_read.fail())
  {
    std::cout << "File input error" << std::endl;
    return EXIT_FAILURE;
  }

  std::string line;

  // Read each line until the stream reaches the end of the file or fails.
  // getline() stores the next line in line and returns the input stream.
  // The while condition converts the stream to true on success or false on failure.
  while (getline(file_read, line))
  {
    double radius;

    try
    {
      radius = std::stod(line);
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