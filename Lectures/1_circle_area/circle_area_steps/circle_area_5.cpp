// This is circle_area_5.cpp
// Changes compared to circle_area_4b.cpp:
// allowing user to input a radius from console, instead fixing it to be 4

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

    int radius;

    // user input
    std::cout << "Enter radius: ";
    std::cin >> radius;

    // calculate and output area as pi*r^2
    double area = M_PI*pow(radius,2);
    std::cout << "Radius is " << radius << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area is " << area << std::endl;

}