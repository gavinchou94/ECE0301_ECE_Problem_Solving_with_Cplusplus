// This is cli_file_io_13.cpp
// Changes compared to cli_file_io_12.cpp:
// - Accepts input and output filenames when both are supplied as arguments.
// - Uses ../input.txt and ../output.txt otherwise.
// - Writes each radius and area on one line, separated by a comma.

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  // Use default filenames unless command-line arguments override them.
  std::string input_file = "../input.txt";
  std::string output_file = "../output.txt";

  if (argc == 3)
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

  // Read each line until the stream reaches the end of the file or fails.
  while (getline(file_read, line))
  {
    // find returns the first matching position, or std::string::npos if absent.
    int equals_index = line.find("=");

    if (equals_index == std::string::npos)
    {
      std::cout << "Input formatting error" << std::endl;
      std::cout << "Line should be r = <radius>" << std::endl;
      file_read.close();
      file_write.close();
      return EXIT_FAILURE;
    }

    // Assume one space follows the equals sign; skip both and extract the remaining text.
    std::string input = line.substr(equals_index + 2, line.length());

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