#ifndef OOP_TASK212_H

#include <iostream>
#include "../Task.h"

#define OOP_TASK212_H

using namespace std;

class Task212: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    int execute() override;
};

#endif //OOP_TASK212_H