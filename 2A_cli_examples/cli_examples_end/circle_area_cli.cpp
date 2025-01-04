// This is final circle_area_cli.cpp, clear comments from circle_area_cli_7.cpp
// What else can you improve?
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <radius>" << std::endl;
        return EXIT_FAILURE;
    }

    double radius;

    try
    {
        radius = std::stod(argv[1]);
    }
    catch (std::invalid_argument)
    {
        std::cout << "Invalid radius, must be a number" << std::endl;
        return EXIT_FAILURE;
    }

    bool isPositive = (radius >= 0);

    if (!isPositive)
    {
        std::cout << "Invalid radius, " << radius;
        std::cout << " should be positive" << std::endl;
        return EXIT_FAILURE;
    }

    // calculate and output area as pi*r^2
    double area = M_PI * pow(radius, 2);
    std::cout << "Radius is : ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << radius << std::endl;
    std::cout << "Area is : " << area << std::endl;
    return EXIT_SUCCESS;
}