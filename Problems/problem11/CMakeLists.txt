cmake_minimum_required(VERSION 3.10)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(problem11)
set(PROVIDED Agent.hpp bitmap.hpp gif.h)
set(AGENTS Acorn.hpp Acorn.cpp 
    Squirrel.hpp Squirrel.cpp 
    Fox.hpp Fox.cpp
)
set(SIMULATOR Grid.hpp Grid.tpp 
    Simulator.hpp Simulator.cpp
)

add_executable(test_sim test_sim.cpp catch.hpp 
                ${PROVIDED} 
                ${AGENTS} 
                ${SIMULATOR}
                )
enable_testing()

add_test(test_sim test_sim)

add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/problem11_submission.zip" --format=zip
       test_sim.cpp ${AGENTS} ${SIMULATOR}
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})