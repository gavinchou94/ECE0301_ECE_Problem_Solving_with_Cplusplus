// This is circle_area_6.cpp
// Changes compared to circle_area_5.cpp:
// 1. change radius type to double to allow decimal places from cin
// 2. use if-else structure to validate radius (from cin) to be positive only
// 3. return EXIT_FAILURE instead of 1, return EXIT_SUCCESS instead of 0. Just to add readability
// Try both 4 and -4 to cin to test results

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> // must include this header if EXIT_FAILURE and EXIT_SUCCESS are used

int main()
{
    double radius;

    // user input
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    if (radius > 0) // If you have multiple statements upon satisfying "if" condition, use {} to include all
    {
        // calculate and output area as pi*r^2
        double area = M_PI * pow(radius, 2);
        std::cout << "The area is: ";
        std::cout << std::fixed << std::setprecision(5);
        std::cout << area << std::endl;
    }
    else
    {
        std::cout << "Radius must be positive!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}