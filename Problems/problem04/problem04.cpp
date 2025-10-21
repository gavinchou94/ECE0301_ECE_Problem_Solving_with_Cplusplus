#include "circuits.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void log_invalid_input(ifstream &reader, ofstream &writer);
double get_current(double resistance, double power);
double get_resistance(double current, double power);
double get_power(double current, double resistance);
double get_value(string expression_string);

int main(int argc, char *argv[])
{
    string inputFile = "..//tests/test_input.txt";
    string outputFile = "..//tests/my_test_output.txt";

    // cin >> inputFile;
    if (argc == 2)
    {
        inputFile = argv[1];
    }

    if (argc == 3)
    {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    ifstream reader(inputFile);
    ofstream writer(outputFile);

    if (reader.fail())
    {
        cout << "Fail input error" << endl;
        return EXIT_FAILURE;
    }
    if (writer.fail())
    {
        cout << "Fail output error" << endl;
        writer.close();
        return EXIT_FAILURE;
    }

    string line;
    while (getline(reader, line))
    {

        if (count(line.begin(), line.end(), ',') != 1)
            log_invalid_input(reader, writer);
        int commaIndex = line.find(',');
        string termA = line.substr(0, commaIndex);
        string termB = line.substr(commaIndex + 1);

        if (count(termA.begin(), termA.end(), '=') != 1 || count(termB.begin(), termB.end(), '=') != 1)
        {
            log_invalid_input(reader, writer);
        }
        int equalIndexA = termA.find('=');
        int equalIndexB = termB.find('=');

        string varNameA = termA.substr(0, equalIndexA);
        string varNameB = termB.substr(0, equalIndexB);

        string numStrA = termA.substr(equalIndexA + 1);
        string numStrB = termB.substr(equalIndexB + 1);
        // Removes all the whitespaces in the varNames
        varNameA.erase(remove(varNameA.begin(), varNameA.end(), ' '), varNameA.end());
        varNameB.erase(remove(varNameB.begin(), varNameB.end(), ' '), varNameB.end());

        if ((varNameA != "R" && varNameA != "I" && varNameA != "P") ||
            (varNameB != "R" && varNameB != "I" && varNameB != "P") ||
            (varNameA == varNameB))
        {
            log_invalid_input(reader, writer);
        }
        double numA, numB;

        bool missingR = (varNameA == "I" && varNameB == "P") || (varNameA == "P" && varNameB == "I");
        bool missingI = (varNameA == "R" && varNameB == "P") || (varNameA == "P" && varNameB == "R");
        bool missingP = (varNameA == "I" && varNameB == "R") || (varNameA == "R" && varNameB == "I");

        numA = get_value(termA);
        numB = get_value(termB);

        double result;
        string units[3]; // 0 = Term A, 1 = Term B, 2 = missing variable
        string missingVar;

        if (missingP && !missingI && !missingR)
        { // Check if power is missing
            // calculatePower(varNameA, numA, varNameB, numB, writer);
            result = (varNameA == "I") ? get_power(numA, numB) : get_power(numB, numA);

            // if varNameA is I in the first term, then the message would be <If I = numA Amps and R = numB Ohms, then P = result Watts.>
            // if false, then the message would be <If R = numA Ohms and I = numB Amps, then ...>
            units[0] = (varNameA == "I") ? " Amps" : " Ohms";
            units[1] = (varNameA == "I") ? " Ohms" : " Amps";
            units[2] = " Watts.\n";
            missingVar = "P";
        }
        else if (missingR && !missingP && !missingI)
        { // Check if resistance is missing
          // calculateResistance(varNameA, numA, varNameB, numB, writer);
            result = (varNameA == "I") ? get_resistance(numA, numB) : get_resistance(numB, numA);
            units[0] = (varNameA == "I") ? " Amps" : " Watts";
            units[1] = (varNameA == "I") ? " Watts" : " Amps";
            units[2] = " Ohms.\n";
            missingVar = "R";
        }
        else if (missingI && !missingR && !missingP)
        { // Check if current is missing
          // calculateCurrent(varNameA, numA, varNameB, numB, writer);
            result = (varNameA == "R") ? get_current(numA, numB) : get_current(numB, numA);
            units[0] = (varNameA == "R") ? " Ohms" : " Watts";
            units[1] = (varNameA == "R") ? " Watts" : " Ohms";
            units[2] = " Amps.\n";
            missingVar = "I";
        }
        else
        {
            // This case would mean all three values were provided.
            log_invalid_input(reader, writer);
        }

        writer << fixed << setprecision(3);
        writer << "If " << varNameA << " = " << (numA) << units[0]
               << " and " << varNameB << " = " << (numB) << units[1]
               << ", then " << missingVar << " = " << (result) << units[2];
    }
    reader.close();
    writer.close();
    return EXIT_SUCCESS;
}
