// This is cli_file_io_2.cpp
// Changes compared to cli_file_io_1.cpp:
// 1. allow user input via command-line input (CLI)
// 2. print out argv[0] and argv[1]
// Just view the first two lines of output, no need to worry about output afterwards
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    std::cout << "argv[0] is " << argv[0] << std::endl; // Just to show what's argv[0]
    std::cout << "argv[1] is " << argv[1] << std::endl; // Just to show what's argv[1]

    double radius = 4.0; // a placeholder value
    // std::cout << "Enter radius: "; // no more cin here
    // std::cin >> radius;

    bool isNumber = std::cin.good();
    bool isPositive = (radius > 0);

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
        std::cout << std::fixed << std::setprecision(2);
        std::cout << radius << std::endl;
        std::cout << "Area is : " << area << std::endl;
    }

    return EXIT_SUCCESS;
}