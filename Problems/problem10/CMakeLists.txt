cmake_minimum_required(VERSION 3.10)
project(problem10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BASE Node.hpp Node.cpp Component.hpp Component.cpp Network.hpp Network.cpp)
set(COMPONENTS VoltageSource.hpp VoltageSource.cpp CurrentSource.hpp CurrentSource.cpp Resistor.hpp Resistor.cpp)
set(NETWORKS VoltageDivider.hpp VoltageDivider.cpp CurrentDivider.hpp CurrentDivider.cpp)

add_executable(test_network test_network.cpp catch.hpp ${BASE} ${COMPONENTS} ${NETWORKS})
enable_testing()

add_test(test_network test_network)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem10.zip" --format=zip
       test_network.cpp ${COMPONENTS} ${NETWORKS}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})