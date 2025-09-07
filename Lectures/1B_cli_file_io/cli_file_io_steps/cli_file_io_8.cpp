// This is cli_file_io_8.cpp
// Changes from cli_file_io_7.cpp:
// introduce file_read object to parse .txt file
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>  // This is required to declare string variables
#include <fstream> // This is required to process file input

int main()
{

    std::string input_file = "input_8.txt";

    // Read input file, declare an object here, will study later
    // syntax is std::ifstream variable_name(file_name);
    std::ifstream file_read(input_file);

    // Test whether file can be read
    if (file_read.fail()) // object.fail() returns true if file cannot be read
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }

    // Create a placeholder string input "4.0" just to test above
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

    // calculate and output area as pi*r^2
    double area = M_PI * pow(radius, 2);
    std::cout << "Radius is : ";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
    return EXIT_SUCCESS;
}