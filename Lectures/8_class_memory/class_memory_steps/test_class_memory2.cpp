// This is test_class_memory2.cpp
// Changes from test_class_memory1.cpp:
// 1. test [] for accessing information
// 2. test [] for updating information

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray2.hpp"


TEST_CASE("Test two constructors", "[safearray]") {
    
    SafeArray arr;
    REQUIRE(arr.get_size()==0);

    int size = 5;
    SafeArray arr2(size);

    for (int i=0; i<size; i++){
        // REQUIRE(arr2.dataptr[i]==0); // this would run into error since dataptr is a private member
        REQUIRE(arr2[i]==0);         // now this shall work
    }
    REQUIRE(arr2.get_size()==5);
    
}

TEST_CASE("Test index[] operator update", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1; // test arr[] is good for being put on LHS
    arr[1]=4;

    REQUIRE(arr[0]==1);
    REQUIRE(arr[1]==4);
    REQUIRE(arr[2]==0);
    REQUIRE(arr[3]==0);
    REQUIRE(arr[4]==0);

    REQUIRE_THROWS_AS(arr[-1], std::out_of_range);
    REQUIRE_THROWS_AS(arr[-1]=5, std::out_of_range);

    // Uncomment below to try to create a new object using memberwise assignment
    // see in VS code what error would it pop up
    // SafeArray arr2(arr);
    // SafeArray arr3 = arr;
}