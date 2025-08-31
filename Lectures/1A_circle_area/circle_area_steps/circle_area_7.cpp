// This is circle_area_7.cpp
// Changes compared to circle_area_6.cpp:
// 1. also check whether cin is a number first, and show error message if not
// 2. place "if-else if" structure ahead of calculation to exit program as early as possible upon invalid input
// In terminal, try both {4, -4 and abcd} to cin to test results

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

int main()
{
    double radius;

    // user input
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    if (!std::cin.good()) // cin.good() would check whether cin input matches the desired data type ()
    {
        std::cout << "Invalid input type" << std::endl;
        return EXIT_FAILURE;
    }
    else if (radius < 0)
    {
        std::cout << "Invalid radius, must be positive" << std::endl;
        return EXIT_FAILURE;
    }

    double area = M_PI * pow(radius, 2);
    std::cout << "The area is: ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << area << std::endl;

    return EXIT_SUCCESS;
}