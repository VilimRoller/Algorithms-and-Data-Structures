#include "gtest/gtest.h"
#include "Algorithms/Search Algorithms/InterpolationSearch.h"
#include "RandomNumberGenerator.h"
#include "Algorithms/Sorting Algorithms/QuickSort.h"


class InterpolationSearchTest : public ::testing::Test {
protected:
	void SetUp() override {
		random_generator_.SetRange(-1000, 1000);
	}

	std::vector<int> GetRandomSortedVector(const int num_of_elements) noexcept {
		auto random_vector = random_generator_.GetGeneratedValues(DistributionType::Uniform, num_of_elements);
		quick_sorter_.SortContainer(random_vector.begin(), random_vector.end());
		return std::move(random_vector);
	}

	template<class VectorIterator>
	std::vector<std::pair<VectorIterator, VectorIterator>> GetIteratorPairs(const VectorIterator begin_it,
		const VectorIterator end_it) noexcept {
		std::vector<std::pair<VectorIterator, VectorIterator>> result;

		for (auto selected_it = begin_it; selected_it < end_it; ++selected_it)
			result.emplace_back(GetPairOfOriginalAndFoundIterator(begin_it, end_it, selected_it));

		return std::move(result);
	}

	template<class VectorIterator>
	const std::pair<VectorIterator, VectorIterator> GetPairOfOriginalAndFoundIterator(const VectorIterator begin_it,
		const VectorIterator end_it, const VectorIterator selected_it) noexcept {
		return std::make_pair(selected_it, interpolation_searcher_.FindValue(begin_it, end_it, *selected_it));
	}

	void TearDown() override {}

	RandomNumberGenerator<int> random_generator_;
	QuickSort quick_sorter_;
	InterpolationSearch interpolation_searcher_;
};

TEST_F(InterpolationSearchTest, SortedVectorSearch) {
	auto random_vector = GetRandomSortedVector(100);
	auto random_vector_iterator_pairs = GetIteratorPairs(random_vector.begin(), random_vector.end());
	
	for (const auto& iterator_pair : random_vector_iterator_pairs)
		EXPECT_EQ(*iterator_pair.first, *iterator_pair.second);
}

TEST_F(InterpolationSearchTest, BigVectorSearch) {
	auto random_vector = GetRandomSortedVector(1000);

	auto first_element_it = random_vector.begin();
	auto last_element_it = random_vector.end() - 1;
	auto middle_element_it = first_element_it + (last_element_it - first_element_it) / 2;

	EXPECT_EQ(*first_element_it, *(interpolation_searcher_.FindValue(random_vector.begin(), random_vector.end(), *first_element_it)));
	EXPECT_EQ(*last_element_it, *(interpolation_searcher_.FindValue(random_vector.begin(), random_vector.end(), *last_element_it)));
	EXPECT_EQ(*middle_element_it, *(interpolation_searcher_.FindValue(random_vector.begin(), random_vector.end(), *middle_element_it)));
}


