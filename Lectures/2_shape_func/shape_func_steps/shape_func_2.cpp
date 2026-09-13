// This is shape_func_2.cpp
// Changes compared to shape_func_1.cpp:
// - Finds the second comma when a line has more than one value.
// - Splits each line into one, two, or three substrings for later parsing.
// Run via CMake Debug to inspect the line-splitting behavior.

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
  int first_comma_index, second_comma_index;

  while (getline(file_read, line))
  {
    // Find first comma, then second comma.
    std::string first_sub_string, second_sub_string, third_sub_string;

    // One-number case.
    first_comma_index = line.find(",");
    if (first_comma_index == std::string::npos)
    {
      std::cout << "It's a circle" << std::endl;
      first_sub_string = line;
      dimension = 1;
    }
    else
    {
      // std::string::substr() has two arguments.
      // substr(starting_index, length_of_substring)
      // The requested length can be the full length of the string.
      first_sub_string = line.substr(0, first_comma_index);
      second_sub_string = line.substr(first_comma_index + 2, line.length());

      second_comma_index = second_sub_string.find(",");

      // Two-number case.
      if (second_comma_index == std::string::npos)
      {
        std::cout << "It's a rectangle" << std::endl;
        dimension = 2;
        // In this case, second_sub_string contains the remaining number text.
      }
      // Three-number case.
      else
      {
        std::cout << "It's a triangle" << std::endl;
        dimension = 3;
        // In this case, split second_sub_string into second_sub and third_sub.
        third_sub_string = second_sub_string.substr(second_comma_index + 2, second_sub_string.length());
        second_sub_string = second_sub_string.substr(0, second_comma_index);
      }
    }

    // Use placeholder values to test line splitting.
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