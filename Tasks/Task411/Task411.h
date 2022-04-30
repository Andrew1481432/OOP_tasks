#ifndef OOP_TASK411_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK411_H

using namespace std;

class Task411 : public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};


#endif //OOP_TASK411_H
