#include <iostream>
#include "Tasks/Task.h"

using namespace std;

int main() {
	Task::init();

	if (Task::issetTasks()) {
		Task::show();
		return Task::run();
	} else {
		cout << "Задач не обнаружено!" << endl;
		return EXIT_FAILURE;
	}
}
