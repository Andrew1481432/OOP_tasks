#ifndef OOP_TASK114_H

#include <iostream>
#include "cmath"
#include "../Task.h"

#define OOP_TASK114_H

using namespace std;

class Task114: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK114_H
