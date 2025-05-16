// This is test_arrays_5.cpp
// Changes from test_arrays_4.cpp:
// 1. test copy function of an array to another, elements are identical
// 2. test that a new copy is stored in a different address

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "arrays_5.hpp"

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
    // int dim=5; int arr[dim]={0,10,20,30,40}; //variable-sized object may not be initialized
    const int size = 5; // size has to be a const int
    int arr[size] = {0, 10, 20, 30, 40};

    display(arr, size);

    //std::cout << arr[5] << std::endl; // print out-of-bounds array element
}

TEST_CASE("Test array addressing", "[array-addressing]")
{
    const int size = 5;
    int arr[size] = {0, 10, 20, 30, 40};

    // let's take a look at how arr is stored in memory
    std::cout << arr << std::endl;        // print a hexadecimal addr for first element, supposing X
    std::cout << arr[0] << std::endl;     // print the first element, which is 0
    std::cout << &arr[0] << std::endl;    // print the addr of the first element, '&' is the addr symbol, shall be X
    std::cout << arr[1] << std::endl;     // print the second element, which is 10
    std::cout << &arr[1] << std::endl;    // print the addr of the second element, shall be X+4 (since size(int)=4)

    double arr_d[2] = {10.0, 20.0};
    std::cout << &arr_d[0] << " " << &arr_d[1] << std::endl; // print two address

    // std::cout << arr[8] <<std::endl;   // arr[8] won't give error, but arr[8] accesses data that is illegal
}

TEST_CASE("Test array swap", "[array-swap]")
{
    const int size = 5;
    int arr[size] = {0, 10, 20, 30, 40};

    int index_1 = 2;
    int index_2 = 3;
    int old_value1 = arr[index_1];
    int old_value2 = arr[index_2];

    // a swap function that should exchange two elements in an array
    swap(arr, index_1, index_2);

    // array object, even not pass by reference (with & symbol), is still updated outside function scope
    // since array is stored as an address in memory
    REQUIRE(arr[index_1]==old_value2);
    REQUIRE(arr[index_2]==old_value1);
}

TEST_CASE("Test string swap", "[string-swap]")
{
    std::string my_string = "from";

    int index_1 = 1;
    int index_2 = 2;

    // a string swap function that should exchange two chars in a string
    // note that function overloading is applied here, two functions are named the same
    swap(my_string, index_1, index_2);

    REQUIRE(my_string=="form");
}

TEST_CASE("Test array copy", "[array-copy]")
{
    const int size = 5;
    int arr[size] = {0, 10, 20, 30, 40};

    int arrcopy[size]; // valid but uninitialized

    // a copy function that expects to copy arr[] to arrcopy[], with size
    copy(arr, arrcopy, size);

    // we test whether arr[] elements are identical across two of them
    // check values via a for-loop
    for (int i = 0; i < size; i++)
    {
        REQUIRE(arrcopy[i]==arr[i]);
    }

    // remember arr[] object itself is an address, the copy's address shall be different
    REQUIRE_FALSE(arrcopy==arr);
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