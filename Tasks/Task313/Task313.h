#ifndef OOP_TASK313_H

#include <iostream>
#include <cmath>
#include "../Task.h"

#define OOP_TASK313_H

using namespace std;

class Task313: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};

#endif //OOP_TASK313_H