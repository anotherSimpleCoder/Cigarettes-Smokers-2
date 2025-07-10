#pragma once

#include <array>
#include <semaphore>

#define SMOKERS_AMOUNT 3

struct CS_Context {
	std::binary_semaphore* table;
	std::array<std::binary_semaphore, 3>* smokers;
	unsigned int chosenSmoker;
};

CS_Context newCSContext() {
	std::array<std::binary_semaphore, 3> smokers = {
		std::binary_semaphore{0},
		std::binary_semaphore{0},
		std::binary_semaphore{0}
	};

	std::binary_semaphore table{0};
	unsigned int chosenSmoker = -1;

	return {
		&table,
		&smokers,
		chosenSmoker
	};
}
