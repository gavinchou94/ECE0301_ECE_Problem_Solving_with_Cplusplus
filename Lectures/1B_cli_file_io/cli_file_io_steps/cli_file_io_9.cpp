// This is cli_file_io_9.cpp (switch to run CMake from here!)
// Changes from cli_file_io_8.cpp:
// 1. use while loop to parse input .txt file line by line
// 2. pass each line to stod() function
// each line of input_9.txt can be mapped to a number, so the program works without errors
// Try to append some letters to last row, see input_9b.txt and use CMake debug (launch.json file, same as cin input)
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "../input_9.txt";
    std::ifstream file_read(input_file);

    if (file_read.fail())
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }

    // Variable "line" is declared to store each line of input file
    std::string line;

    // Introduce a while-loop to run line by line until some errors show up
    while (getline(file_read, line))
    // usage: getline(file_read, line) reads a line from file_read and stores it into line
    // it returns true if valid and returns false if no more lines
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

        // calculate and output area as pi*r^2
        double area = M_PI * pow(radius, 2);
        std::cout << "Radius is : ";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }
    return EXIT_SUCCESS;
}