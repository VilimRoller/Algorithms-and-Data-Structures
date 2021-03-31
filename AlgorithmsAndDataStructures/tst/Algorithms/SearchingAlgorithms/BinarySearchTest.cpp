#include "gtest/gtest.h"
#include "Algorithms/Search Algorithms/BinarySearch.h"
#include "RandomNumberGenerator.h"
#include "Algorithms/Sorting Algorithms/QuickSort.h"

class BinarySearchTest : public ::testing::Test {
protected:
	void SetUp() override {

	}

	std::vector<int> GetRandomSortedVector(const int num_of_elements) noexcept {
		auto random_vector = random_generator_.GetGeneratedValues(DistributionType::NO_DISTRIBUTION, num_of_elements);
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
		return std::make_pair(selected_it, binary_searcher_.FindValue(begin_it, end_it, *selected_it));
	}

	void TearDown() override {}

	RandomNumberGenerator<int> random_generator_;
	QuickSort quick_sorter_;
	BinarySearch binary_searcher_;
};

TEST_F(BinarySearchTest, SortedVectorSearch) {
	auto random_vector = GetRandomSortedVector(100);
	auto random_vector_iterator_pairs = GetIteratorPairs(random_vector.begin(), random_vector.end());

	for (const auto& iterator_pair : random_vector_iterator_pairs)
		EXPECT_EQ(*iterator_pair.first, *iterator_pair.second);
}

TEST_F(BinarySearchTest, BigVectorSearch) {
	auto random_vector = GetRandomSortedVector(1000);

	auto first_element_it = random_vector.begin();
	auto last_element_it = random_vector.end() - 1;
	auto middle_element_it = first_element_it + (last_element_it - first_element_it) / 2;

	EXPECT_EQ(*first_element_it, *(binary_searcher_.FindValue(random_vector.begin(), random_vector.end(), *first_element_it)));
	EXPECT_EQ(*last_element_it, *(binary_searcher_.FindValue(random_vector.begin(), random_vector.end(), *last_element_it)));
	EXPECT_EQ(*middle_element_it, *(binary_searcher_.FindValue(random_vector.begin(), random_vector.end(), *middle_element_it)));
}

TEST_F(BinarySearchTest, NoElementFound) {
	auto odd_numofvalues_vec = { 1, 3, 4, 5, 6 };
	auto even_numofvalues_vec = { 1, 2, 4, 5, 6, 7 };

	EXPECT_EQ(odd_numofvalues_vec.end(), binary_searcher_.FindValue(odd_numofvalues_vec.begin(), odd_numofvalues_vec.end(), 2));
	EXPECT_EQ(even_numofvalues_vec.end(), binary_searcher_.FindValue(even_numofvalues_vec.begin(), even_numofvalues_vec.end(), 3));
}

TEST_F(BinarySearchTest, ContainerWithSameElements) {
	auto odd_numofvalues_vec = { 0, 0, 0, 0, 0 };
	auto even_numofvalues_vec = { 0, 0, 0, 0, 0, 0 };

	EXPECT_EQ(0, *binary_searcher_.FindValue(odd_numofvalues_vec.begin(), odd_numofvalues_vec.end(), 0));
	EXPECT_EQ(0, *binary_searcher_.FindValue(even_numofvalues_vec.begin(), even_numofvalues_vec.end(), 0));
}

TEST_F(BinarySearchTest, OneElementNotFound) {
	auto one_element_vector = {1};

	EXPECT_EQ(one_element_vector.end(), binary_searcher_.FindValue(one_element_vector.begin(), one_element_vector.end(), 0));
}

TEST_F(BinarySearchTest, OneElementFound) {
	auto one_element_vector = { 0 };

	EXPECT_EQ(0, *binary_searcher_.FindValue(one_element_vector.begin(), one_element_vector.end(), 0));
}

TEST_F(BinarySearchTest, EmptyContainer) {
	std::vector<int> empty_vector;

	EXPECT_EQ(empty_vector.end(), binary_searcher_.FindValue(empty_vector.begin(), empty_vector.end(), 0));
}

