// This is final version of circle_area.cpp, clear comments from circle_area_8.cpp

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

int main()
{
    char answer = 'y';

    while (answer == 'y' || answer == 'Y')
    {
        double radius;
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;

        if (!std::cin.good())
        {
            std::cout << "Invalid input type" << std::endl;
            return EXIT_FAILURE;
        }

        if (radius < 0)
        {
            std::cout << "Invalid radius, must be positive" << std::endl;
            return EXIT_FAILURE;
        }

        double area = M_PI * pow(radius, 2);
        std::cout << "The area is: ";
        std::cout << std::fixed << std::setprecision(5);
        std::cout << area << std::endl;

        std::cout << "Do you want to calculate another area? (y/n): ";
        std::cin >> answer;
    }

    return EXIT_SUCCESS;
}