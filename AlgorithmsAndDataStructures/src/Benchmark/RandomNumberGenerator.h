#pragma once

#include <random>
#include <type_traits>
#include <utility>
#include <vector>
#include <cassert>
#include <limits>
#include "DistributionType.h"

template<typename GENERATED_TYPE>
class RandomNumberGenerator {

	using RangePair = std::pair<long, long>;

public:
	RandomNumberGenerator() {
		//CheckType();
	}

	void SetRange(const long bottom_limit, const long upper_limit) noexcept {
		range_ = std::make_pair(bottom_limit, upper_limit);
	}

	void SetProbability(const double probability) noexcept {
		probability_ = probability;
	}

	void SetMean(const double mean) noexcept {
		mean_ = mean;
	}

	void SetLambda(const double lambda) noexcept {
		lambda_ = lambda;
	}

	void SetAlphaBeta(const double alpha, const double beta) noexcept {
		alpha_beta_ = std::make_pair(alpha, beta);
	}

	void Set_ab_Parameters(const double a, const double b) noexcept {
		ab_parameters_ = std::make_pair(a, b);
	}

	void SetStandardDeviation(const double stdev) noexcept {
		stdev_ = stdev;
	}

	void Set_ms_Parameters(const double m, const double s) noexcept {
		ms_parameters_ = std::make_pair(m, s);
	}

	void SetDegreesOfFreedom(const double degrees) noexcept {
		degrees_of_freedom_ = degrees;
	}

	void Set_mn_DegreesOfFreedom(const double m, const double n) {
		mn_degrees_of_freedom_ = std::make_pair(m, n);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetGeneratedValues(DistributionType distribution_type,
		const std::size_t num_of_elements) const noexcept {

		switch (distribution_type) {
		case DistributionType::Uniform:
			return GetUniformDistributionValues(num_of_elements);
			break;
		case DistributionType::Binomial:
			return GetBinomialDistributionValues(num_of_elements);
			break;
		case DistributionType::NegativeBinomial:
			return GetNegativeBinomialDistributionValues(num_of_elements);
			break;
		case DistributionType::Geometric:
			return GetGeometricDistributionValues(num_of_elements);
			break;
		case DistributionType::Poisson:
			return GetPoissonDistributionValues(num_of_elements);
			break;
		case DistributionType::Exponential:
			return GetExponentialDistributionValues(num_of_elements);
			break;
		case DistributionType::Gamma:
			return GetGammaDistributionValues(num_of_elements);
			break;
		case DistributionType::Weibull:
			return GetWeibullDistributionValues(num_of_elements);
			break;
		case DistributionType::ExtremeValue:
			return GetExtremeValueDistributionValues(num_of_elements);
			break;
		case DistributionType::Normal:
			return GetNormalDistributionValues(num_of_elements);
			break;
		case DistributionType::LogNormal:
			return GetLogNormalDistributionValues(num_of_elements);
			break;
		case DistributionType::ChiSquared:
			return GetChiSquaredDistributionValues(num_of_elements);
			break;
		case DistributionType::Cauchy:
			return GetCauchyDistributionValues(num_of_elements);
			break;
		case DistributionType::Fischer_f:
			return GetFischer_fDistributionValues(num_of_elements);
			break;
		case DistributionType::Student_t:
			return GetStudent_tValueDistributionValues(num_of_elements);
			break;
		default:
			return GetNoDistributionValues(num_of_elements);
		}
	}


private:

	void CheckType() const noexcept {
	static_assert(std::is_integral<GENERATED_TYPE>::value || std::is_floating_point<GENERATED_TYPE>::value, 
		"Wrong type used, only integer and floating types are allowed");
	}

	[[nodiscard]] constexpr bool IsIntegral() const {
		return std::is_integral<GENERATED_TYPE>::value;
	}

	[[nodiscard]] constexpr bool IsFloatingPoint() const{
		return std::is_floating_point<GENERATED_TYPE>::value;
	}

#pragma region DISTRIBUTION IMPLEMENTATIONS

	template <typename DISTRIBUTON_TYPE>
	[[nodiscard]] std::vector<GENERATED_TYPE> GetFilledVector(DISTRIBUTON_TYPE& distribution, const std::size_t num_of_elements) const {
		std::vector<GENERATED_TYPE> return_value;
		std::random_device random_device_;
		std::mt19937_64 random_number_engine_(random_device_());

		return_value.reserve(num_of_elements);

		for (std::size_t i = std::size_t(0); i < num_of_elements; ++i)
			return_value.emplace_back(static_cast<GENERATED_TYPE>(distribution(random_number_engine_)));

		return std::move(return_value);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetNoDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::vector<GENERATED_TYPE> return_value;
		std::random_device random_device_;
		std::mt19937_64 random_number_engine_(random_device_());

		return_value.reserve(num_of_elements);

		for (std::size_t i = std::size_t(0); i < num_of_elements; ++i)
			return_value.emplace_back(static_cast<GENERATED_TYPE>(random_number_engine_()));

		return std::move(return_value);
	}

/*--------------------------------------------------------------------------------------------------------------------------*/
/*												UNIFORM DISTRIBUTIONS														*/
/*--------------------------------------------------------------------------------------------------------------------------*/

	[[nodiscard]] std::vector<GENERATED_TYPE> GetUniformDistributionValues(const std::size_t num_of_elements) const noexcept {
		if (IsIntegral())
			return GetUniformIntDistributionValues(num_of_elements);
		else 
			return GetUniformRealDistributionValues(num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetUniformIntDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::uniform_int_distribution<long long> distribution(static_cast<long>(range_.first), static_cast<long>(range_.second));

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetUniformRealDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::uniform_real_distribution<double> distribution(static_cast<double>(range_.first), static_cast<double>(range_.second));

		return GetFilledVector(distribution, num_of_elements);
	}

/*--------------------------------------------------------------------------------------------------------------------------*/
/*											  BERNOULLI DISTRIBUTIONS														*/
/*--------------------------------------------------------------------------------------------------------------------------*/

	[[nodiscard]] std::vector<GENERATED_TYPE> GetBinomialDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::binomial_distribution<long long> distribution(static_cast<long>(range_.second), probability_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetNegativeBinomialDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::negative_binomial_distribution<long long> distribution(static_cast<long>(range_.second), probability_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetGeometricDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::geometric_distribution<long long> distribution(probability_);

		return GetFilledVector(distribution, num_of_elements);
	}

/*--------------------------------------------------------------------------------------------------------------------------*/
/*											  POISSON DISTRIBUTIONS															*/
/*--------------------------------------------------------------------------------------------------------------------------*/

	[[nodiscard]] std::vector<GENERATED_TYPE> GetPoissonDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::poisson_distribution<long long> distribution(mean_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetExponentialDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::exponential_distribution<long double> distribution(lambda_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetGammaDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::gamma_distribution<long double> distribution(alpha_beta_.first, alpha_beta_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetWeibullDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::weibull_distribution<long double> distribution(ab_parameters_.first, ab_parameters_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetExtremeValueDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::extreme_value_distribution<long double> distribution(ab_parameters_.first, ab_parameters_.second);

		return GetFilledVector(distribution, num_of_elements);
	}


/*--------------------------------------------------------------------------------------------------------------------------*/
/*											  NORMAL DISTRIBUTIONS															*/
/*--------------------------------------------------------------------------------------------------------------------------*/

	[[nodiscard]] std::vector<GENERATED_TYPE> GetNormalDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::normal_distribution<long double> distribution(mean_, stdev_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetLogNormalDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::lognormal_distribution<long double> distribution(ms_parameters_.first, ms_parameters_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetChiSquaredDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::chi_squared_distribution<long double> distribution(degrees_of_freedom_);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetCauchyDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::cauchy_distribution<long double> distribution(ab_parameters_.first, ab_parameters_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetFischer_fDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::fisher_f_distribution<long double> distribution(mn_degrees_of_freedom_.first, mn_degrees_of_freedom_.second);

		return GetFilledVector(distribution, num_of_elements);
	}

	[[nodiscard]] std::vector<GENERATED_TYPE> GetStudent_tValueDistributionValues(const std::size_t num_of_elements) const noexcept {
		std::student_t_distribution<long double> distribution(degrees_of_freedom_);

		return GetFilledVector(distribution, num_of_elements);
	}

#pragma endregion

	
	/*------------------------------------------------------------------------------------------------------------------------------*/
	/*												DISTRIBUTION INPUT VALUES														*/											
	/*------------------------------------------------------------------------------------------------------------------------------*/
	

	RangePair range_ = std::make_pair(-100000, 100000);

	double probability_ = 0.1;										//Binomial, Negative binomial, Geometric
	double mean_ = 1.0;												//Poisson, Normal
	double lambda_ = 0.3;											//Exponential
	std::pair<double, double> alpha_beta_{ 1.0, 1.0 };				//Gamma
	std::pair<double, double> ab_parameters_{ 1.0, 1.0 };			//Weibull, Extreme value, Cauchy

	double stdev_ = 0.5;											//Normal
	std::pair<double, double> ms_parameters_{1.0, 1.0};				//LogNormal
	double degrees_of_freedom_ = 1000.0;							//Chi squared, Student_t
	std::pair<double, double> mn_degrees_of_freedom_{ 1.0, 1.0 };	//Fischer

};
