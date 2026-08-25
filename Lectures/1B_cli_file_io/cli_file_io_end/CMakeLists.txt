cmake_minimum_required(VERSION 3.14)
project(cli_file_io_end)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES cli_file_io.cpp)
set(HEADERS )

add_executable(test_cli_file_io ${SOURCES})

enable_testing()
add_test(NAME test-cli-file-io COMMAND test_cli_file_io)

add_custom_target(direct_download
    COMMAND ${CMAKE_COMMAND} -E tar "cfv"
        "${CMAKE_CURRENT_BINARY_DIR}/cli_file_io_end.zip"
        --format=zip
        ${SOURCES} CMakeLists.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})