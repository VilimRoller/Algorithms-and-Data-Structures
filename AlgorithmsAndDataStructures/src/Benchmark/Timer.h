#pragma once

#include <chrono>
#include <iostream>

class Timer {
public:

	Timer(bool start = false) {
		if (start)
			Start();
	}

	void Start() {
		start_time_ = std::chrono::high_resolution_clock::now();
	}

	void Stop() {
		end_time_ = std::chrono::high_resolution_clock::now();
		CalculateDuration();
	}

	void CalculateDuration() noexcept {
		measured_time_ = end_time_ - start_time_;
	}

	[[nodiscard]] const long double GetMeasuredTimeInMicroseconds() const noexcept {
		return measured_time_.count();
	}

	[[nodiscard]] const long long GetMeasuredTimeInMiliseconds() const noexcept {
		return std::chrono::duration_cast<std::chrono::milliseconds>(measured_time_).count();
	}

	[[nodiscard]] const long long GetMeasuredTimeInSeconds() const noexcept {
		return std::chrono::duration_cast<std::chrono::seconds>(measured_time_).count();
	}

	void PrintTimeInMicroSeconds() const noexcept {
		std::cout << "Elapsed time = " << GetMeasuredTimeInMicroseconds() << "us" << std::endl;
	}

	void PrintTimeInMiliSeconds() const noexcept {
		std::cout << "Elapsed time = " << GetMeasuredTimeInMiliseconds() << "ms" << std::endl;
	}

	void PrintTimeInSeconds() const noexcept {
		std::cout << "Elapsed time = " << GetMeasuredTimeInSeconds() << "s" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time_ = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::high_resolution_clock> end_time_ = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long double, std::micro> measured_time_;
};
