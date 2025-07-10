#ifndef CS_CONTEXT_HH
#define CS_CONTEXT_HH

#include <array>
#include <semaphore>

#define SMOKERS_AMOUNT 3

struct CS_Context {
	std::binary_semaphore* table;
	std::array<std::binary_semaphore, 3>* smokers;
	unsigned int chosenSmoker;
};

CS_Context newCSContext();

#endif