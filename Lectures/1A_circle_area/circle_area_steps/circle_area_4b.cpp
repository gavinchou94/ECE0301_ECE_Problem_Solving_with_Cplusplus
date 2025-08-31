// This is circle_area_4b.cpp
// Changes compared to circle_area_4.cpp:
// calculating area using pow function and constant M_PI from library

#include <iostream>
#include <iomanip>
#include <cmath> // must include this header if pow function and constant M_PI are used

int main()
{
    int radius = 4;

    // calculate and output area as pi*r^2
    double area = M_PI * pow(radius, 2);
    std::cout << "The area is: ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << area << std::endl;
}