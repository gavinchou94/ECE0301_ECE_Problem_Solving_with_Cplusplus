// You may notice an output_4.txt is generated, but with blank content

// This is circle_area_file_5.cpp
// Changes from circle_area_file_4.cpp:
// modify cout in last few lines to file_write, allow output to be stored in .txt file
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "input_5.txt";
    std::ifstream file_read(input_file);

    std::string output_file = "output_5.txt";
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
        
    // Introduce a while-loop to run line by line until some errors show up
    while (getline(file_read, line))
    {

        int equals_index = line.find("=");

        if (equals_index == std::string::npos)
        {
            std::cout << "Input formatting error" << std::endl;
            std::cout << "Line should be r=<radius>" << std::endl;
            return EXIT_FAILURE;
        }

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

        // Use file_write instead of std::cout
        file_write << "Radius is : ";
        file_write << std::fixed;
        file_write << std::setprecision(2);
        file_write << radius << ", "; // Use a comma to make it clear
        file_write << "Area is : " << area << std::endl;
    }

    file_read.close();
    file_write.close();
    return EXIT_SUCCESS;
}