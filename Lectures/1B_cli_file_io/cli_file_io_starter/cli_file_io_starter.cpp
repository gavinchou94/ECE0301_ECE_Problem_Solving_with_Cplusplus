#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main()
{
  double radius;

  // user input
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  if (!std::cin.good()) // cin.good() would check whether cin input matches the desired data type ()
  {
    std::cout << "Invalid input type" << std::endl;
    return EXIT_FAILURE;
  }
  else if (radius < 0)
  {
    std::cout << "Invalid radius, must be positive" << std::endl;
    return EXIT_FAILURE;
  }

  double area = M_PI * pow(radius, 2);
  std::cout << "The area is: ";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << std::endl;

  return EXIT_SUCCESS;
}