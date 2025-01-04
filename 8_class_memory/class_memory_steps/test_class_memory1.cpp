// This is new test_class_memory1.cpp
// test two constructors and get_size() function
// but there is no way now to check element stored inside

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray1.hpp"


TEST_CASE("Test two constructors", "[safearray]") {
    
    SafeArray arr;
    REQUIRE(arr.get_size()==0);

    int size = 5;
    SafeArray arr2(size);

    for (int i=0; i<size; i++){
        // REQUIRE(arr2.dataptr[i]==0); // this would run into error since dataptr is a private member
        // REQUIRE(arr2[i]==0);         // this would run into error since arr2 is an object, compiler doesn't know how to deal with []
    }
    REQUIRE(arr2.get_size()==5);
    
}