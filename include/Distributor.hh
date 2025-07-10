#pragma once

#include "CS_Context.hh"

class Distributor {
private:
	CS_Context* csContext;	

public:
	Distributor(CS_Context* csContext);
	void run();
};
