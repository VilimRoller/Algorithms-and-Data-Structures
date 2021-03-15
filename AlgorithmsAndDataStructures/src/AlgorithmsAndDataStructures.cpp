#include "AlgorithmsAndDataStructures.h"

constexpr const int num_of_vectors = 1000;
constexpr const int step_size = 100;

void StartBigObjBenchmark(const DistributionType distribution) {
	SortingAlgorithmBenchmark<BigObject<long long>> benchmark;
	benchmark.StartBenchmark(distribution, num_of_vectors, step_size, "_BigObj");
}

void StartIntBenchmark(const DistributionType distribution) {
	SortingAlgorithmBenchmark<int> benchmark;
	benchmark.StartBenchmark(distribution, num_of_vectors, step_size, "_int");
}

void StartBenchmarks(const DistributionType distribution) {
	StartIntBenchmark(distribution);
	StartBigObjBenchmark(distribution);
}

int main() {
	StartBenchmarks(DistributionType::Uniform);
	StartBenchmarks(DistributionType::NO_DISTRIBUTION);
	StartBenchmarks(DistributionType::ChiSquared);
	StartBenchmarks(DistributionType::Exponential);
	StartBenchmarks(DistributionType::Binomial);
}
