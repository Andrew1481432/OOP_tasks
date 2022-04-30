#ifndef OOP_TASK111_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK111_H

using namespace std;

class Task111: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};


#endif //OOP_TASK111_H
