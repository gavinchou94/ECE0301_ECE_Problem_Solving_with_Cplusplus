// This is test_vector_1.cpp
// Changes from test_vector_starter.cpp
// test the empty() and size() function of vector object

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector]") {
    //declare vector of type <int>, <double>
    std::vector<int> vec1;
    
    //without any modifier after vec1, it is initialized as empty
    REQUIRE(vec1.empty());  //empty() function returns false/true
    REQUIRE(vec1.size()==0); //vector has size() function that returns an int
}