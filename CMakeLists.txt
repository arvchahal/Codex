cmake_minimum_required(VERSION 3.28)
project(codex)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(data_structures)
#add_subdirectory(algorithms)
#add_subdirectory(design_patterns)

add_executable(codex main.cpp
         )#Algorithms DesignPatterns)
