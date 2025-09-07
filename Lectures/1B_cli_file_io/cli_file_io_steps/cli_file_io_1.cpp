// This is cli_file_io_1.cpp
// Changes compared to cli_file_io_starter.cpp:
// add boolean flags, such changes make it easier for users to interpret branching conditions
// Try Chapter 3.2, CMake "Debug Program with cin", create your launch.json file
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{

    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius; // The inclusion of cin requires a different workflow of cmake debugging

    bool isNumber = std::cin.good();
    // good() checks whether cin gets a valid input that matches data type!
    bool isPositive = (radius > 0);

    if (!isNumber)
    {
        std::cout << "Invalid radius, must be a number" << std::endl;
        return EXIT_FAILURE;
    }
    else if (!isPositive)
    {
        std::cout << "Invalid radius, " << radius;
        std::cout << " should be positive" << std::endl;
        return EXIT_FAILURE;
    }
    // Why do we put these if-conditions before the calculation of area?
    // Because early exit is a good programming practice to avoid waste of computation resources
    else
    {
        // calculate and output area as pi*r^2
        double area = M_PI * pow(radius, 2);
        std::cout << "Radius is : ";
        std::cout << std::fixed << std::setprecision(2);
        // With std::fixed, setprecision controls the number of digits after the decimal point.
        // Without std::fixed, setprecision controls the total number of significant digits shown.
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }

    return EXIT_SUCCESS;
}