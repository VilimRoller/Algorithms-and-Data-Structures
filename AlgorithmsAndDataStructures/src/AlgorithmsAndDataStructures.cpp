#include "AlgorithmsAndDataStructures.h"

#include "Algorithms/Search Algorithms/InterpolationSearch.h"
#include "Algorithms/Search Algorithms/BinarySearch.h"
#include "Algorithms/SearchAlgorithmsBenchmark.h"
#include "Algorithms/Sorting Algorithms/QuickSort.h"
#include "Data Structures/Vector.h"
#include "Data Structures/Queue.h"

#include <memory>

int main() {
	Vector<int> test_vec;
	Queue<int> test_queue;

	test_queue.push(1);
	test_queue.push(2);
	test_queue.push(3);

	std::cout << test_queue.size() << " " << test_queue.pop() << "\n";
	std::cout << test_queue.size() << " " << test_queue.pop() << "\n";
	std::cout << test_queue.size() << " " << test_queue.pop() << "\n";

}
