#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray.hpp"


TEST_CASE("Test default construction", "[safearray]") {
    SafeArray arr;

    REQUIRE(arr.get_size()==0);
    
}

TEST_CASE("Test construction with data", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    for (int i=0; i<size; i++){
        REQUIRE(arr[i]==0);
    }

    REQUIRE(arr.get_size()==5);

    REQUIRE_THROWS_AS(arr[-1], std::out_of_range);
    
}

TEST_CASE("Test index[] operator", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    //SafeArray arrcopy;
    //arrcopy=arr;

    //arr[0]=10;
    //arr[1]=40;

    REQUIRE(arr[0]==1);
    REQUIRE(arr[1]==4);
    
}

TEST_CASE("Test copy constructor", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2(arr);
    SafeArray arr3=arr;

    int test[]={1,4,0,0,0};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
        REQUIRE(arr3[i]==test[i]);
    }
}

TEST_CASE("Test copy constructor/assignment and deep copy", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2(arr);
    SafeArray arr3=arr;

    arr[0]=10;
    arr[1]=40;

    int test[]={1,4,0,0,0};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
        REQUIRE(arr3[i]==test[i]);
    }
}

TEST_CASE("Test object and non-member operator", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    arr[0]=1;
    arr[1]=4;

    SafeArray arr2 = arr+100;

    int test[]={101,104,100,100,100};
    for (int i=0; i<size; i++){
        REQUIRE(arr2[i]==test[i]);
    }
}

