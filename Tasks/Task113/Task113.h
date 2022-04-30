#ifndef OOP_TASK113_H

#include <iostream>
#include "cmath"
#include "../Task.h"

#define OOP_TASK113_H

using namespace std;

class Task113: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK113_H
