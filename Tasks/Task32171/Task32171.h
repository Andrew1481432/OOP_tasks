#ifndef OOP_TASK32171_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK32171_H

using namespace std;

class Task32171: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};

#endif //OOP_TASK32171_H