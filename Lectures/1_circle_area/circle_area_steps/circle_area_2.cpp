// This is circle_area_2.cpp
// Changes compared to circle_area_starter.cpp:
// introduce variable radius and constant PI

#include <iostream>

int main() {

    int radius = 4;
    const double PI = 3.14159;

    // calculate and output area as pi*r^2
    std::cout << "Radius is " << radius << std::endl;
    std::cout << "Area is " << PI*radius*radius << std::endl;

}