#ifndef OOP_TASK33_H
#define OOP_TASK33_H

#include <iostream>
#include "../Task.h"

#include "class33/cl_application.h"

using namespace class33;
using namespace std;

class Task33: public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};

#endif //OOP_TASK33_H
