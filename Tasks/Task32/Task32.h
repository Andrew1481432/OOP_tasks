#ifndef OOP_TASK32_H
#define OOP_TASK32_H

#include <iostream>
#include "../Task.h"

#include "class32/cl_application.h"

using namespace class32;
using namespace std;

class Task32: public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};

#endif //OOP_TASK32_H
