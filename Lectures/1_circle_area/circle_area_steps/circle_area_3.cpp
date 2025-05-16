// This is circle_area_3.cpp
// Changes compared to circle_area_2.cpp:
// introduce variable area and output that variable

#include <iostream>

int main() {

    int radius = 4;
    const double PI = 3.14159;
    
    // calculate and output area as pi*r^2
    double area = PI*radius*radius;
    std::cout << "Radius is " << radius << std::endl;
    std::cout << "Area is " << area << std::endl;

}