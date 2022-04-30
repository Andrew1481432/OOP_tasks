#ifndef OOP_TASK112_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK112_H

using namespace std;

class Task112: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK112_H
