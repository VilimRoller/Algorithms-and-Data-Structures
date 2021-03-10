#tst
set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES} "main.h" "RandomNumberGeneratorTest.cpp" "Algorithms/Sorting Algorithms/BubbleSortTest.cpp" "Algorithms/Sorting Algorithms/InsertionSortTest.cpp" "Algorithms/Sorting Algorithms/MergeSortTest.cpp" "Algorithms/Sorting Algorithms/QuickSortTest.cpp" "Algorithms/Sorting Algorithms/SelectionSortTest.cpp")

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
