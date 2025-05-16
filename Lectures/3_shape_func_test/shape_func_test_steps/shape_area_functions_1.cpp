// This is shape_area_functions_1.cpp
// Changes from shape_area_functions_starter.cpp:
// 1. delete statements to find "=" and input validation of r=<radius>
// 2. add line parsing to find first comma ","
// Try CMake debug with file read/write here, e.g. add a breakpoint at Line 62
// Learn to use control options in Cmake debug: continue/step-over etc
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

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
        return EXIT_FAILURE;
    }
    else if (file_write.fail())
    {
        std::cout << "Output file error" << std::endl;
        file_read.close();
        return EXIT_FAILURE;
    }

    std::string line;
    
    int dimension = 0;
    int first_comma_index;

    while (getline(file_read, line))
    {

        // find first comma, second comma, third comma

        // one-number case
        first_comma_index = line.find(",");

        if (first_comma_index == std::string::npos)
        {
            std::cout << "It's a circle" << std::endl;
            dimension = 1;
        }

        // two-number case

        // three-number case

        std::string input = line.substr(first_comma_index + 1, line.length());

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

        file_write << "Radius is : ";
        file_write << std::fixed;
        file_write << std::setprecision(2);
        file_write << radius << ", ";
        file_write << "Area is : " << area << std::endl;
    }

    file_read.close();
    file_write.close();
    return EXIT_SUCCESS;
}