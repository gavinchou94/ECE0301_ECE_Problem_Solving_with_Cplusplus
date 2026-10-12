#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

const double THRESHOLD = 1e-9;
const int COLS = 6;
const int ENTRIES = 5;

const std::string FIELDS[COLS] = {
    "ID", "Units", "Pins", "Transistors", "Maximum Delay", "Power per Unit"};

const double DATA[ENTRIES][COLS] = {
    // ID    Units  Pins  Transistors  Maximum Delay [ns]  Power per Unit [mW]
    // quad 2-input NAND gates
    {7400, 4, 14, 40, 22.0, 2.0},
    // quad 2-input AND gates
    {7408, 4, 14, 40, 15.0, 2.0},
    // single 8-input NAND gate
    {7430, 1, 14, 50, 22.0, 2.0},
    // BCD-to-7-segment decoder/driver
    {7447, 1, 16, 80, 35.0, 30.0},
    // dual JK flip-flops
    {7473, 2, 14, 90, 20.0, 15.0}};

#endif