// Did you notice that with isdigit(), even -10, 10.0 are not considered as numbers?
// We can instead use try-catch block since stod() is quite robust to recognize float numbers

// This is circle_area_cli_6.cpp
// Changes compared to circle_area_cli_5.cpp:
// use try-catch block together with stod() function
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
// #include <string>

int main(int argc, char *argv[]) // This is necessary for any CLI
{

    double radius = 4.0;

    if (argc > 1)
    {
        // This try-catch block output errors if argv[1] cannot be mapped to double-type numbers
        // Unlike isdigit(), strings like "-10.5" or "10.0" can be converted
        try
        {
            radius = std::stod(argv[1]);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid radius, must be a number" << std::endl;
            return EXIT_FAILURE;
        }
    }

    bool isPositive = (radius >= 0);

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