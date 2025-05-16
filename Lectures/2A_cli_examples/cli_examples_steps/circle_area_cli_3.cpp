// This is circle_area_cli_3.cpp
// Changes compared to circle_area_cli_2.cpp:
// pass argv[1] to radius since we know argv[1] receives value of argument after ./circle_area_cli

// But even without using cmake, this program will be identified with errors by VS Code in Problems Tab
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    // Given that we know argv[1] stores the string, we can pass it to radius
    double radius = argv[1];

    // Errors of above statement include: (1) string-type input is passed to double-type variable
    // (2) Sometimes, argc = 1 and no argv[1], i.e., user doesn't put an argument after ./circle_area_cli

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