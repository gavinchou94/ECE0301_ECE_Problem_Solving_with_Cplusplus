#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void calculateResistance(string varNameA, double numA, string varNameB, double numB, ofstream &writer);
void calculateCurrent(string varNameA, double numA, string varNameB, double numB, ofstream &writer);
void calculatePower(string varNameA, double numA, string varNameB, double numB, ofstream &writer);
void errorexit(ifstream &reader, ofstream &writer);

int main(int argc, char *argv[])
{
    string inputFile = "input.txt";
    string outputFile = "output.txt";

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
            errorexit(reader, writer);
        int commaIndex = line.find(',');
        string termA = line.substr(0, commaIndex);
        string termB = line.substr(commaIndex + 1);

        if (count(termA.begin(), termA.end(), '=') != 1 || count(termB.begin(), termB.end(), '=') != 1)
        {
            errorexit(reader, writer);
        }
        int equalIndexA = termA.find('=');
        int equalIndexB = termB.find('=');

        string varNameA = termA.substr(0, equalIndexA);
        string varNameB = termB.substr(0, equalIndexB);

        string numStrA = termA.substr(equalIndexA + 1);
        string numStrB = termB.substr(equalIndexB + 1);

        varNameA.erase(remove(varNameA.begin(), varNameA.end(), ' '), varNameA.end());
        varNameB.erase(remove(varNameB.begin(), varNameB.end(), ' '), varNameB.end());

        if ((varNameA != "R" && varNameA != "I" && varNameA != "P") ||
            (varNameB != "R" && varNameB != "I" && varNameB != "P") ||
            (varNameA == varNameB))
        {
            errorexit(reader, writer);
        }
        double numA, numB;
        try
        {
            // stod (string to double) will throw an error if the string
            // is not a valid number (e.g., empty, or "A").
            numA = stod(numStrA);
            numB = stod(numStrB);
        }
        catch (const invalid_argument &e)
        {
            // This 'catch' block runs if stod fails.
            errorexit(reader, writer);
        }

        // --- Assign values to the correct variables ---
        double current = NAN, power = NAN, resistance = NAN;

        if (varNameA == "I") current = numA;
        else if (varNameA == "R") resistance = numA;
        else if (varNameA == "P") power = numA;

        if (varNameB == "I") current = numB;
        else if (varNameB == "R") resistance = numB;
        else if (varNameB == "P") power = numB;

        // --- Calculate the missing value ---
        if (isnan(power))
        { // Check if power is missing
            calculatePower(varNameA, numA, varNameB, numB, writer);
        }
        else if (isnan(resistance))
        { // Check if resistance is missing
            calculateResistance(varNameA, numA, varNameB, numB, writer);
        }
        else if (isnan(current))
        { // Check if current is missing
            calculateCurrent(varNameA, numA, varNameB, numB, writer);
        }
        else
        {
            // This case would mean all three values were provided.
            errorexit(reader, writer);
        }
    }
    reader.close();
    writer.close();
    return EXIT_SUCCESS;
}
void errorexit(ifstream &reader, ofstream &writer)
{
    cout << "Invalid input format." << endl;
    reader.close();
    writer.close();
    exit(EXIT_FAILURE);
}
void calculateResistance(string varNameA, double numA, string varNameB, double numB, ofstream &writer)
{
    double current, power;

    if (varNameA == "I")
    {
        current = numA;
        power = numB;
        double result = power / pow(current, 2);
        writer << fixed << setprecision(3);
        writer << "If I = " << current << " Amps and P = " << power << " Watts, then R = " << result << " Ohms." << endl;
    }
    else
    {
        power = numA;
        current = numB;
        double result = power / pow(current, 2);
        writer << fixed << setprecision(3);
        writer << "If P = " << power << " Watts and I = " << current << " Amps, then R = " << result << " Ohms." << endl;
    }
}

void calculateCurrent(string varNameA, double numA, string varNameB, double numB, ofstream &writer)
{
    double power, resistance;

    if (varNameA == "R")
    {
        resistance = numA;
        power = numB;
        double result = sqrt(power / resistance);
        writer << fixed << setprecision(3);
        writer << "If R = " << resistance << " Ohms and P = " << power << " Watts, then I = " << result << " Amps." << endl;
    }
    else
    {
        resistance = numA;
        power = numB;
        double result = sqrt(power / resistance);
        writer << fixed << setprecision(3);
        writer << "If P = " << power << " Watts and R = " << resistance << " Ohms, then I = " << result << " Amps." << endl;
    }
}

void calculatePower(string varNameA, double numA, string varNameB, double numB, ofstream &writer)
{
    double current, resistance;
    // Checks if the first term of the line
    if (varNameA == "I")
    {
        current = numA;
        resistance = numB;
        double result = pow(current, 2) * resistance;
        writer << fixed << setprecision(3);
        writer << "If I = " << current << " Amps and R = " << resistance << " Ohms, then P = " << result << " Watts." << endl;
    }
    else
    {
        resistance = numA;
        current = numB;
        double result = pow(current, 2) * resistance;
        writer << fixed << setprecision(3);
        writer << "If R = " << resistance << " Ohms and I = " << current << " Amps, then P = " << result << " Watts." << endl;
    }
}