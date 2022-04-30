#include "Task211.h"
#include "Class211/Class211.h"

std::string Task211::getName() {
    return "Занятие № 2_1_1";
}

int Task211::getId() {
    return 211;
}


/**
 * Задача
Создать объект, который сообщает об отработке конструктора и деструктора.
У объекта нет свойств и функциональности.
Написать программу, которая:
1.	Создает объект.
Входные данные
Отсутствует.
Выходные данные
Первая строка, с первой позиции: Constructor
Вторая строка, с первой позиции: Destructor
 */
int Task211::execute() {
	Class211 *obj = new Class211();
	delete obj;
	return EXIT_SUCCESS;
}

