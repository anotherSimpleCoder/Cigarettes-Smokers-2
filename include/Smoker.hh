#pragma once

#include "CS_Context.hh"

class Smoker{
private:
	int id;
	CS_Context* csContext;
public:
	Smoker(int id, CS_Context* csContext);
	void run();
};
