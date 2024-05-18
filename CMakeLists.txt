cmake_minimum_required(VERSION 3.28.3)

project(aomo VERSION 0.0.1)

configure_file("./src/config.h.in" "./include/config.h")

set(SRC_LIST ./src/aomo.cpp ./src/parser/parser.cpp ./src/getopt.cpp ./src/print.cpp
    ./src/clarg.cpp) 

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

add_executable(${PROJECT_NAME} ${SRC_LIST})