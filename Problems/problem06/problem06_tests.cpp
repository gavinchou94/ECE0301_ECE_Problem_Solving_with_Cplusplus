#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cmath>

#include "database.hpp"
#include "constants.hpp"

/* Provided test cases */

TEST_CASE("Test initialize", "[database]")
{
    // create the database as a dynamic array
    // ENTRIES and COLS are defined in constants.hpp
    // as the number of rows and columns in DATA, respectively
    double *db = new double[ENTRIES * COLS];
    // use the provided initialize function to fill db with entries from DATA
    initialize(db);

    // Get each value in the dynamic array db, and confirm that it matches
    // the corresponding value in DATA.
    // This tests that the initialize function called above
    // has correctly copied all of the values from DATA into db.
    double dbval, ref, diff;
    bool db_matches_DATA = true; // define a boolean to reduce REQUIRE statements in the loop
    for (int r = 0; r < ENTRIES; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            // use the index function to get a 1D index for db from the row,column
            dbval = db[index(r, c)];
            // use double brackets to index DATA as a static 2D array
            ref = DATA[r][c];
            // these are double values, so we should check that their difference
            // is within a threshold instead of using ==
            diff = std::abs(dbval - ref);
            db_matches_DATA = (diff <= THRESHOLD);
            if (!db_matches_DATA)
            {
                // if any mismatch is detected, stop the comparisons
                break;
            }
        }
        if (!db_matches_DATA)
        {
            // need a second break to break out of the outer loop
            break;
        }
    }
    // check whether the loops completed without a mismatch
    REQUIRE(db_matches_DATA);

    // always deallocate at the end of each test case
    // when allocating with "new" in that test case
    delete[] db;
}

TEST_CASE("Test search", "[database]")
{
    double *db = new double[ENTRIES * COLS];
    initialize(db);

    // search for each DATA value in the corresponding column of db
    std::string field;
    double value;
    bool db_search = true;
    for (int r = 0; r < ENTRIES; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            // defining field and value outside of the function call
            // makes debugging easier
            field = FIELDS[c];
            value = DATA[r][c];
            db_search = search(field, value, db, ENTRIES);
            if (!db_search)
            {
                break;
            }
        }
        if (!db_search)
        {
            break;
        }
    }
    REQUIRE(db_search);

    delete[] db;
}

/* Write your own test cases here */