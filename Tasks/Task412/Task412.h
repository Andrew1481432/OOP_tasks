#ifndef OOP_TASK412_H
#define OOP_TASK412_H

#include <iostream>
#include "../Task.h"

using namespace std;

class Task412: public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};

#endif //OOP_TASK412_H
