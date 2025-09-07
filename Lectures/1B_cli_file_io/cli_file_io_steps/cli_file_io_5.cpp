// This is cli_file_io_5.cpp
// Changes compared to cli_file_io_4.cpp:
// 1. isdigit() verifies each char in input string since we need some method to catch and fix
// 2. for loop is introduced
// Try {10, 12b, abcd} after ./circle_area_cli and play with no additional arguments too!
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string> // Since we are going to declare string variable

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    double radius = 4.0;

    if (argc > 1)
    {
        std::string input = argv[1]; // To ensure clarity, we first store argv[1] to input
        // Later we will learn that char *argv[] is actually an array of chars, i.e., a string

        // We have a for-loop below to determine whether each char of string input is a digit
        for (int i = 0; i < input.length(); i++) // input.length() gives the length of string input
        {
            if (!std::isdigit(input[i])) // isdigit() checks whether a char is a digit, string[i] gives the i-th char of string
            {
                std::cout << "Invalid radius, must be a number" << std::endl;
                return EXIT_FAILURE;
            }
        }
        // Should all chars be digits, we can safely do the conversion and assign radius
        radius = std::stod(input);
    }

    bool isPositive = (radius > 0);

    if (!isPositive)
    {
        std::cout << "Invalid radius, " << radius;
        std::cout << " should be positive" << std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        // calculate and output area as pi*r^2
        double area = M_PI * pow(radius, 2);
        std::cout << "Radius is : ";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }

    return EXIT_SUCCESS;
}