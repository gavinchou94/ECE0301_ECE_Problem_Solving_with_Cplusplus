// This is cli_file_io_10.cpp
// Changes from cli_file_io_9.cpp:
// 1. for new type of input text, find where "=" is
// 2. quit program if no "=" exists, otherwise find out substring after "=" to pass to stod()
// each line of input_10.txt in the format of r = NUMBER
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main()
{

    std::string input_file = "../input_10.txt";
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
        // usage: string.find(substring) returns the index of the first occurrence of substring in string

        // std::string::npos is -1, indicating that no index is found
        if (equals_index == std::string::npos)
        // find() will return 0~(N-1) if found, and return std::string::npos if not found
        {
            std::cout << "Input formatting error" << std::endl;
            std::cout << "Line should be r = <radius>" << std::endl;
            return EXIT_FAILURE;
        }

        // Use substr to extract the substring after "="
        std::string input = line.substr(equals_index + 2, line.length());
        // substr arguments are (start_index, how_long_it_should_span)
        // e.g. string s = "abcdefgh", s.substr(2,3) returns "cde"
        // here we use +2 to skip the space after "="

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
    }
    return EXIT_SUCCESS;
}