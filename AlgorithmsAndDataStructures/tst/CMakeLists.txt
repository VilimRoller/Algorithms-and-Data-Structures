cmake_minimum_required(VERSION 3.5)

project(AlgorithmsAndDataStructuresTests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(AlgorithmsAndDataStructuresLib STATIC
  ../src/Algorithms/AlgorithmInfo.h
  ../src/Algorithms/SearchAlgorithms/BinarySearch.h
  ../src/Algorithms/SearchAlgorithms/InterpolationSearch.h
  ../src/Algorithms/SearchAlgorithms/JumpSearch.h
  ../src/Algorithms/SearchAlgorithms/LinearSearch.h
  ../src/Algorithms/SearchAlgorithms/SearchAlgorithm.h
  ../src/Algorithms/SortAlgorithms/BubbleSort.h
  ../src/Algorithms/SortAlgorithms/HeapSort.h
  ../src/Algorithms/SortAlgorithms/InsertionSort.h
  ../src/Algorithms/SortAlgorithms/MergeSort.h
  ../src/Algorithms/SortAlgorithms/QuickSort.h
  ../src/Algorithms/SortAlgorithms/SelectionSort.h
  ../src/Algorithms/SortAlgorithms/ShellSort.h
  ../src/Algorithms/SortAlgorithms/SortAlgorithm.h
  ../src/DataStructures/Queue.h
  ../src/DataStructures/Stack.h
  ../src/DataStructures/Vector.h
)

set_target_properties(AlgorithmsAndDataStructuresLib PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB_RECURSE TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Benchmark/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DataStructures/*.cpp
)

list(FILTER TEST_FILES EXCLUDE REGEX "main.cpp$")  # Exclude main.cpp from the test files

add_executable(AlgorithmsAndDataStructuresTests ${TEST_FILES} main.cpp)

target_link_libraries(AlgorithmsAndDataStructuresTests
  ${GTEST_LIBRARIES}
  AlgorithmsAndDataStructuresLib
)

set_property(TARGET AlgorithmsAndDataStructuresTests PROPERTY CXX_STANDARD 17)