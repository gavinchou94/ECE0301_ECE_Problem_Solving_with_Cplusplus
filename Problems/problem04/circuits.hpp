#ifndef _CIRCUITS_HPP
#define _CIRCUITS_HPP
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

void log_invalid_input(ifstream &reader, ofstream &writer)
{
    cout << "Invalid input format." << endl;
    reader.close();
    writer.close();
    exit(EXIT_FAILURE);
}
double get_value(string expression_string)
{
    int equals_index = expression_string.find("=");
    if (equals_index == std::string::npos)
    {
        cout << "Input formatting error" << endl;
        return -1;
    }
    string numstring = expression_string.substr(equals_index + 2, expression_string.length());
    double value;
    try
    {
        value = stod(numstring);
    }
    catch (invalid_argument)
    {
        return -1;
    }
    return value;
}
double get_current(double resistance, double power)
{
    if (resistance < 0 || power < 0)
    {
        return -1;
    }
    else
    {
        return sqrt(power / resistance);
    }
}
double get_resistance(double current, double power)
{
    if (current < 0 || power < 0)
    {
        return -1;
    }
    else
    {
        return power / pow(current, 2);
    }
}
double get_power(double current, double resistance)
{
    if (resistance < 0 || current < 0)
    {
        return -1;
    }
    else
    {
        return pow(current, 2) * resistance;
    }
}
double get_divider_power(double source_power, double resistance1, double resistance2)
{ // I use Google to double check if the divider power formula is correct
    if (resistance1 < 0 || resistance2 < 0 || source_power < 0)
    {
        return -1;
    }
    else
    {
        return source_power * (resistance2 / (resistance1 + resistance2));
    }
}

#endif