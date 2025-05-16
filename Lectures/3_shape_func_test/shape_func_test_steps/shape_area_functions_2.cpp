// This is shape_area_functions_2.cpp
// Changes from shape_area_functions_1.cpp:
// 1. continue parsing the line to find second comma ","
// 2. split the line accordingly into 1 part, or 2 parts, or 3 parts
// Try CMake debug here to test line splitting, e.g. add a breakpoint at Line 59

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{

    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

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
    int first_comma_index, second_comma_index;
    
    while (getline(file_read, line))
    {

        // find first comma, second comma, third comma
        std::string first_sub_string, second_sub_string, third_sub_string;

        // one-number case
        first_comma_index = line.find(",");
        if (first_comma_index == std::string::npos)
        {
            std::cout << "It's a circle" << std::endl;
            first_sub_string = line;
            dimension = 1;
        }
        else
        {
            // string object member function substr() has two arguments
            // substr(starting_index, ending_index)
            // ending_index can be line.length() or can be -1
            first_sub_string = line.substr(0, first_comma_index);
            second_sub_string = line.substr(first_comma_index+1, std::string::npos);

            second_comma_index = second_sub_string.find(",");

            // two-number case
            if (second_comma_index == std::string::npos)
            {
                std::cout << "It's a rectangle" << std::endl;
                dimension = 2;
                // in this case, second_sub_string is all we need to find numbers
            }
            // three-number case
            else
            {
                std::cout << "It's a triangle" << std::endl;
                dimension = 3;
                // in this case, further split second_sub_string to second_sub and third_sub
                third_sub_string = second_sub_string.substr(second_comma_index+1, std::string::npos);
                second_sub_string = second_sub_string.substr(0, second_comma_index);
            }
        }

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