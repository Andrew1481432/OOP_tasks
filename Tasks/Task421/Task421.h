#ifndef OOP_TASK421_H
#define OOP_TASK421_H

#include <iostream>
#include "../Task.h"

using namespace std;

class Task421: public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};

#endif //OOP_TASK421_H
