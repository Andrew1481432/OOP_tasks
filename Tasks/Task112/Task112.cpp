#include "Task112.h"

std::string Task112::getName() {
    return "Занятие № 1_1_2";
}

int Task112::getId() {
    return 112;
}


/**
 * Программа демонстрирует работу оператора цикла.
 * Вычисление суммы натуральных чисел. Вводится целое n.
 * Вычисляется сумма натуральных чисел от 1 до n (включительно).
 * Проверить значение n на допустимость.
 */
int Task112::execute() {
	int n = 0;
	cin >> n;

	if(cin.fail()||n<1) {
		cout << "n is wrong (" << n << ")";
		return EXIT_FAILURE;
	}

	int s = 0;
	for(int i = 0; i < n; i++) {
		s += (i+1);
	}

	cout << "Sum_n = " << s;
	return EXIT_SUCCESS;
}
