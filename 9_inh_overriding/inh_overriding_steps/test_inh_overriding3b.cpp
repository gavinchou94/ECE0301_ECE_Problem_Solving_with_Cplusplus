// This is test_inh_overriding3b.cpp
// Changes from test_inh_overriding3.cpp
// 1. define two functions here to demonstrate binding later
// 2. one takes base class object as argument, the other takes ptr to base class object
// 3. simple test of these non-member functions

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SafeArray3.hpp"
#include "SearchableArray3.hpp"
#include "UniqueArray3.hpp"

TEST_CASE("Test SafeArray size construction and access using get/set", "[safearray]") {
    int size = 5;
    SafeArray arr(size);

    REQUIRE(arr.get_size() == size);
    for (int i=0; i<size; i++) {
        arr.set(i, i);
        REQUIRE(arr.get(i) == i);
    }

    REQUIRE_THROWS_AS(arr.get(size), std::out_of_range);
    REQUIRE_THROWS_AS(arr.set(size,0), std::out_of_range);
}

TEST_CASE("Test inheritance and search", "[inh]") {
    int size = 5;
    SearchableArray arr(size);

    REQUIRE(arr.get_size()==5);

    for (int i=0; i<size; i++){
        arr.set(i,i);                  // inherited from base class 
        REQUIRE(arr.get(i)==i);        // inherited from base class
        REQUIRE(arr.search(i));        // derived class method
    }

    REQUIRE_FALSE(arr.search(-2));     // derived class method
    REQUIRE_THROWS_AS(arr.set(10, 10), std::out_of_range); // inherited from base class
}

TEST_CASE("Test inheritance access permission", "[inh]") {
    int size = 5;
    SearchableArray arr(size);
    REQUIRE(arr.search(0));     // derived class method built on "protected" var
}

TEST_CASE("Test inheritance and redefine/override", "[inh]") {
    int size = 5;
    UniqueArray uarr(size);

    REQUIRE(uarr.get_size()==5);

    for (int i=0; i<size; i++){
        // set uarr to be [1,2,3,4,5]
        uarr.set(i,i+1);                // overridden set functions
        REQUIRE(uarr.get(i)==i+1);      // test success of overriding
    }

    //arr[0]=5 would trigger exception since arr[4]=5
    REQUIRE_THROWS_AS(uarr.set(0, 5), std::logic_error);
    REQUIRE_NOTHROW(uarr.set(0, -2));   //arr[0]=-2 is okay
    REQUIRE(uarr.get(0)==-2);

    // these following 3 lines demonstrates dynamic binding
    // delete "virtual" at Line 27 of SafeArray3.hpp and try it again
    SafeArray *sa_ptr = new UniqueArray(2);
    sa_ptr->set(0, 100);
    REQUIRE_THROWS_AS(sa_ptr->set(1, 100), std::logic_error);
}

// define a function that takes a SafeArray object (as a reference)
// and apply half to the arr object memberwise 
void halve(SafeArray & arr){
    int val;
    for (int i=0; i<arr.get_size(); i++){
        val = 0.5*arr.get(i);
        arr.set(i,val);
    }
}

// define a function that takes a SafeArray ptr
// and apply half to the arr object memberwise 
void halve(SafeArray* sarr){
    int val;
    for (int i=0; i<sarr->get_size(); i++){   //note that (*x).y is just x->y
        val = 0.5*sarr->get(i);
        sarr->set(i,val);
    }
}

TEST_CASE("Test non-member functions", "[inh]") {
    int size =5;
    SafeArray arr(size);
    SafeArray* arr_ptr = new SafeArray(5);

    for (int i=0; i<size; i++){
        // set arr/arr_ptr to be [1,2,3,4,5]
        arr.set(i,i+1);
        arr_ptr->set(i,i+1);
    }

    halve(arr);
    halve(arr_ptr);

    for (int i=0; i<size; i++){
        // test arr/arrptr now to be [int(0.5*1),int(0.5*2),int(0.5*3),int(0.5*4),int(0.5*5)]
        REQUIRE(arr.get(i)==int(0.5*(i+1)));
        REQUIRE(arr_ptr->get(i)==int(0.5*(i+1)));
    }
}