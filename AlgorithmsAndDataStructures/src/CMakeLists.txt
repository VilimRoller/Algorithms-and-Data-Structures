#src
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES}    "Algorithms/Sorting Algorithms/ShellSort.h" "Algorithms/SortingAlgorithmBenchmark.h" "Algorithms/BigObject.h" "Algorithms/Searching Algorithms/SearchAlgorithm.h" "Algorithms/Searching Algorithms/LinearSearch.h" "Algorithms/Searching Algorithms/BinarySearch.h" "Algorithms/Searching Algorithms/JumpSearch.h" "Algorithms/Searching Algorithms/InterpolationSearch.h")

add_library(${BINARY}_lib STATIC ${SOURCES}    "Algorithms/Sorting Algorithms/ShellSort.h" "Algorithms/SortingAlgorithmBenchmark.h" "Algorithms/BigObject.h"  "Algorithms/Sorting Algorithms/SortingAlgorithm.h" "Algorithms/Searching Algorithms/SearchAlgorithm.h" "Algorithms/Searching Algorithms/LinearSearch.h" "Algorithms/Searching Algorithms/BinarySearch.h" "Algorithms/Searching Algorithms/JumpSearch.h" "Algorithms/Searching Algorithms/InterpolationSearch.h")


