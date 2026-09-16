#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

TEST_CASE("An example description", "[tag]")
{
  std::cout << "Hello from Catch2!" << std::endl;
}