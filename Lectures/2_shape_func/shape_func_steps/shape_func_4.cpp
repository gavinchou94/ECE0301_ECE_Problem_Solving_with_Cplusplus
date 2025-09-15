// This is shape_func_4.cpp
// Changes from shape_func_3.cpp:
// 1. verify each number to be valid
// 2. calculate the area based on dimension indicator

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string input_file = "../input.txt";
    std::string output_file = "../output.txt";

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

        // find first comma, second comma
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
            first_sub_string = line.substr(0, first_comma_index);
            second_sub_string = line.substr(first_comma_index + 2, std::string::npos);

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
                third_sub_string = second_sub_string.substr(second_comma_index + 2, std::string::npos);
                second_sub_string = second_sub_string.substr(0, second_comma_index);
            }
        }

        std::string first_number, second_number, third_number;
        double first_value, second_value, third_value;
        int equals_index;

        if (dimension >= 1)
        {
            equals_index = first_sub_string.find("=");

            if (equals_index == std::string::npos)
            {
                std::cout << "Input formatting error" << std::endl;
                file_read.close(); // make sure you close the file_read & file_write objects
                file_write.close();
                return EXIT_FAILURE;
            }

            first_number = first_sub_string.substr(equals_index + 2, first_sub_string.length());

            try
            {
                first_value = std::stod(first_number);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input, must be a number" << std::endl;
                file_read.close();
                file_write.close();
                return EXIT_FAILURE;
            }
        }

        if (dimension >= 2)
        {
            equals_index = second_sub_string.find("=");

            if (equals_index == std::string::npos)
            {
                std::cout << "Input formatting error" << std::endl;
                file_read.close(); // make sure you close the file_read & file_write objects
                file_write.close();
                return EXIT_FAILURE;
            }

            second_number = second_sub_string.substr(equals_index + 2, second_sub_string.length());

            try
            {
                second_value = std::stod(second_number);
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
            equals_index = third_sub_string.find("=");

            if (equals_index == std::string::npos)
            {
                std::cout << "Input formatting error" << std::endl;
                file_read.close(); // make sure you close the file_read & file_write objects
                file_write.close();
                return EXIT_FAILURE;
            }

            third_number = third_sub_string.substr(equals_index + 2, third_sub_string.length());

            try
            {
                third_value = std::stod(third_number);
            }
            catch (std::invalid_argument)
            {
                std::cout << "Invalid input, must be a number" << std::endl;
                file_read.close();
                file_write.close();
                return EXIT_FAILURE;
            }
        }

        bool isGood = (first_value >= 0 && second_value >= 0 && third_value > -1 && third_value < 1);

        if (!isGood)
        {
            std::cout << "Invalid numbers" << std::endl;
            file_read.close();
            file_write.close();
            return EXIT_FAILURE;
        }

        double area;
        if (dimension == 1)
        {
            area = M_PI * pow(first_value, 2);
        }
        else if (dimension == 2)
        {
            area = first_value * second_value;
        }
        else if (dimension == 3)
        {
            area = 0.5 * first_value * second_value * third_value;
        }

        file_write << std::fixed << std::setprecision(2);
        file_write << "Area is : " << area << std::endl;
    }

    file_read.close();
    file_write.close();
    return EXIT_SUCCESS;
}