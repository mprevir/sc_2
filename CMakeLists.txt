project(sc_2)
cmake_minimum_required(VERSION 2.8)
#aux_source_directory(. SRC_LIST)
file(GLOB SRC_LIST "n_exceptions.h" "network.*" "neuron.*" "weightmatrix.*")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_library(AssociativeANN ${SRC_LIST})
