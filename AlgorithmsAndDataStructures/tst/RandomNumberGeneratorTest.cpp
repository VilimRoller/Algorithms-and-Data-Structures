#include "gtest/gtest.h"
#include "RandomNumberGenerator.h"
#include <vector>


class RandomNumberGeneratorTest : public ::testing::Test {
protected:
	void SetUp() override {
		GenerateRandomValuesForAllDistributionsAndTypes(num_of_generated_elements_);
	}

	void GenerateRandomValuesForAllDistributionsAndTypes(const std::size_t num_of_elements) {
		GenerateRandomValuesForAllDistributions(num_of_elements, int_generator_,	all_distributions_generated_int_);
		GenerateRandomValuesForAllDistributions(num_of_elements, float_generator_,	all_distributions_generated_float_);
		GenerateRandomValuesForAllDistributions(num_of_elements, double_generator_,	all_distributions_generated_double_);
		GenerateRandomValuesForAllDistributions(num_of_elements, long_generator_,	all_distributions_generated_long_);
	}

	template<class RandomNumGenerator, class result_type>
	void GenerateRandomValuesForAllDistributions(const std::size_t num_of_elements, RandomNumGenerator& number_generator, 
												result_type& result_vector) {
		for (const auto distribution_type : all_distribution_types) 
			result_vector.emplace_back(number_generator.GetGeneratedValues(distribution_type, num_of_elements));
	}

	void TearDown() override {}

	RandomNumberGenerator<int>		int_generator_;
	RandomNumberGenerator<float>	float_generator_;
	RandomNumberGenerator<double>	double_generator_;
	RandomNumberGenerator<long>		long_generator_;

	std::vector<std::vector<int>>		all_distributions_generated_int_;
	std::vector<std::vector<float>>		all_distributions_generated_float_;
	std::vector<std::vector<double>>	all_distributions_generated_double_;
	std::vector<std::vector<long>>		all_distributions_generated_long_;
	
	const std::array<DistributionType, Distributions::number_of_types> all_distribution_types = Distributions::all_distributions_enums;
	const std::size_t num_of_generated_elements_ = std::size_t(5);
};

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Uniform) {
	EXPECT_EQ(all_distributions_generated_int_[0].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[0].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[0].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[0].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Binomial) {
	EXPECT_EQ(all_distributions_generated_int_[1].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[1].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[1].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[1].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_NegativeBinomial) {
	EXPECT_EQ(all_distributions_generated_int_[2].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[2].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[2].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[2].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Geometric) {
	EXPECT_EQ(all_distributions_generated_int_[3].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[3].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[3].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[3].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Poisson) {
	EXPECT_EQ(all_distributions_generated_int_[4].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[4].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[4].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[4].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Exponential) {
	EXPECT_EQ(all_distributions_generated_int_[5].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[5].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[5].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[5].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Gamma) {
	EXPECT_EQ(all_distributions_generated_int_[6].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[6].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[6].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[6].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Weibull) {
	EXPECT_EQ(all_distributions_generated_int_[7].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[7].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[7].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[7].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_ExtremeValue) {
	EXPECT_EQ(all_distributions_generated_int_[8].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[8].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[8].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[8].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Normal) {
	EXPECT_EQ(all_distributions_generated_int_[9].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[9].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[9].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[9].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_LogNormal) {
	EXPECT_EQ(all_distributions_generated_int_[10].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[10].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[10].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[10].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_ChiSquared) {
	EXPECT_EQ(all_distributions_generated_int_[11].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[11].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[11].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[11].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Cauchy) {
	EXPECT_EQ(all_distributions_generated_int_[12].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[12].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[12].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[12].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Fischer_f) {
	EXPECT_EQ(all_distributions_generated_int_[13].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[13].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[13].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[13].size(),		num_of_generated_elements_);
}

TEST_F(RandomNumberGeneratorTest, NumberOfGeneratedValues_Student_t) {
	EXPECT_EQ(all_distributions_generated_int_[14].size(),		num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_float_[14].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_double_[14].size(),	num_of_generated_elements_);
	EXPECT_EQ(all_distributions_generated_long_[14].size(),		num_of_generated_elements_);
}