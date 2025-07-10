#include <array>
#include <algorithm>
#include <thread>
#include <vector>

#include "Smoker.hh"
#include "Distributor.hh"

int main(int argc, char** argv) {
	CS_Context csContext = newCSContext();
	Distributor distributor(&csContext);
	std::array ids = {0, 1, 2};
	std::array<Smoker, 3> smokers{};
	std::ranges::transform(ids, smokers.begin(), [&csContext](int id){return Smoker(id, &csContext);});
	std::vector<std::thread> smokerThreads;

	std::thread distributorThread(&Distributor::run, &distributor);
	for (auto& smoker : smokers) {
		smokerThreads.emplace_back(&Smoker::run, &smoker);
	}

	distributorThread.join();
	for (auto& smokerThread : smokerThreads) {
		smokerThread.join();
	}

	return 0;
}
