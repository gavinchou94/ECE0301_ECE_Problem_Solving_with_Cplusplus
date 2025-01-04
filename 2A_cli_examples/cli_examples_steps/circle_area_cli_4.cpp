// This is circle_area_cli_4.cpp
// Changes compared to circle_area_cli_3.cpp:
// 1. use "if" to determine whether there is more than 1 argument
// 2. use function stod() to convert string to double
// Try {10, -10 and abcd} after ./circle_area_cli and play with no additional arguments too!
// Starting here, try CMake "Debug Programs with CLI (command-line inputs)"
// What would happen if you put "abcd" in your "args" of launch.json file?
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    double radius = 4.0; // A default initial value in case of no CLI

    if (argc > 1) // This gurantees that radius only gets value if there exists one
    {                                
        radius = std::stod(argv[1]); // stod() is a function to convert string to double
    }

    // bool isNumber = std::cin.good(); // No more cin
    bool isPositive = (radius >= 0);

    // Due to commenting above, no more isNumber
    // if (!isNumber) {
    //     std::cout << "Invalid radius, must be a number" << std::endl;
    //     return EXIT_FAILURE;
    // } else
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
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }

    return EXIT_SUCCESS;
}