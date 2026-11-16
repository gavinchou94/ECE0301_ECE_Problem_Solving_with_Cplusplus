cmake_minimum_required(VERSION 3.14)
project(problem10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES test_network.cpp)
set(SOURCES VoltageSource.cpp CurrentSource.cpp Resistor.cpp VoltageDivider.cpp CurrentDivider.cpp PracticalVsCircuit.cpp)
set(HEADERS VoltageSource.hpp CurrentSource.hpp Resistor.hpp VoltageDivider.hpp CurrentDivider.hpp PracticalVsCircuit.hpp)
set(PROVIDED Node.cpp Component.cpp Network.cpp Node.hpp Component.hpp Network.hpp)

add_executable(problem10_tests ${TEST_SOURCES} ${SOURCES} ${HEADERS} ${PROVIDED} catch.hpp)

enable_testing()
add_test(NAME test-problem10 COMMAND problem10_tests)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../problem10.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS} ${PROVIDED} catch.hpp CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(submission
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/problem10_submission.zip"
        --format=zip
        ${TEST_SOURCES} ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})