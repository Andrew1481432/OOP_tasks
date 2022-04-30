#ifndef OOP_STACK_H
#define OOP_STACK_H

#include <iostream>

using namespace std;

class Stack
{
private: // объявляем приватные поля
	int* array;

	int count; // текущее кол-во элементов
	int size; // размер стека
public:
	string name;
	Stack(string name, int size);

	bool push(int element);
	bool pop(int&);

	bool isFull();

	//размер стека
	int getSize();
	//текущее количество элементов в стеке
	int getCount();
};
#endif //OOP_STACK_H
