#include "Benchmark/SearchAlgorithmsBenchmark.h"
#include "Benchmark/SortAlgorithmsBenchmark.h"


int main() {
	const int numOfVectorSizes = 100;
	const int vectorSizeStep = 10;

	SearchAlgorithmsBenchmark<int>().StartBenchmark(numOfVectorSizes, vectorSizeStep);
	SortAlgorithmsBenchmark<int>().StartBenchmark(DistributionType::Uniform, numOfVectorSizes, vectorSizeStep, std::string{});

	return 0;
}
