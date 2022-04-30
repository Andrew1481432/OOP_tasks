#include "Task111.h"

std::string Task111::getName() {
    return "Занятие № 1_1_1";
}

int Task111::getId() {
    return 111;
}

int Task111::execute() {
	int n = 0;
	cin >> n;

	if(n % 2 == 0) {
		cout << "even";
	} else {
		cout << "uneven";
	}
	return EXIT_SUCCESS;
}
