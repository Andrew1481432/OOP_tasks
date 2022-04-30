#ifndef OOP_TASK123_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK123_H

using namespace std;

class Task123: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK123_H
