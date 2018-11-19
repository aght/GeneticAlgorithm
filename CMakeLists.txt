cmake_minimum_required(VERSION 3.12)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Random.cpp Random.hpp Tour.cpp Tour.hpp Population.cpp Population.hpp GeneticAlgorithm.cpp GeneticAlgorithm.hpp)