cmake_minimum_required(VERSION 3.2)
project(G2015010376)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(G2015010376 ${SOURCE_FILES} Shape.cpp Shape.h Point.cpp Point.h Rectangle.cpp Rectangle.h)