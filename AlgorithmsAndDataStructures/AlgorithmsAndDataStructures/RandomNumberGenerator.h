#pragma once

#include <random>
#include <type_traits>
#include <utility>
#include <vector>
#include <cassert>
#include "DistributionType.h"

template<typename GENERATED_TYPE>
class RandomNumberGenerator {

	using RangePair = std::pair<GENERATED_TYPE, GENERATED_TYPE>;

public:
	RandomNumberGenerator() {
		CheckType();
		SetRandomNumberEngine();
	}

	void CheckType() const noexcept {
	static_assert(std::is_integral<GENERATED_TYPE>::value || std::is_floating_point<GENERATED_TYPE>::value, 
		"Wrong type used, only integer and floating types are allowed");
	}

	void SetRandomNumberEngine() {
		random_number_engine_ = std::mt19937_64(random_device_());
	}

	void SetRange(const GENERATED_TYPE bottom_limit, const GENERATED_TYPE upper_limit) {
		range_ = std::make_pair(bottom_limit, upper_limit);
	}

	constexpr bool IsIntegral() const noexcept {
		return std::is_integral<GENERATED_TYPE>::value;
	}

	constexpr bool IsFloatingPoint() const noexcept{
		return std::is_floating_point<GENERATED_TYPE>::value;
	}

	std::vector<GENERATED_TYPE>&& GetGeneratedValues(DistributionType distribution_type,
		const std::size_t num_of_elements,
		const RangePair range = range_) {

		SetRange(range);

		switch (distribution_type) {
		case DistributionType::Uniform:
			GetUniformDistribution(num_of_elements)
				break;
		case DistributionType::Bernoulli:
			break;
		case DistributionType::Binomial:
			break;
		case DistributionType::NegativeBinomial:
			break;
		case DistributionType::Geometric:
			break;
		case DistributionType::Poisson:
			break;
		case DistributionType::Exponential:
			break;
		case DistributionType::Gamma:
			break;
		case DistributionType::Weibull:
			break;
		case DistributionType::ExtremeValue:
			break;
		case DistributionType::Normal:
			break;
		case DistributionType::LogNormal:
			break;
		case DistributionType::ChiSquared:
			break;
		case DistributionType::Cauchy:
			break;
		case DistributionType::Fischer_f:
			break;
		case DistributionType::Student_t:
			break;
		case DistributionType::Discrete:
			break;
		case DistributionType::PieceWiseConstant:
			break;
		case DistributionType::PieceWiseLinear:
			break;
		default:
			return std::vector<GENERATED_TYPE>();
		}
	}


#pragma region DISTRIBUTION IMPLEMENTATIONS

	template <typename DISTRIBUTON_TYPE>
	std::vector<GENERATED_TYPE>&& GetFilledVector(DISTRIBUTON_TYPE& distribution, const std::size_t num_of_elements) {
		std::vector<GENERATED_TYPE> return_value;

		for (std::size_t i = std::size_t(0); i < num_of_elements; ++i)
			return_value.emplace_back(static_cast<GENERATED_TYPE>(distribution(random_number_engine_)));

		return std::move(return_value);
	}

	/*--------------------------------------------------------------------------------------------------------------------------*/
	/*												UNIFORM DISTRIBUTIONS														*/
	/*--------------------------------------------------------------------------------------------------------------------------*/

	std::vector<GENERATED_TYPE>&& GetUniformDistribution(const std::size_t num_of_elements) {
		if (IsIntegral())
			return GetUniformIntDistribution(num_of_elements);
		else 
			return GetUniformRealDistribution(num_of_elements);
	}

	std::vector<GENERATED_TYPE>&& GetUniformIntDistribution(const std::size_t num_of_elements) {
		std::uniform_int_distribution<long long> distribution(range_.first, range_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	std::vector<GENERATED_TYPE>&& GetUniformRealDistribution(const std::size_t num_of_elements) {
		std::uniform_real_distribution<long double> distribution(range_.first, range_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	/*--------------------------------------------------------------------------------------------------------------------------*/
	/*											  BERNOULLI DISTRIBUTIONS														*/
	/*--------------------------------------------------------------------------------------------------------------------------*/





#pragma endregion

	

private:

	RangePair range_;
	std::random_device random_device_;
	std::mt19937_64 random_number_engine_;
};