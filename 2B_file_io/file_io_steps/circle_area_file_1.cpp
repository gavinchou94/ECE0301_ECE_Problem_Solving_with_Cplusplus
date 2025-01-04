// This is circle_area_file_1.cpp
// Changes from circle_area_file_starter.cpp:
// introduce file_read object to parse .txt file
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string> // This is required to declare string variables
#include <fstream> // This is required to process file input

int main()
{

    std::string input_file = "input.txt";

    // Read input file, declare a object here, will study later
    std::ifstream file_read(input_file);

    // Test whether file can be read
    if (file_read.fail())
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

    bool isPositive = (radius >= 0);

    if (!isPositive)
    {
        std::cout << "Invalid radius, " << radius;
        std::cout << " should be positive" << std::endl;
        return EXIT_FAILURE;
    }

    // calculate and output area as pi*r^2
    double area = M_PI * pow(radius, 2);
    std::cout << "Radius is : ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
    return EXIT_SUCCESS;
}