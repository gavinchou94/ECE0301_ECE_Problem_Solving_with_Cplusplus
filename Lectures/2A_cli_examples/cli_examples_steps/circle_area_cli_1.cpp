// This is circle_area_cli_1.cpp
// Changes compared to circle_area_cli_starter.cpp:
// add boolean flags, such changes make it easier for users to interpret branching conditions
// Try CMake "Debug Program with cin", create your launch.json file
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{

    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius;

    bool isNumber = std::cin.good();
    bool isPositive = (radius >= 0);

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
    else
    {
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