#pragma once
#include <array>

enum class DistributionType {
	Uniform,
	Binomial,
	NegativeBinomial,
	Geometric,
	Poisson,
	Exponential,
	Gamma,
	Weibull,
	ExtremeValue,
	Normal,
	LogNormal,
	ChiSquared,
	Cauchy,
	Fischer_f,
	Student_t
};

namespace Distributions {
	constexpr int number_of_types = 15;

	const std::array<DistributionType, number_of_types> all_distributions_enums{
		DistributionType::Uniform,
		DistributionType::Binomial,
		DistributionType::NegativeBinomial,
		DistributionType::Geometric,
		DistributionType::Poisson,
		DistributionType::Exponential,
		DistributionType::Gamma,
		DistributionType::Weibull,
		DistributionType::ExtremeValue,
		DistributionType::Normal,
		DistributionType::LogNormal,
		DistributionType::ChiSquared,
		DistributionType::Cauchy,
		DistributionType::Fischer_f,
		DistributionType::Student_t };
}

