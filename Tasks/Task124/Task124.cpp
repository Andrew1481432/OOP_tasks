#include "Task124.h"
#include "class124/Calc.h"

std::string Task124::getName() {
    return "Занятие № 1_2_4";
}

int Task124::getId() {
    return 124;
}

/*
Создать объект, который вычисляет значение целочисленного арифметического выражения, состоящего из трех последовательных операции. Операция деления заменена на операцию вычисления целочисленного остатка.
Объект обладает следующей функциональностью:
- выполняет первую операцию выражения, в качестве параметров передается первый целочисленный параметр, символ операции (+,-,*,%), второй целочисленный параметр;
- вычисляет вторую и далее операцию, в качестве параметров передается символ операции (+,-,*,%), второй целочисленный параметр;
- возвращает значение вычисленного выражения (значение можно получить после выполнения трех операции).
Написать программу, которая:
1. Создает объект.
2. Вводит значения аргументов для первой операции.
3. Выполняет первую операцию.
4. Вводит значение аргументов для второй операции.
5. Выполняет вторую операцию.
6. Вводит значение аргументов для третьей операции.
7. Выполняет третью операцию.
8. Выводит результат.
 */
int Task124::execute() {
	Calc *calc = new Calc();
	int x, y = 0;
	char sign;
	cin >> x >> sign >> y;
	calc->operation(x, sign, y);
	cin >> sign >> y;
	calc->operation(sign, y);
	cin >> sign >> y;
	calc->operation(sign, y);
	cout << calc->getRes();
	delete calc;
	return EXIT_SUCCESS;
}