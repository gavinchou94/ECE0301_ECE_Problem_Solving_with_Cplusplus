// This is shape_area_functions_6.cpp
// Changes from shape_area_functions_5.cpp:
// extract the area calculation to functions
// make sure to include the function prototype/signature in the begining
// note the identical function names, it is acceptable due to function overloading

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

double conversion(std::string);
double area(double);
double area(double, double);
double area(double, double, double);

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

        // find first comma, second comma, third comma
        std::string first_sub_string, second_sub_string, third_sub_string;

        // one-number case
        first_comma_index = line.find(",");
        if (first_comma_index == std::string::npos)
        {
            std::cout << "It's a circle" << std::endl;
            first_sub_string = line;
            dimension = 1;
        }
        else
        {
            // string object member function substr() has two arguments
            // substr(starting_index, ending_index)
            // ending_index can be line.length() or can be -1
            first_sub_string = line.substr(0, first_comma_index);
            second_sub_string = line.substr(first_comma_index + 1, std::string::npos);

            second_comma_index = second_sub_string.find(",");

            // two-number case
            if (second_comma_index == std::string::npos)
            {
                std::cout << "It's a rectangle" << std::endl;
                dimension = 2;
                // in this case, second_sub_string is all we need to find numbers
            }
            // three-number case
            else
            {
                std::cout << "It's a triangle" << std::endl;
                dimension = 3;
                // in this case, further split second_sub_string to second_sub and third_sub
                third_sub_string = second_sub_string.substr(second_comma_index + 1, std::string::npos);
                second_sub_string = second_sub_string.substr(0, second_comma_index);
            }
        }

        std::string input = line.substr(first_comma_index + 1, line.length());

        double first_number, second_number, third_number;
        if (dimension >= 1)
        {
            try
            {
                first_number = std::stod(first_sub_string);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input, must be a number" << std::endl;
                file_read.close(); // make sure you close the fild_read & file_write objects
                file_write.close();
                return EXIT_FAILURE;
            }
        }

        if (dimension >= 2)
        {
            try
            {
                second_number = std::stod(second_sub_string);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input, must be a number" << std::endl;
                file_read.close();
                file_write.close();
                return EXIT_FAILURE;
            }
        }

        if (dimension == 3)
        {
            try
            {
                third_number = std::stod(third_sub_string);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input, must be a number" << std::endl;
                file_read.close();
                file_write.close();
                return EXIT_FAILURE;
            }
        }

        bool isPositive = (first_number >= 0 && second_number >= 0 && third_number >= 0);

        if (!isPositive)
        {
            std::cout << "Negative numbers,";
            std::cout << " should be positive" << std::endl;
            file_read.close();
            file_write.close();
            return EXIT_FAILURE;
        }

        double result;
        if (dimension == 1)
        {
            result = area(first_number);
        }
        else if (dimension == 2)
        {
            result = area(first_number, second_number);
        }
        else if (dimension == 3)
        {
            result = area(first_number, second_number, third_number);
        }

        // file_write << "Radius is : ";
        file_write << std::fixed;
        file_write << std::setprecision(2);
        // file_write << radius << ", ";
        file_write << "Area is : " << result << std::endl;
    }

    file_read.close();
    file_write.close();
    return EXIT_SUCCESS;
}

double conversion(std::string input_string)
{
    double output_number;
    try
    {
        output_number = std::stod(input_string);
    }
    catch (std::invalid_argument)
    {
        return -1;
    }
    return output_number;
}

double area(double r)
{
    return M_PI * pow(r, 2);
}
double area(double w, double l)
{
    return w * l;
}
double area(double a, double b, double angle)
{
    return 0.5 * a * b * sin(angle * M_PI / 180);
}