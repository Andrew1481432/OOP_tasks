#ifndef OOP_TASK213_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK213_H

using namespace std;

class Task213: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};

#endif //OOP_TASK213_H