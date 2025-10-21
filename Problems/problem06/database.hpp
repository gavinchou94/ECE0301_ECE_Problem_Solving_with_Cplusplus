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
    int col = column_index(field);

    if (col == -1)
        return false;

    for (int i = 0; i < rows; i++)
    {
        int dbindex = index(i, col);
        double dbval = database[dbindex];
        if (std::abs(dbval - value) <= THRESHOLD)
        {
            return true;
        }
    }
    return false;
}

bool add_entry(const double new_row[],
               double *&database, int &rows)
{
    // TODO, refer to general workflow of append() in steps/pointers_6.hpp
    if (search(FIELDS[0], new_row[0], database, rows))
    {
        return false;
    }
    double *newdb = new double[(rows + 1) * COLS];

    for (int i = 0; i < rows * COLS; i++)
    {
        newdb[i] = database[i];
    }
    for (int j = 0; j < COLS; j++)
    {
        newdb[index(rows, j)] = new_row[j];
    }
    delete[] database;
    database = newdb;
    rows++;
    return true;
}

bool remove_entry(const double id,
                  double *&database, int &rows)
{
    // TODO
    if (!search(FIELDS[0], id, database, rows))
    {
        return false;
    }
    int remove_r = -1;
    for (int i = 0; i < rows; i++)
    {
        double dbid = database[index(i, 0)];
        if (std::abs(dbid - id) <= THRESHOLD)
        {
            remove_r = i;
            break;
        }
    }
    if (remove_r == -1)
    {
        return false;
    }
    int newr = rows-1;
    delete[] database;

    if (newr == 0)
    {
        database = nullptr;
        rows = newr;
        return true;
    }
    double *newdata = new double[newr * COLS];
    int newdbi = 0;
    for (int i = 0; i < rows; i++)
    {
        if (i != remove_r)
        {
            for (int j = 0; j < COLS; j++)
            {
                newdata[newdbi] = database[index(i, j)];
                newdbi++;
            }
        }
    }
    database = newdata;
    rows = newr;
    return true;
}
#endif