// This is circle_area_3b.cpp
// Changes compared to circle_area_3.cpp:
// declare area to be int type, which would truncate all decimal places
// Not a good pratice

#include <iostream>

int main() {

    int radius = 4;
    const double PI = 3.14159;
    
    // calculate and output area as pi*r^2
    int area = PI*radius*radius;
    std::cout << "Radius is " << radius << std::endl;
    std::cout << "Area is " << area << std::endl;

}