cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cli_file_io)
# change the source codes from _1, _2 ..., to _14 to test
add_executable(cli-file-io cli_file_io_1.cpp)