cmake_minimum_required(VERSION 3.20)
project(lab_generation)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_generation main.cpp solve_lab.cpp solve_lab.h)
