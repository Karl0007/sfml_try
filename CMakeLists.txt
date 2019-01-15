cmake_minimum_required(VERSION 3.11)

project(demo)

set(CMAKE_CXX_FLAGS "-std=c++11 -lsfml-graphics -lsfml-window -lsfml-system")

aux_source_directory(. DIR_SRCS)
add_executable(demo ${DIR_SRCS})