cmake_minimum_required(VERSION 3.20)

project(pvt_pile)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PVT_PILE_MAIN_SOURCES
    pvt_pile.cpp)

add_executable(pvt_pile
    ${PVT_PILE_MAIN_SOURCES})