cmake_minimum_required(VERSION 3.14)
project(problem11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROVIDED Agent.hpp bitmap.hpp gif.h)
set(AGENTS Acorn.hpp Acorn.cpp Squirrel.hpp Squirrel.cpp Fox.hpp Fox.cpp)
set(SIMULATOR Grid.hpp Grid.tpp Simulator.hpp Simulator.cpp)

add_executable(problem11-tests test_sim.cpp catch.hpp 
                ${PROVIDED} 
                ${AGENTS} 
                ${SIMULATOR}
                )

enable_testing()
add_test(test-problem11 problem11-tests)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem11_submission.zip" --format=zip
       test_sim.cpp ${AGENTS} ${SIMULATOR}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})