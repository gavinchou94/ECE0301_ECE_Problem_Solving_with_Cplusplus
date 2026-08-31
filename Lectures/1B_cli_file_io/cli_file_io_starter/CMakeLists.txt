cmake_minimum_required(VERSION 3.14)
project(cli_file_io_starter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES cli_file_io_starter.cpp)
set(HEADERS )

add_executable(cli_file_io_starter ${SOURCES})

enable_testing()
add_test(NAME test-cli-file-io-starter COMMAND cli_file_io_starter)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/../cli_file_io_starter.zip"
        --format=zip
        ${SOURCES} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})