// This is circle_area_cli_7.cpp
// Changes compared to circle_area_cli_6.cpp:
// 1. no more default radius value, user is forced to input two arguments
// 2. output the usage of this program if user didn't provide a radius
// Try {10, 12b, abcd} after ./circle_area_cli and play with no additional arguments too!
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    if (argc != 2) // If user doesn't provide radius or provide too many, return error and provide usage guide
    { 
        std::cout << "Usage: " << argv[0] << " <radius>" << std::endl;
        return EXIT_FAILURE;
    }

    double radius;

    // No need to determine if argc > 1
    try
    {
        radius = std::stod(argv[1]);
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
    return EXIT_SUCCESS;
}