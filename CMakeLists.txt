cmake_minimum_required(VERSION 3.20)

project(pvt_pile)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PVT_PILE_CORE_SOURCES
    #AstPrinter.cpp
    Error.cpp
    Expr.cpp
    ExprVisitor.cpp
    Scanner.cpp
    Token.cpp)

add_library(pvt_pile_core ${PVT_PILE_CORE_SOURCES})

set(PVT_PILE_MAIN_SOURCES
    pvt_pile.cpp)

add_executable(pvt_pile
    ${PVT_PILE_MAIN_SOURCES})

target_link_libraries(pvt_pile pvt_pile_core)