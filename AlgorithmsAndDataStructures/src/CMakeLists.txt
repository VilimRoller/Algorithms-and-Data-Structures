#src
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES} "Algorithms/Benchmark.h"  "Data Structures/Vector.h" "Data Structures/Stack.h"   "Data Structures/BinarySearchTree.h" "Data Structures/DoublyLinkedList.h" "Data Structures/Queue.h" "Data Structures/Matrix.h" "Data Structures/Array.h" "Data Structures/HashTable.h" "Data Structures/Map.h" "Data Structures/Graph.h" "Data Structures/Heap.h")

add_library(${BINARY}_lib STATIC ${SOURCES} "Algorithms/Benchmark.h"  "Data Structures/Vector.h" "Data Structures/Stack.h"   "Data Structures/BinarySearchTree.h" "Data Structures/DoublyLinkedList.h" "Data Structures/Queue.h" "Data Structures/Matrix.h" "Data Structures/Array.h" "Data Structures/HashTable.h" "Data Structures/Map.h" "Data Structures/Graph.h" "Data Structures/Heap.h")


