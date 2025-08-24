/* hello_world.cpp */
/* Run on terminal using ``g++ -o hello_world hello_world.cpp`` && ``./hello_world`` */

#include <cstdlib>  // For EXIT_SUCCESS
#include <iostream> // For std::cout, std::endl

int main()
{
    std::cout << "Hello World!!!" << std::endl;

    // use 'return EXIT_SUCCESS;' for better portability and code clarity
    // as EXIT_SUCCESS is defined by the C++ standard to indicate successful program termination.
    return EXIT_SUCCESS; // same as return 0;
}