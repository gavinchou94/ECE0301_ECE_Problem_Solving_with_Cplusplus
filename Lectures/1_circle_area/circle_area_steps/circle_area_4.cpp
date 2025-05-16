// This is circle_area_4.cpp
// Changes compared to circle_area_3.cpp:
// format output for area to show 2 decimal places
// Starting here, try Cmake debug and add breakpoint to view variables

#include <iostream>
#include <iomanip> // must include this header if std::fixed and std::setprecision(2) are used

int main() {

    int radius = 4;
    const double PI = 3.14159;
    
    // calculate and output area as pi*r^2
    double area = PI*radius*radius;
    std::cout << "Radius is " << radius << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area is " << area << std::endl;

}