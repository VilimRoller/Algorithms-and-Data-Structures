#main file
cmake_minimum_required (VERSION 3.15)
project (AlgorithmsAndDataStructures)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(tst)

add_subdirectory (src)
add_subdirectory (tst)
add_subdirectory (lib/googletest)
