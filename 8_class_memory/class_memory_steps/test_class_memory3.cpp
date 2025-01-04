// This is test_class_memory3.cpp
// Changes from test_class_memory2.cpp:
// test copy instructor

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray3.hpp"


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

TEST_CASE("Test copy constructor", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2(arr);
    //SafeArray arr3=arr;

    int test[]={1,4,0,0,0};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
        //REQUIRE(arr3[i]==test[i]);
    }

    // Uncomment below to try to copy an object
    // see in VS code what error would it pop up
    SafeArray arr3(7);
    arr3 = arr;
    std::cout<<"Hi"<<std::endl;

}