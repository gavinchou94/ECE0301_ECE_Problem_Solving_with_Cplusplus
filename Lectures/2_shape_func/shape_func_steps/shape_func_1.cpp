// This is shape_func_1.cpp
// Changes compared to shape_func_starter.cpp:
// - Removes the r = <radius> parsing and validation from the starter code.
// - Finds the first comma to distinguish the one-number circle case.
// Run via CMake Debug to practice file read/write debugging.

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  std::string input_file = "../input.txt";
  std::string output_file = "../output.txt";

  if (argc > 3)
  {
    std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
    return EXIT_FAILURE;
  }
  else if (argc == 2)
  {
    input_file = argv[1];
  }
  else if (argc == 3)
  {
    input_file = argv[1];
    output_file = argv[2];
  }

  std::ifstream file_read(input_file);
  std::ofstream file_write(output_file);

  if (file_read.fail())
  {
    std::cout << "File input error" << std::endl;
    file_read.close();
    file_write.close();
    return EXIT_FAILURE;
  }
  else if (file_write.fail())
  {
    std::cout << "Output file error" << std::endl;
    file_read.close();
    file_write.close();
    return EXIT_FAILURE;
  }

  std::string line;

  int dimension = 0;
  int first_comma_index;

  while (getline(file_read, line))
  {
    // Find first comma, then second comma.

    // One-number case.
    first_comma_index = line.find(",");

    if (first_comma_index == std::string::npos)
    {
      std::cout << "It's a circle" << std::endl;
      dimension = 1;
    }

    // Two-number case.

    // Three-number case.

    std::string input = "4.0"; // placeholder value

    double radius;

    try
    {
      radius = std::stod(input);
    }
    catch (std::invalid_argument)
    {
      std::cout << "Invalid radius, must be a number" << std::endl;
      file_read.close();
      file_write.close();
      return EXIT_FAILURE;
    }

    bool isPositive = (radius > 0);

    if (!isPositive)
    {
      std::cout << "Invalid radius, " << radius;
      std::cout << " should be positive" << std::endl;
      file_read.close();
      file_write.close();
      return EXIT_FAILURE;
    }

    // Calculate and output the area as pi * radius^2.
    double area = M_PI * pow(radius, 2);

    file_write << "Radius is : ";
    file_write << std::fixed << std::setprecision(2);
    file_write << radius << ", ";
    file_write << "Area is : " << area << std::endl;
  }

  file_read.close();
  file_write.close();
  return EXIT_SUCCESS;
}