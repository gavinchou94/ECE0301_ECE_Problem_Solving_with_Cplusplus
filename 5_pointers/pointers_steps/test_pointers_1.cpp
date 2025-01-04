// This is test_pointers_1.cpp
// Changes from test_pointers_starter.cpp:
// declare two arrays using pointer and using dynamically allocated memory

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Test array initialization in dynamic memory", "[ptr-dynamic]")
{
    // The following two lines would run into error since static_size 
    // is a variable that cannot be passed as a static array size declarator
    // int static_size = 4;
    // int arr[static_size] = {0, 1, 2, 3};

    // The dynamically allocated arr[] is possible with a var size declarator
    // Note the syntax and array initialization
    int size = 4;
    int * arr = new int[size]{0, 1, 2, 3};
    // add a breakpoint in above line to view arr as a pointer (hex address)
    // and *arr shows its first element content

    int * arr2; // create another pointer
    arr2 = new int[size]; // This pointer links to a different dynamically allocated array
    // add a breakpoint in above line to view arr2 (different hex address)

    for (int i=0; i<size; i++){
        arr2[i]=i;
    } // assign arr2 content
}

TEST_CASE("Test array copy in dynamic memory", "[ptr-copy]")
{
}

TEST_CASE("Test bad array copy in dynamic memory", "[ptr-copy-bad]")
{
}

TEST_CASE("Test array copy function in dynamic memory", "[ptr-fnc]")
{
}

TEST_CASE("Test array append function in dynamic memory", "[ptr-apd]")
{
}