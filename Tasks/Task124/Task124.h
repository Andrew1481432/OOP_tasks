#ifndef OOP_TASK124_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK124_H

using namespace std;

class Task124: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK124_H
