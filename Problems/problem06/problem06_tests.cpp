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
TEST_CASE("Test Search Missing", "[database][search]")
{
    double *db = new double[ENTRIES * COLS];
    initialize(db);

    REQUIRE_FALSE(search("Temperature", 315, db, ENTRIES));
    REQUIRE_FALSE(search("Class", 3.1415, db, ENTRIES));
    REQUIRE_FALSE(search("ID", 2.1, db, ENTRIES));

    delete[] db;
}
TEST_CASE("Test Add Moon", "[database][search][add_entry]")
{
    int oldrows = ENTRIES;
    double *db = new double[ENTRIES * COLS];
    initialize(db);
    int rows = oldrows;

    const double moon[COLS] = {301, 3, 1737.4, 7.349e22, 3.3437, 27.321582};

    REQUIRE(add_entry(moon, db, rows));
    REQUIRE(rows == oldrows + 1);
    REQUIRE(search("ID", 301.0, db, rows));
    REQUIRE(search("Mean Radius", 1737.4, db, rows));

    delete[] db;
}
TEST_CASE("Test Copy Earth", "[database][search][add_entry]")
{
    int oldrows = ENTRIES;
    double *db = new double[ENTRIES * COLS];
    initialize(db);
    int rows = oldrows;

    const double copyearth[COLS] = {DATA[3][0], DATA[3][1], DATA[3][2], DATA[3][3], DATA[3][4], DATA[3][5]};

    REQUIRE_FALSE(add_entry(copyearth, db, rows));
    REQUIRE(rows == oldrows);
    REQUIRE(search("ID", 399, db, rows));

    delete[] db;
}
TEST_CASE("Test Remove Sun", "[database][remove_entry]")
{
    double *db = new double[ENTRIES * COLS];
    initialize(db);
    int row = ENTRIES;

    double sunid = 10;

    REQUIRE(search("ID", sunid, db, row));
    REQUIRE(remove_entry(sunid, db, row));
    REQUIRE(row == ENTRIES - 1);
    REQUIRE_FALSE(search("ID", sunid, db, row));
    REQUIRE(search("ID", 399, db, row));
    REQUIRE_FALSE(remove_entry(9999, db, row));

    delete[] db;
}
TEST_CASE("Test search add remove", "[database][search][add_entry][remove_entry]")
{
    int oldrows = ENTRIES;
    double *db = new double[ENTRIES * COLS];
    initialize(db);
    int rows = oldrows;

    const double moon[COLS] = {301, 3, 1737.4, 7.349e22, 3.3437, 27.321582};

    REQUIRE(add_entry(moon, db, rows));
    REQUIRE(search("ID", 301.0, db, rows));
    REQUIRE(remove_entry(399, db, rows)); // Goodbye Earth
    REQUIRE_FALSE(search("ID", 399, db, rows));
    REQUIRE(search("ID", 301, db, rows));
    REQUIRE(rows == ENTRIES);

    delete[] db;
}