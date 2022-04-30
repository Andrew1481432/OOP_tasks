#ifndef OOP_TASK31_H
#define OOP_TASK31_H

#include <iostream>
#include "../Task.h"

#include "class31/cl_application.h"

using namespace class31;
using namespace std;

class Task31: public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};

#endif //OOP_TASK31_H
