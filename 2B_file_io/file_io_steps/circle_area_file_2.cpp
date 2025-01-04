// This is circle_area_file_2.cpp
// Changes from circle_area_file_1.cpp:
// 1. use while loop to parse input .txt file line by line
// 2. pass each line to stod() function
// each line of input_2.txt can be mapped to a number, so the program works without errors
// Try to append some letters to last row, see input_2b.txt and use CMake debug (launch.json file, same as cin input)
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "input_2.txt";
    std::ifstream file_read(input_file);

    // Test whether file can be read
    if (file_read.fail())
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }

    // Variable "line" is declared to store each line of input file
    std::string line;

    // Introduce a while-loop to run line by line until some errors show up
    while (getline(file_read, line))
    {
        
        // std::string input = "4.0";
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
    }
    return EXIT_SUCCESS;
}