// This is circle_area_3b.cpp
// Changes compared to circle_area_3.cpp:
// declare area to be int type, which would truncate all decimal places, not a good practice
// Another common error is using int to do divisions: 1/2 = 0, 1/2.0 = 0.5

#include <iostream>

int main()
{
    int radius = 4;
    const double PI = 3.14159;

    // calculate and output area as pi*r^2
    int area = PI * radius * radius;
    std::cout << "The area is: ";
    std::cout << area << std::endl;
}