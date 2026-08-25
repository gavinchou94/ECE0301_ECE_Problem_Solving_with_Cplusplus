cmake_minimum_required(VERSION 3.14)
project(cli_file_io_steps)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STEPS
    cli_file_io_1.cpp
    # cli_file_io_2.cpp
    # cli_file_io_3.cpp
    # cli_file_io_4.cpp
    # cli_file_io_5.cpp
    # cli_file_io_5b.cpp
    # cli_file_io_6.cpp
    # cli_file_io_7.cpp
    # cli_file_io_8.cpp
    # cli_file_io_9.cpp
    # cli_file_io_10.cpp
    # cli_file_io_11.cpp
    # cli_file_io_12.cpp
    # cli_file_io_13.cpp
    # cli_file_io_14.cpp
)

add_executable(test_cli_file_io ${STEPS})

enable_testing()