#include "Distributor.hh"

#include <random>

Distributor::Distributor(CS_Context* csContext) {
	this->csContext = csContext;
}

void Distributor::run() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0,2);

	while(true) {
		int chosenSmoker = dis(gen);
		csContext->chosenSmoker = chosenSmoker;
		csContext->smokers->at(chosenSmoker).release();
		csContext->table->release();
	}
}
