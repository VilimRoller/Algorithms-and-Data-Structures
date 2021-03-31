#pragma once
namespace Benchmark {

	constexpr const std::int32_t LLC_size = 1024 * 1024 * 2; // 8MB

	void FlushCache() noexcept {
		volatile const std::size_t bigger_than_cache = std::size_t(LLC_size * 2);
		volatile long long* random_data = new long long[bigger_than_cache];

		for (volatile std::size_t i = std::size_t(0); i < bigger_than_cache; ++i)
			random_data[i] = std::rand();

		delete[] random_data;
	}
}