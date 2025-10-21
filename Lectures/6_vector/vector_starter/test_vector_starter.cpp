#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector> // this header file has to be included

TEST_CASE("Vector init", "[vector-empty]")
{
    // declare vector of type <int>, <double>
    std::vector<int> vec1;

    // without any modifier after vec1, it is initialized as empty
    REQUIRE(vec1.empty());
    REQUIRE(vec1.size() == 0);
}

TEST_CASE("Vector init with size", "[vector-size]")
{
    std::vector<int> vec1(3);
    REQUIRE(vec1.size() == 3);
    REQUIRE_FALSE(vec1.empty());

    for (int i = 0; i < vec1.size(); i++)
    {
        REQUIRE(vec1[i] == 0);
    }

    vec1[0] == 1;
    vec1[1] == 4;
    vec1[2] == 9;

    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[1] == 4);
    REQUIRE(vec1[2] == 9);
}

TEST_CASE("Vector updating size via push and pop", "[vector-update]")
{
    std::vector<int> vec1;
    REQUIRE(vec1.empty());

    vec1.push_back(1);
    REQUIRE(vec1.size() == 1);
    REQUIRE(vec1[0] == 1);

    vec1.push_back(4);
    REQUIRE(vec1.size() == 2);
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[1] == 4);

    vec1.pop_back();
    REQUIRE(vec1.size() == 1);
    vec1.pop_back();
    REQUIRE(vec1.empty());
}

TEST_CASE("Vector insert and erase", "[vector-insert-erase]")
{
    std::vector<int> vec1 = {1, 4, 9, 16};
    std::vector<int>::iterator start_addr = vec1.begin();

    vec1.insert(vec1.begin() + 1, 3);
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[1] == 3);
    REQUIRE(vec1[2] == 4);
    REQUIRE(vec1[3] == 9);
    REQUIRE(vec1[4] == 16);
    REQUIRE(vec1.size() == 5);

    vec1.erase(vec1.begin() + 2);
    REQUIRE(vec1.size() == 4);
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec1[1] == 3);
    REQUIRE(vec1[3] == 9);
    REQUIRE(vec1[4] == 16);
}

TEST_CASE("Vector indexing via []", "[vector-index]")
{
    std::vector<int> vec1 = {1, 4, 9, 16};
    int val = vec1[4];
    std::cout << val << std::endl;
}

TEST_CASE("Vector indexing via at", "[vector-index]")
{
    std::vector<int> vec2 = {1, 4, 9, 16};
    int val = vec2.at(4);
    std::cout << val << std::endl;
    vec2.at(5) = 36;

    REQUIRE_THROWS_AS(vec2.at(6), std::out_of_range);
    REQUIRE_THROWS_AS(std::stod("abcd"), std::invalid_argument);
}

TEST_CASE("Vector of other data type and ADT", "[vector-ADT]")
{
    std::vector<double> vec1 = {1.1, 2.728, 5.2};
    std::vector<char> vec2 = {'e', 'c', 'e'};

    REQUIRE(std::abs(vec1[1] - 2.728) <= 1e-9);
    REQUIRE(vec2[1] == 'c');

    struct Entry
    {
        char name;
        int val;
    };
    std::vector<Entry> vec3 = {{'e', 14}, {'c', 12}, {'e', 12}};
    REQUIRE(vec3.size() == 3);
    REQUIRE(vec3.at(0).name == 'e');
    REQUIRE(vec3.at(0).val == 14);
    REQUIRE(vec3.at(1).name == 'c');
    REQUIRE(vec3.at(1).val == 12);
    REQUIRE(vec3.at(2).name == 'e');
    REQUIRE(vec3.at(2).val == 14);
}