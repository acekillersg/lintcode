cmake_minimum_required(VERSION 3.7)
project(lintcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SolutionClasses.h Algorithms.h STL_Solution.h AdjList_Graph_Solution.h)
add_executable(lintcode ${SOURCE_FILES})