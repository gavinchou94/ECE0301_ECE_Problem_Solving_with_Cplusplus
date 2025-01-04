// This is test_vector_4.cpp
// Changes from test_vector_3.cpp
// 1. Updating vector content via erase(arg1) and insert(arg1, arg2)
// 2. Showing begin() is an iterator

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector-empty]") {
    //declare vector of type <int>, <double>
    std::vector<int> vec1;
    
    //without any modifier after vec1, it is initialized as empty
    REQUIRE(vec1.empty());  //empty() function returns false/true
    REQUIRE(vec1.size()==0); //vector has size() function that returns an int
}

TEST_CASE("Vector init with size", "[vector-size]"){
    std::vector<int> vec1(3); //vector is initialized with ()
    REQUIRE(vec1.size()==3);
    REQUIRE_FALSE(vec1.empty());

    // In an initialized but not assigned array, data content is undefined
    // but an initialized but not assigned vector object has default content 0
    for(int i=0;i<vec1.size();i++){
        REQUIRE(vec1[i]==0);
    }

    // same as array, [] is used in vector to access/update indexed content
    vec1[0] = 1;
    vec1[1] = 4;
    vec1[2] = 9;

    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[1] == 4);
    REQUIRE(vec1[2] == 9);

}

TEST_CASE("Vector updating size via push and pop", "[vector-update]"){
    std::vector<int> vec1;
    //vec1[0]=4; // this would run into bad-access error since vec1 is still empty
    REQUIRE(vec1.empty());
    
    // Unlike array, vector object can be easily modified in terms of size
    // no need to start a new vector object
    vec1.push_back(1); // push_back(?) appends one element at the end of vector object
    REQUIRE(vec1.size()==1);
    REQUIRE(vec1[0]==1);

    vec1.push_back(4); // push_back(?) can continue modifying vector object
    REQUIRE(vec1.size()==2);
    REQUIRE(vec1[0]==1);
    REQUIRE(vec1[1]==4);

    vec1.pop_back(); // pop_back() removes one element at the end of vector object, no arg required
    REQUIRE(vec1.size()==1);
    vec1.pop_back();
    REQUIRE(vec1.empty());
    //vec1.pop_back(); // This would run into error when trying to pop_back an empty vector
}

TEST_CASE("Vector insert and erase", "[vector]"){
    // vector is initialized either using size modifier or explicitly {x, x, ...}
    std::vector<int> vec1={1,4,9,16};

    // update vector content at certain index
    // e.g., desired vec1 is {1,3,4,9,16}

    // vec1.insert(1, 3); // This would run into error since arg1 in function insert(arg1, arg2)
    // should essentially be an address ptr
    std::vector<int>::iterator start_addr = vec1.begin();

    // vec1.begin() is the ptr to first element, +n would move ptr n positions
    vec1.insert(vec1.begin()+1, 3); // this would insert at index 1 an int 3
    REQUIRE(vec1[0]==1);
    REQUIRE(vec1[1]==3);
    REQUIRE(vec1[2]==4);
    REQUIRE(vec1[3]==9);
    REQUIRE(vec1[4]==16);
    REQUIRE(vec1.size()==5);

    // vec1.erase(arg1) would erase the content at arg1 position, arg1 is also an addr ptr

    // e.g., desired vec1 is now {1,3,9,16}
    vec1.erase(vec1.begin()+2);
    REQUIRE(vec1.size()==4);
    REQUIRE(vec1[0]==1);
    REQUIRE(vec1[1]==3);
    REQUIRE(vec1[2]==9);
    REQUIRE(vec1[3]==16);
}