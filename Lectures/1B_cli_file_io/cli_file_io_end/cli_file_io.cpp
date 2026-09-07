#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  // Use default filenames when no user-supplied filename arguments are provided.
  std::string input_file = "../input.txt";
  std::string output_file = "../output.txt";

  if (argc > 3) // Reject more than two user-supplied filename arguments.
  {
    std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
    return EXIT_FAILURE;
  }
  else if (argc == 2) // Override the input filename and retain the default output filename.
  {
    input_file = argv[1];
  }
  else if (argc == 3) // Override both filenames.
  {
    input_file = argv[1];
    output_file = argv[2];
  }

  std::ifstream file_read(input_file);
  std::ofstream file_write(output_file);

  if (file_read.fail())
  {
    std::cout << "File input error" << std::endl;
    return EXIT_FAILURE;
  }
  else if (file_write.fail())
  {
    std::cout << "Output file error" << std::endl;
    file_read.close();
    return EXIT_FAILURE;
  }

  std::string line;

  // Read each line until the stream reaches the end of the file or fails.
  while (getline(file_read, line))
  {
    int equals_index = line.find("=");

    if (equals_index == std::string::npos)
    {
      std::cout << "Input formatting error" << std::endl;
      std::cout << "Line should be r = <radius>" << std::endl;
      return EXIT_FAILURE;
    }

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
      return EXIT_FAILURE;
    }

    bool isPositive = (radius > 0);

    if (!isPositive)
    {
      std::cout << "Invalid radius, " << radius;
      std::cout << " should be positive" << std::endl;
      file_read.close();
      return EXIT_FAILURE;
    }

    // Calculate and output the area as pi * radius^2.
    double area = M_PI * pow(radius, 2);

    // Write the results to the output file.
    file_write << "Radius is : ";
    file_write << std::fixed << std::setprecision(2);
    file_write << radius << ", "; // Separate the radius and area with a comma.
    file_write << "Area is : " << area << std::endl;
  }

  file_read.close();
  file_write.close();
  return EXIT_SUCCESS;
}