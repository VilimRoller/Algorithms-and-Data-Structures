#include "AlgorithmsAndDataStructures.h"

#include "Algorithms/Search Algorithms/InterpolationSearch.h"
#include "Algorithms/Search Algorithms/BinarySearch.h"
#include "Algorithms/SearchAlgorithmsBenchmark.h"
#include "Algorithms/Sorting Algorithms/QuickSort.h"
#include "Data Structures/Vector.h"

#include <memory>

int main() {
	Vector<int> test_vec;
	std::vector<int> real_vec;
	QuickSort quick_sorter;

	real_vec.emplace_back(2);
	real_vec.emplace_back(1);
	real_vec.emplace_back(3);


	test_vec.emplace_back(2);
	test_vec.emplace_back(1);
	test_vec.emplace_back(3);


	quick_sorter.SortContainer(test_vec.rbegin(), test_vec.rend());

	for (const auto element : test_vec)
		std::cout << element << " ";
}
