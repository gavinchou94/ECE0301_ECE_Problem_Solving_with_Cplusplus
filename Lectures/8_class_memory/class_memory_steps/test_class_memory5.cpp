// This is test_class_memory5.cpp
// Changes from test_class_memory4.cpp:
// test object and non-member operator, two directions

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray5.hpp"


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

TEST_CASE("Test copy constructor/assignment", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2(arr);     // arr2 is declared using copy constructor
    SafeArray arr3=arr;      // arr3 is declared using copy constructor
    SafeArray arr4(7);
    arr4 = arr3;             // arr4 is assigned value using copy assignment

    // close this testing case w/t and w/o customed copy assignment, see diff in VS Code

    int test[]={1,4,0,0,0};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
        REQUIRE(arr3[i]==test[i]);           // test arr3 of copy constructor
        REQUIRE(arr4[i]==test[i]);           // test arr4 of copy assignment
    }
    REQUIRE(arr4.get_size()==5);             // test arr4 of copy assignment
}

TEST_CASE("Test object and non-member operator", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2 = arr+100;
    SafeArray arr3 = 100+arr;

    int test[]={101,104,100,100,100};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
        REQUIRE(arr3[i]==test[i]);
    }
}