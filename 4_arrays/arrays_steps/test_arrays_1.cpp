// This is test_arrays_1.cpp
// Changes from test_arrays_starter.cpp:
// declare an array variable and verify its indexing

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Test array indexing", "[array-index]")
{
    // int arr[]; // not allowed, size is not specified
    // int arr[] = {0,10,20,30,40}; // Size is inferred
    // int arr[4] = {0,10,20,30,40}; // bad example, mismatched
    // int arr[5]; // valid but uninitialized
    int arr[5] = {0, 10, 20, 30, 40}; // make sure to match size

    // One way to test indexing one by one
    //REQUIRE(arr[0]==0);
    //REQUIRE(arr[1]==10);
    //REQUIRE(arr[2]==20);
    //REQUIRE(arr[3]==30);
    //REQUIRE(arr[4]==40);

    // Another way to test indexing using for-loop
    for (int i = 0; i < 5; i++)
    {
        REQUIRE(arr[i]==10*i);
    }

    //int test = arr[5]; // test access out of bounds
}

TEST_CASE("Test array printing", "[array-printing]")
{
    REQUIRE(true);
}

TEST_CASE("Test array addressing", "[array-addressing]")
{
    REQUIRE(true);
}

TEST_CASE("Test array swap", "[array-swap]")
{
    REQUIRE(true);
}

TEST_CASE("Test string swap", "[string-swap]")
{
    REQUIRE(true);
}

TEST_CASE("Test array copy", "[array-copy]")
{
    REQUIRE(true);
}

TEST_CASE("Test array linear search", "[array-search]")
{
    REQUIRE(true);
}

TEST_CASE("Test 2d array (mat) linear search", "[2d-array-search]")
{
    REQUIRE(true);
}

TEST_CASE("Test binary search", "[bi-search]")
{
    REQUIRE(true);
}