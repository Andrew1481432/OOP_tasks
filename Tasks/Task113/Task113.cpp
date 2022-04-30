#include "Task113.h"

std::string Task113::getName() {
    return "Занятие № 1_1_3";
}

int Task113::getId() {
    return 113;
}


/**
 * Программа демонстрирует работу оператора цикла.
 * Вычислить количество цифр в целом числе.
 * Для представления целого числа использовать целый
 * тип с максимальным объемом памяти.
 */
int Task113::execute() {
	int countN = 0;
	long long int N = 0;

	cin >> N;
	N = abs(N);
	if(N != 0) {
		while (N > 0) {
			countN++;
			N /= 10;
		}
	} else {
		countN++;
	}

	cout<<"Number of digits: "<<countN;
	return EXIT_SUCCESS;
}
