#include "Smoker.hh"

#include <iostream>

Smoker::Smoker(int id, CS_Context* csContext) {
	this->id = id;
	this->csContext = csContext;
}

void Smoker::run() {
	while(true) {
		this->csContext->smokers->at(this->id).acquire();
		this->csContext->table->acquire();
		std::cout << "Smoker " << this->id << " is smoking\n";
	}
}
