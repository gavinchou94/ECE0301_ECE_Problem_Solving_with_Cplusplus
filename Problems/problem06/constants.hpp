#ifndef _CONSTANTS
#define _CONSTANTS

#include <string>

const double THRESHOLD = 1e-9;

const int COLS = 6;
const int ENTRIES = 5;

const std::string FIELDS[COLS] = {
    "ID", "Class", "Mean Radius", "Mass", "Density", "Orbit"};

const double DATA[ENTRIES][COLS] = {
    // ID   Class   Rad [km]    Mass [kg]   Dens [g/cm^3]   Orbit [y]
    // sun
    {10, 0, 695700, 1988500e24, 1.408, 0},
    // mercury
    {199, 1, 2440.53, 0.330103e24, 5.4289, 0.2408467},
    // venus
    {299, 1, 6051.8, 4.86731e24, 5.243, 0.61519726},
    // earth
    {399, 1, 6371.0084, 5.97217e24, 5.5134, 1.0000174},
    // mars
    {499, 1, 3389.50, 0.641691e24, 3.9340, 1.8808476}};

#endif