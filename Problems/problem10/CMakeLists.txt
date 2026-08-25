cmake_minimum_required(VERSION 3.14)
project(problem10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BASE Node.hpp Node.cpp Component.hpp Component.cpp Network.hpp Network.cpp)
set(COMPONENTS VoltageSource.hpp VoltageSource.cpp CurrentSource.hpp CurrentSource.cpp Resistor.hpp Resistor.cpp)
set(NETWORKS VoltageDivider.hpp VoltageDivider.cpp CurrentDivider.hpp CurrentDivider.cpp PracticalVsCircuit.hpp PracticalVsCircuit.cpp)
add_executable(problem10-tests test_network.cpp catch.hpp ${BASE} ${COMPONENTS} ${NETWORKS})

enable_testing()
add_test(test-problem10 problem10-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem10_submission.zip" --format=zip
       test_network.cpp ${COMPONENTS} ${NETWORKS}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})