// AlgorithmsAndDataStructures.cpp : Defines the entry point for the application.
//

#include "AlgorithmsAndDataStructures.h"

#include <memory>
#include <array>
#include <vector>
#include <future>

int main()
{
	RandomNumberGenerator<int> generator;
	generator.SetRange(-10, 10);

	Timer t1;
	//auto sorter = std::make_unique<SelectionSort<int>>();
	
	QuickSort selection_sorter;
	QuickSort selection_sorter2;
	
	//auto rand_values = generator.GetGeneratedValues(DistributionType::Uniform, 1000);
	auto rand_values = std::make_unique<std::vector<int>>(generator.GetGeneratedValues(DistributionType::Uniform, 10));
	auto rand_values2 = std::make_unique<std::vector<int>>(*rand_values);

	std::vector<int> test_arr{8, 7, 1, 1, 9, 1, 1};

	t1.Start();
	selection_sorter.SortContainer(*rand_values);
	t1.Stop();
	selection_sorter.GetAlgorithmInfo().PrintAlgoInfo();

	t1.PrintTimeInMiliSeconds();


	
	for (const auto value : *rand_values) {
		std::cout << value << " ";
	}
	


	return 0;
}
