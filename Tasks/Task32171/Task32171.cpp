#include "Task32171.h"
#include "array/Arr.h"

using namespace Arr_32171;

std::string Task32171::getName()
{
    return "Занятие № 3_2_17";
}

int Task32171::getId()
{
    return 3217;
}


/*
Разработать объект, который обладает следующей функциональностью:
- В конструкторе вводит количество элементов целочисленного массива, создает целочисленный массив заданным количеством элементов, определяет значения элементов массива. Значение каждого элемента равно квадрату индекса элемента.
- Выводит значения элементов массива в обратном порядке.
Необходимые свойства объекта определяется разработчиком. Количество элементов массива принадлежит интервалу от 5 до 20.
Написать программу:
1. Создает объект посредством оператора new.
2. Выводит значения элементов массива в обратном порядке.
3. Удаляет объект посредством оператора delete.
 */
int Task32171::execute()
{
	Arr *arrObj = new Arr();
	arrObj->show();
	delete arrObj;

	return EXIT_SUCCESS;
}