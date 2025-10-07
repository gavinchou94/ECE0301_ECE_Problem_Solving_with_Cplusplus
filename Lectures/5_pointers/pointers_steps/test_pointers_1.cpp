// This is test_pointers_1.cpp
// Changes from test_pointers_starter.cpp:
// 1. Add test cases on pointer basics and static/dynamic pointer/array
// 2. declare two arrays using pointer and using dynamically allocated memory

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Test array initialization in dynamic memory", "[ptr-dynamic]")
{
    // first show pointer basics
    int a = 5;                            // normal int variable
    int *static_ptr = &a;                 // pointer variable pointing to a
    std::cout << static_ptr << std::endl; // this will be a hex address

    // use dereference to get the value of a
    std::cout << *static_ptr << std::endl;

    int *another_ptr = &a;                  // another pointer variable pointing to a
    (*static_ptr)++;                        // a++
    std::cout << *static_ptr << std::endl;  // should be 6
    std::cout << *another_ptr << std::endl; // should also be 6
    std::cout << a << std::endl;            // should also be 6

    // now show dynamic pointer
    int *b_ptr = new int(7);          // dynamically allocate an int variable, init to 7
    std::cout << b_ptr << std::endl;  // this will be a hex address
    std::cout << *b_ptr << std::endl; // this will be 7
    int *c_ptr = new int;             // another dynamic pointer without init
    *c_ptr = 8;                       // assign value to the memory location

    // The following two lines would run into error since static_size
    // is a variable that cannot be passed as a static array size declarator
    // int static_size = 5;
    // int arr[static_size] = {0, 1, 2, 3, 4};

    // The dynamically allocated arr[] is possible with a var size declarator
    // Note the syntax and array initialization
    int size = 5;
    int *arr = new int[size]{0, 1, 2, 3, 4};
    // add a breakpoint in above line to view arr as a pointer (hex address)
    // and *arr shows its first element content

    int *arr2;            // create another pointer
    arr2 = new int[size]; // This pointer links to a different dynamically allocated array
                          // without initialization
                          // add a breakpoint in above line to view arr2 as a pointer (hex address)

    for (int i = 0; i < size; i++)
    {
        arr2[i] = i;
        REQUIRE(arr2[i] == i);
    } // assign arr2 content

    // for sure you can declare pointer to other types
    double *db_ptr = new double(3.14);
    double *db_arr_ptr = new double[3]{3.14, 3.15, 3.16};
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