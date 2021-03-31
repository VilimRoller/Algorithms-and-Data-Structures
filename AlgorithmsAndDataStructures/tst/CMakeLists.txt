#tst
set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}   "Data Structures/StackTest.cpp" "Data Structures/QueueTest.cpp" "Data Structures/DoublyLinkedListTest.cpp" "Data Structures/BinarySearchTreeTest.cpp" "Data Structures/MatrixTest.cpp" "Data Structures/VectorTest.cpp")

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
