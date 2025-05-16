// This is circle_area_7.cpp
// Changes compared to circle_area_6.cpp:
// 1. also check whether cin is a number first, and show error message if not
// 2. place "if-else if" structure ahead of calculation to exit program as early as possible upon invalid input
// In terminal, try both {4, -4 and abcd} to cin to test results
// Starting here, try Cmake debug with cin (i.e., create a launch.json file)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

int main() {

    double radius;

    std::cout << "Enter radius: ";
    std::cin >> radius;

    if (!std::cin.good()) { //cin.good() would check whether cin input matches the desired data type () 
        std::cout << "Invalid input type" << std::endl;
        return EXIT_FAILURE;
    } else if (radius < 0) {
        std::cout << "Invalid radius, must be positive" << std::endl;
        return EXIT_FAILURE;
    } 
    
    // calculate and output area as pi*r^2
    double area = M_PI*pow(radius,2);
    std::cout << "Radius is " << radius << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area is " << area << std::endl;
    

    return EXIT_SUCCESS;
}