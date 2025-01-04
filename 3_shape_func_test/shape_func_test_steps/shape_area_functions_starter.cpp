#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "shapes_7.hpp"

//double conversion (std::string);
//double area(double );
//double area(double , double );
//double area(double , double , double );

// This is where we stopped on Monday 09/16
int main(int argc, char *argv[])
{

    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    if (argc > 3)
    {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return EXIT_FAILURE;
    }
    else if (argc == 2)
    {
        input_file = argv[1];
    }
    else if (argc == 3)
    {
        input_file = argv[1];
        output_file = argv[2];
    }

    std::ifstream file_read(input_file);
    std::ofstream file_write(output_file);

    if (file_read.fail())
    {
        std::cout << "File input error" << std::endl;
        return EXIT_FAILURE;
    }
    else if (file_write.fail())
    {
        std::cout << "Output file error" << std::endl;
        file_read.close();
        return EXIT_FAILURE;
    }

    std::string line;
    int dimension = 0;
    int first_comma_index, second_comma_index;
    
    while (getline(file_read, line))
    {
        first_comma_index = line.find(",");
        
        std::string first_sub_string, second_sub_string, third_sub_string;

        if (first_comma_index == std::string::npos)
        {
            std::cout << "It's a circle" << std::endl;
            first_sub_string = line;
            dimension = 1;
        }
        else
        {
            first_sub_string = line.substr(0, first_comma_index);
            second_sub_string = line.substr(first_comma_index+1, std::string::npos);
            
            second_comma_index = second_sub_string.find(",");
            if (second_comma_index == std::string::npos){
                std::cout << "It's a rectangle" << std::endl;
                dimension = 2;
            }
            else{
                std::cout << "It's a triangle" << std::endl;
                dimension = 3;
                third_sub_string = second_sub_string.substr(second_comma_index+1, std::string::npos);
                second_sub_string = second_sub_string.substr(0, second_comma_index);
            }
        }

        double first_number, second_number, third_number;
        if (dimension >=1)
        {
            first_number = conversion(first_sub_string);
        }
        if (dimension >=2)
        {
            second_number = conversion(second_sub_string);
        }

        if (dimension ==3)
        {
            third_number = conversion(third_sub_string);
        }

        bool isPositive = (first_number >= 0 && second_number>=0 && third_number >=0);

        if (!isPositive)
        {
            std::cout << "Invalid numbers, ";
            std::cout << " should be positive" << std::endl;
            return EXIT_FAILURE;
        }

        double result;
        if (dimension==1){
            result = area(first_number);
        }
        else if (dimension==2){
            result = area(first_number, second_number);
        }
        else if (dimension == 3){
            result = area(first_number, second_number, third_number);
        }

        // calculate and output area as pi*r^2
        //file_write << "Radius is : ";
        file_write << std::fixed;
        file_write << std::setprecision(2);
        //file_write << radius << ", ";
        file_write << "Area is : " << result << std::endl;

    }

    file_read.close();
    file_write.close();
    return EXIT_SUCCESS;
}

// double conversion (std::string input_string){

//     double output_number;
//     try
//     {
//         output_number = std::stod(input_string);
//     }
//     catch (std::invalid_argument)
//     {
//         std::cout << "Invalid dimension, must be a number" << std::endl;
//         return -1;
//     }
//     return output_number;
// }

// double area(double r)
// {
//     return M_PI * pow(r, 2);
// }
// double area(double w, double l)
// {
//     return w * l;
// }
// double area(double a, double b, double angle)
// {
//     return 0.5 * a * b * sin(angle * M_PI / 180);
// }