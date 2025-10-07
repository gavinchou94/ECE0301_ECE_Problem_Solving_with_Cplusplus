// This is test_pointers_3.cpp
// Changes from test_pointers_2.cpp:
// 1. show how to copy an array using element-wise copy
// 2. show their ptrs are different and memory usage are independent from each other

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

    // These two arrays share the same content, but arr and arr2, as pointers (hex addresses)
    // are different from each other
    for (int i = 0; i < size; i++)
    {
        REQUIRE(arr[i] == arr2[i]);
    }
    REQUIRE_FALSE(arr == arr2);

    // Deallocate memory after final usage
    delete[] arr; // arr is no longer used after this line, it is also good to add arr=nullptr;

    REQUIRE(arr2[2] == 2);
    delete[] arr2; // arr2 is no longer used after this line

    delete b_ptr;
    delete c_ptr;
    delete db_ptr;
    delete[] db_arr_ptr; // every "new" should have a corresponding "delete"

    // if you want to be safe, set the pointer to nullptr AFTER delete
    // so that it won't be a dangling pointer

    // or there is more code after deletion, you can set it to nullptr right away
    // to avoid accidental usage of dangling pointer
}

TEST_CASE("Test array copy in dynamic memory", "[ptr-copy]")
{
    // These 3 lines are same as above: create ptr arr and assign value,
    // and declare another ptr of same size
    int size = 5;
    int *arr = new int[size]{0, 1, 2, 3, 4};
    int *arrcopy = new int[size];

    // Apply element-wise copy to update content of arrcopy[]
    for (int i = 0; i < size; i++)
    {
        arrcopy[i] = arr[i];
    }

    // These two arrays share the same content, but arr and arrcopy, as pointers (hex addresses)
    // are different from each other
    for (int i = 0; i < size; i++)
    {
        REQUIRE(arrcopy[i] == arr[i]);
    }
    REQUIRE_FALSE(arrcopy == arr);

    // Deallocate memory after final usage, same as above
    delete[] arr;

    // The copy is content-wise copy, not pointer shallow copy
    // Therefore, memory usage is independent, arrcopy[2] is still available after deleting arr[]
    std::cout << arrcopy[2] << std::endl;
    delete[] arrcopy;
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