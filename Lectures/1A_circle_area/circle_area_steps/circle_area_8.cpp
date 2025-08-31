// This is circle_area_8.cpp
// Changes compared to circle_area_7.cpp:
// Add while-loop to repeat the area calculation

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

int main()
{
  char answer = 'y'; // variable declaration must be before the while loop

  while (answer == 'y' || answer == 'Y')
  {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    if (!std::cin.good())
    {
      std::cout << "Invalid input type" << std::endl;
      return EXIT_FAILURE;
    }

    if (radius < 0)
    {
      std::cout << "Invalid radius, must be positive" << std::endl;
      return EXIT_FAILURE;
    }

    double area = M_PI * pow(radius, 2);
    std::cout << "The area is: ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << area << std::endl;

    std::cout << "Do you want to calculate another area? (y/n): ";
    std::cin >> answer;
  }

  // while-loop syntax: if condition is true, loop body is executed
  // then the condition is checked again.

  /*
  while (condition)
  {
    loop body
  }
  */

  return EXIT_SUCCESS;
}