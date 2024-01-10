cmake_minimum_required(VERSION 3.27)
project(hwlist)

set(CMAKE_CXX_STANDARD 17)

add_executable(hwlist main.cpp
        forward.h
        list.h
        double.h)
