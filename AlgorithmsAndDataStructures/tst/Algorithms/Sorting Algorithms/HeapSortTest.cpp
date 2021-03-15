#include "gtest/gtest.h"
#include "RandomNumberGenerator.h"
#include "Algorithms/Sorting Algorithms/HeapSort.h"
#include <vector>
#include <array>
#include <algorithm>

class HeapSortTest : public ::testing::Test {
protected:
	void SetUp() override {
		InitializeGeneratedElementVectorSizes();
		RefreshRandomVectorValues();
	}

	void InitializeGeneratedElementVectorSizes() {
		size_t_generator_.SetRange(10, 100);
		generated_element_vectors_sizes_ = size_t_generator_.GetGeneratedValues(DistributionType::Uniform, number_of_generated_vectors_sizes_);
	}

	void RefreshRandomVectorValues() {
		for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
			GenerateRandomValuesForAllDistributions(generated_element_vectors_sizes_[i], double_generator_, all_distributions_generated_double_[i]);

		for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
			GenerateRandomValuesForAllDistributions(generated_element_vectors_sizes_[i], long_generator_, all_distributions_generated_long_[i]);
	}

	template<class RandomNumGenerator, class result_type>
	void GenerateRandomValuesForAllDistributions(const std::size_t num_of_elements, RandomNumGenerator& number_generator,
		result_type& result_vector) {
		for (const auto distribution_type : all_distribution_types)
			result_vector.emplace_back(number_generator.GetGeneratedValues(distribution_type, num_of_elements));
	}

	template<class VectorType>
	void SortAllDistributionVectors(VectorType& distribution_values, SortingType sorting_type) {
		for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
			for (int j = 0; j < Distributions::number_of_types; ++j)
				heap_sorter_.SortContainer(distribution_values[i][j], sorting_type);
	}

	void TearDown() override {}

	HeapSort heap_sorter_;

	static const std::size_t number_of_generated_vectors_sizes_ = std::size_t(10);

	RandomNumberGenerator<double>	double_generator_;
	RandomNumberGenerator<long>		long_generator_;

	RandomNumberGenerator<std::size_t> size_t_generator_;

	std::array<std::vector<std::vector<double>>, number_of_generated_vectors_sizes_>	all_distributions_generated_double_;
	std::array<std::vector<std::vector<long>>, number_of_generated_vectors_sizes_>	all_distributions_generated_long_;

	const std::array<DistributionType, Distributions::number_of_types> all_distribution_types = Distributions::all_distributions_enums;

	std::vector<std::size_t> generated_element_vectors_sizes_;
};

TEST_F(HeapSortTest, SortDoubleVector_Ascending) {
	SortAllDistributionVectors(all_distributions_generated_double_, SortingType::Ascending);
	for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
		for (int j = 0; j < Distributions::number_of_types; ++j)
			EXPECT_TRUE(std::is_sorted(all_distributions_generated_double_[i][j].begin(), all_distributions_generated_double_[i][j].end()));
	RefreshRandomVectorValues();
}

TEST_F(HeapSortTest, SortLongVector_Ascending) {
	SortAllDistributionVectors(all_distributions_generated_long_, SortingType::Ascending);
	for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
		for (int j = 0; j < Distributions::number_of_types; ++j)
			EXPECT_TRUE(std::is_sorted(all_distributions_generated_long_[i][j].begin(), all_distributions_generated_long_[i][j].end()));
	RefreshRandomVectorValues();
}

TEST_F(HeapSortTest, SortDoubleVector_Descending) {
	SortAllDistributionVectors(all_distributions_generated_double_, SortingType::Descending);
	for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
		for (int j = 0; j < Distributions::number_of_types; ++j)
			EXPECT_TRUE(std::is_sorted(all_distributions_generated_double_[i][j].rbegin(), all_distributions_generated_double_[i][j].rend()));
	RefreshRandomVectorValues();
}

TEST_F(HeapSortTest, SortLongVector_Descending) {
	SortAllDistributionVectors(all_distributions_generated_long_, SortingType::Descending);
	for (auto i = std::size_t(0); i < number_of_generated_vectors_sizes_; ++i)
		for (int j = 0; j < Distributions::number_of_types; ++j)
			EXPECT_TRUE(std::is_sorted(all_distributions_generated_long_[i][j].rbegin(), all_distributions_generated_long_[i][j].rend()));
	RefreshRandomVectorValues();
}
