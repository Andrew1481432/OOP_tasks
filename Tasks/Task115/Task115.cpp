#include "Task115.h"

std::string Task115::getName() {
    return "Занятие № 1_1_5";
}

int Task115::getId() {
    return 115;
}

int Task115::execute() {
    int N = 0;
    cin >> N;
    if(cin.fail()||N<1 || N>9) {
        cout << "N is wrong: " << N;
        return EXIT_FAILURE;
    }

	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			cout << j+1 << ((j<i) ? " " : "");
		}
		if(i<(N-1)) {
			cout << endl;
		}
	}
	return EXIT_SUCCESS;
}
