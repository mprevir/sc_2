file(GLOB SRC_LIST "*.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_library(AssociativeANN ${SRC_LIST})
