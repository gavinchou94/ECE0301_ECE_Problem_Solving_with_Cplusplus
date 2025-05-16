// This is test_vector_7.cpp
// Changes from test_vector_6.cpp
// 1. create vector of double, char type
// 2. vector of struct and access fields

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector-empty]")
{
    //declare vector of type <int>, <double>
    std::vector<int> vec1;

    //without any modifier after vec1, it is initialized as empty
    REQUIRE(vec1.empty()); //empty() function returns false/true
    REQUIRE(vec1.size()==0); //vector has size() function that returns an int
}

TEST_CASE("Vector init with size", "[vector-size]")
{
    std::vector<int> vec1(3); //vector is initialized with ()
    REQUIRE(vec1.size()==3);
    REQUIRE_FALSE(vec1.empty());

    // In an initialized but not assigned array, data content is undefined
    // but an initialized but not assigned vector object has default content 0
    for (int i = 0; i < vec1.size(); i++)
    {
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

TEST_CASE("Vector updating size via push and pop", "[vector-update]")
{
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

TEST_CASE("Vector insert and erase", "[vector]")
{
    // vector is initialized either using size modifier or explicitly {x, x, ...}
    std::vector<int> vec1 = {1, 4, 9, 16};

    // update vector content at certain index
    // e.g., desired vec1 is {1,3,4,9,16}

    // vec1.insert(1, 3); // This would run into error since arg1 in function insert(arg1, arg2)
    // should essentially be an address ptr
    // std::vector<int>::iterator start_addr = vec1.begin();

    // vec1.begin() is the ptr to first element, +n would move ptr n positions
    vec1.insert(vec1.begin() + 1, 3); // this would insert at index 1 an int 3
    REQUIRE(vec1[0]==1);
    REQUIRE(vec1[1]==3);
    REQUIRE(vec1[2]==4);
    REQUIRE(vec1[3]==9);
    REQUIRE(vec1[4]==16);
    REQUIRE(vec1.size()==5);

    // vec1.erase(arg1) would erase the content at arg1 position, arg1 is also an addr ptr

    // e.g., desired vec1 is now {1,3,9,16}
    vec1.erase(vec1.begin() + 2);
    REQUIRE(vec1.size()==4);
    REQUIRE(vec1[0]==1);
    REQUIRE(vec1[1]==3);
    REQUIRE(vec1[2]==9);
    REQUIRE(vec1[3]==16);
}

TEST_CASE("Vector indexing via []", "[vector]")
{
    std::vector<int> vec1 = {1, 4, 9, 16}; // vector initializing with size=4
    int val = vec1[4];
    std::cout << val << std::endl; // vector bad access via [] won't get into error, but val undefined

    //vec1[9] = 25; // vector update via [] has similar behavior, but the update has no effect

    //indexing through [], higher speed, less security
}

TEST_CASE("Vector indexing via at", "[vector]")
{
    std::vector<int> vec2 = {1, 4, 9, 16}; // vector initializing with size=4

    //int val = vec2.at(4); // vector bad access via .at() won't get into error, but throws an exception
    //std::cout << val << std::endl; // val is not assigned value yet due to exception

    //vec2.at(5) = 36; // vector update via .at() also throws an exception

    //THROWS_AS is another type of REQUIRE statement
    REQUIRE_THROWS_AS(vec2.at(6), std::out_of_range);
    REQUIRE_THROWS_AS(std::stod("abcd"), std::invalid_argument);

    //indexing through .at() is slower but safer since it avoids bad access by throwing an exception
}

TEST_CASE("Vector of other data type and ADT", "[vector]")
{
    std::vector<double> vec1 = {1.1, 2.728, 5.2}; // vector initializing with double type
    std::vector<char> vec2 = {'e', 'c', 'e'}; // vector initializing with char type
    REQUIRE(std::abs(vec1[1]-2.728)<=1e-9);
    REQUIRE(vec2[1]=='c');

    struct Entry
    {
        char name;
        int val;
    };

    // vector initializing with struct Entry type
    std::vector<Entry> vec3 = {{'e', 14}, {'c', 12}, {'e', 14}}; // a vector of size=3
    REQUIRE(vec3.size()==3);
    REQUIRE(vec3.at(0).name=='e');
    REQUIRE(vec3.at(0).val==14);
    REQUIRE(vec3.at(1).name=='c');
    REQUIRE(vec3.at(1).val==12);
    REQUIRE(vec3.at(2).name=='e');
    REQUIRE(vec3.at(2).val==14);
}
