// This is circle_area_4.cpp
// Changes compared to circle_area_3.cpp:
// format output for area to show 5 decimal places

#include <iostream>
#include <iomanip> // must include this header if std::fixed and std::setprecision(5) are used

int main()
{
    int radius = 4;
    const double PI = 3.14159;

    // calculate and output area as pi*r^2
    double area = PI * radius * radius;
    std::cout << "The area is: ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << area << std::endl;
}