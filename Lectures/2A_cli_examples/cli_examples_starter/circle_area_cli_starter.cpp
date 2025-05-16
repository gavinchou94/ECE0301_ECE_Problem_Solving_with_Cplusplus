// This is the final version of circle_area.cpp
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{

    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius; // cin allows user to input a radius from console

    if (!std::cin.good()) // cin.good() to check whether input type is matched
    {
        std::cout << "Invalid radius, must be a number" << std::endl;
        return EXIT_FAILURE; // EXIT_FAILURE = constant 1, <cstdlib> is included
    }
    else if (radius < 0)
    {
        std::cout << "Invalid radius, " << radius;
        std::cout << " should be positive" << std::endl;
        return EXIT_FAILURE;
    }
    else // Note the structure of "if-->else if-->else"
    {
        // calculate and output area as pi*r^2
        double area = M_PI * pow(radius, 2); // M_PI, pow from <cmath>
        std::cout << "Radius is : ";
        std::cout << std::fixed;
        std::cout << std::setprecision(2); // fixed, setprecision from <iomanip>
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }

    return EXIT_SUCCESS; // EXIT_FAILURE = constant 0
}