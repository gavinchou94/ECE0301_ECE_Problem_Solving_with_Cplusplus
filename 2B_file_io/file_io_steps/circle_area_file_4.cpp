// This is circle_area_file_4.cpp
// Changes from circle_area_file_3.cpp:
// declare output file object, verify it
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "input_4.txt";
    std::ifstream file_read(input_file);

    // Write to output file, declare a object here, will study later
    std::string output_file = "output_4.txt";
    std::ofstream file_write(output_file);

    if (file_read.fail())
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }
    else if (file_write.fail()) // like the verification of input file, here we verify the output file can be written to
    {
        std::cout << "Output file error" << std::endl;
        file_read.close();
        return EXIT_FAILURE;
    }

    std::string line;

    // Introduce a while-loop to run line by line until some errors show up
    while (getline(file_read, line))
    {

        // We need to find where the "=" is and parse accordingly
        int equals_index = line.find("=");

        if (equals_index == std::string::npos)
        {
            std::cout << "Input formatting error" << std::endl;
            std::cout << "Line should be r=<radius>" << std::endl;
            return EXIT_FAILURE;
        }

        // std::string input = line; // This would run into error
        // substr arguments are start index and substring length
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
    file_read.close();
    return EXIT_SUCCESS;
}