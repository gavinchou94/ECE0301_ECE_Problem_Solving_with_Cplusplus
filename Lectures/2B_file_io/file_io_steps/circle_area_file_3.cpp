// This is circle_area_file_3.cpp
// Changes from circle_area_file_2.cpp:
// 1. for new type of input text, find where "=" is
// 2. quit program if no "=" exists, otherwise find out substring after "=" to pass to stod()
// each line of input_3.txt in the format of r=x.xx
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "input_3.txt";
    std::ifstream file_read(input_file);

    if (file_read.fail())
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;

    // Introduce a while-loop to run line by line until some errors show up
    while (getline(file_read, line))
    {

        // We need to find where the "=" is and parse accordingly
        int equals_index = line.find("=");

        // std::string::npos is -1, indicating that no index is found
        if (equals_index == std::string::npos)
        {
            std::cout << "Input formatting error" << std::endl;
            std::cout << "Line should be r=<radius>" << std::endl;
            return EXIT_FAILURE;
        }

        // std::string input = line; // This would run into error
        // substr arguments are (start_index, how_long_it_should_span)
        std::string input = line.substr(equals_index + 1, line.length());

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
    }
    return EXIT_SUCCESS;
}