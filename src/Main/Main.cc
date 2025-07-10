#include <array>
#include <iostream>
#include <semaphore>
#include <thread>

#include "CS_Context.hh"
#include "Smoker.hh"
#include "Distributor.hh"

int main(int argc, char** argv) {
	CS_Context csContext = newCSContext();
	Distributor distributor(&csContext);
	std::array<int, 3> ids = {0, 1, 2};
	std::array<Smoker, 3> smokers;

	std::transform(ids.begin(), ids.end(), smokers.begin(), [csContext](int id){return Smoker(id, &csContext);});

	return 0;
}
