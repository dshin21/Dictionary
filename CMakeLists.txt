cmake_minimum_required(VERSION 3.12)
project(Dictionary)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dictionary main.cpp dictionary.cpp dictionary.hpp)