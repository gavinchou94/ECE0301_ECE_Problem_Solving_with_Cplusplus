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

int main() {

    double radius;

    std::cout << "Enter radius: ";
    std::cin >> radius;

    if (radius > 0)   // If you have multiple statements upon satisfying "if" condition, use {} to include all
    {
        // calculate and output area as pi*r^2
        double area = M_PI*pow(radius,2);
        std::cout << "Radius is " << radius << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Area is " << area << std::endl;
    } else {
        std::cout << "Invalid radius: " << radius << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}