// This is test_pointers_4.cpp
// Changes from test_pointers_3.cpp:
// 1. show a bad copy example by copying ptr to a new array alias
// 2. arr and arr_badcopy share a deceptive equivalence, and could run into double free error

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

    // These two arrays share the same content, but arr and arr2, as pointers (hex addresses)
    // are different from each other
    for (int i=0; i<size; i++){
        REQUIRE(arr[i]==arr2[i]);
    }
    REQUIRE_FALSE(arr==arr2);

    // Deallocate memory after final usage
    delete [] arr; // arr is no longer used after this line, it is also good to add arr=nullptr;

    REQUIRE(arr2[2]==2);
    delete [] arr2; // arr2 is no longer used after this line
}

TEST_CASE("Test array copy in dynamic memory", "[ptr-copy]")
{
    // These 3 lines are same as above: create ptr arr and assign value,
    // and declare another ptr of same size
    int size = 4;
    int * arr = new int[size]{0,1,2,3};
    int * arrcopy = new int [size];

    // Apply element-wise copy to update content of arrcopy[]
    for (int i=0; i<size; i++){
        arrcopy[i]=arr[i];
    }

    // These two arrays share the same content, but arr and arrcopy, as pointers (hex addresses)
    // are different from each other
    for (int i=0; i<size; i++){
        REQUIRE(arrcopy[i]==arr[i]);
    }
    REQUIRE_FALSE(arrcopy==arr);

    // Deallocate memory after final usage, same as above
    delete [] arr;

    // The copy is content-wise copy, not pointer-wise copy
    // Therefore, memory usage is independent, arrcopy[2] is still available after deleting arr[]
    std::cout << arrcopy[2]<<std::endl;
    delete [] arrcopy;
}

TEST_CASE("Test bad array copy in dynamic memory", "[ptr-copy-bad]")
{
    int size = 4;
    int * arr = new int[size]{-1,1,2,3}; //modify a bit to make 1st element non-zero

    // create a new ptr arrcopy that gets the same address as arr ptr
    int * arr_badcopy = arr;
    // add a breakpoint here to view arr_badcopy and arr in variable windows
    // what are the content of *arr and *arr_badcopy (not even copied yet)? 

    // The following REQUIRE statements are satisfied, unfortunately due to deceptive equivalence
    // since arr, arr_badcopy are different alias pointing to same data content (their ptrs, hex addresses are the same)
    for (int i=0; i<size; i++){
        REQUIRE(arr_badcopy[i]==arr[i]);
    }

    // Deallocate memory after final usage, same as above
    delete [] arr;

    // Uncomment the following two lines to see what would happen
    // std::cout << arr_badcopy[2]<<std::endl; // This would return 0 due to content erased
    // delete [] arr_badcopy; // This would yield a double free error due to repeated erasing 
}

TEST_CASE("Test array copy function in dynamic memory", "[ptr-fnc]")
{
}

TEST_CASE("Test array append function in dynamic memory", "[ptr-apd]")
{
}