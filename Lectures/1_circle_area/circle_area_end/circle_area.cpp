// This is final version of circle_area.cpp, clear comments from circle_area_7.cpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

int main()
{

    double radius;

    std::cout << "Enter radius: ";
    std::cin >> radius;

    if (!std::cin.good())
    {
        std::cout << "Invalid input type" << std::endl;
        return EXIT_FAILURE;
    }
    else if (radius < 0)
    {
        std::cout << "Invalid radius, must be positive" << std::endl;
        return EXIT_FAILURE;
    }

    // calculate and output area as pi*r^2
    double area = M_PI * pow(radius, 2);
    std::cout << "Radius is " << radius << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area is " << area << std::endl;

    return EXIT_SUCCESS;
}