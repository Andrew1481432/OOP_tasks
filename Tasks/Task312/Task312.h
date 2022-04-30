#ifndef OOP_TASK312_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK312_H

using namespace std;

class Task312 : public Task
{
	virtual std::string getName() override;

	virtual int getId() override;

	int execute() override;
};


#endif //OOP_TASK312_H
