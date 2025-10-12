#ifndef _DATABASE_HPP
#define _DATABASE_HPP

#include <cstdlib>
#include <string>

#include "constants.hpp"

/* Provided functions */
int index(int row, int col)
{
    /* Calculates a 1D index from a row and column.
        A 2D matrix can be represented in memory with a 1D array,
        assuming that indices 0 to COLS-1 are the items in the first row,
        indices COLS to 2*COLS-1 are the items in the second row, etc.
        So if we want to access data at a specific row and column,
        we calculate that index as row*COLS + column
    */
    return row * COLS + col;
}

int column_index(std::string field)
{
    /* Uses parallel arrays to determine the integer column index
        given the string field name.
        FIELDS is defined in constants.hpp. This function does a linear
        search over the FIELDS array to find and return the index of the
        column with the specified field name.
        Returns -1 if field name is not valid.
    */
    for (int c = 0; c < COLS; c++)
    {
        if (FIELDS[c] == field)
        {
            return c;
        }
    }
    return -1;
}

void initialize(double *database)
{
    /* Fills the dynamic array database with data from the constant DATA.
        Note the use of the index function to get the index for the dynamic array
        database, versus using double brackets for the the static 2D array DATA.
    */
    for (int r = 0; r < ENTRIES; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            database[index(r, c)] = DATA[r][c];
        }
    }
}

/* Functions to implement */
bool search(const std::string field, const double value,
            const double *database, const int rows)
{
    // TODO
    return false;
}

bool add_entry(const double new_row[],
               double *&database, int &rows)
{
    // TODO, refer to general workflow of append() in steps/pointers_6.hpp
    return false;
}

bool remove_entry(const double id,
                  double *&database, int &rows)
{
    // TODO
    return false;
}

#endif