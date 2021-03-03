// AlgorithmsAndDataStructures.cpp : Defines the entry point for the application.
//

#include "AlgorithmsAndDataStructures.h"

#include <memory>

int main()
{
	auto generator = std::make_unique<RandomNumberGenerator<int>>();

	Timer t1;

	return 0;
}
