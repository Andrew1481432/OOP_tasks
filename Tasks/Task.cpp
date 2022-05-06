#include "Task.h"

#include "Task111/Task111.h"
#include "Task112/Task112.h"
#include "Task113/Task113.h"
#include "Task114/Task114.h"
#include "Task115/Task115.h"

#include "Task123//Task123.h"
#include "Task124//Task124.h"

#include "Task211/Task211.h"
#include "Task212/Task212.h"
#include "Task213/Task213.h"

#include "Task312/Task312.h"
#include "Task32171/Task32171.h"
#include "Task313/Task313.h"

#include "Task411/Task411.h"
#include "Task412/Task412.h"

#include "Task31/Task31.h"
#include "Task32/Task32.h"

#include <iostream>
#include "../Utils/Utils.h"

using namespace std;

using namespace Utils;

// region fabrica

std::map<int, Task*> Task::tasks;

void Task::init() {
	reg(new Task111());
	reg(new Task112());
	reg(new Task113());
	reg(new Task114());
	reg(new Task115());

	reg(new Task123());
	reg(new Task124());

    reg(new Task211());
    reg(new Task212());
    reg(new Task213());

	reg(new Task312());
	reg(new Task32171());
	reg(new Task313());

	reg(new Task411()); // 1-ая часть курсовой
	reg(new Task412());

	reg(new Task31()); // 2-ая часть курсовой
	reg(new Task32()); // 3-ая часть курсовой
}

bool Task::issetTasks() {
    return !tasks.empty();
}

int Task::run() {
    cout << ">> Введите номер работы: ";
    int n = Utils::getInput<int>();

    if(tasks.find(n) != tasks.end()) { // isset()
	    return tasks[n]->execute();
    } else {
        cout << "Введен неверный номер работы!" << endl;
		return EXIT_FAILURE;
    }
}

void Task::show() {
    cout << "Выберите работу для проверки:" << endl;

    for (const auto& [key, task]: tasks){
        cout << ">> " << key << " - " << task->getName() << endl;
    }
}

void Task::reg(Task *task) {
    Task::tasks[task->getId()] = task;
}

// endregion