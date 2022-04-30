#include "Task313.h"
#include "stack/Stack.h"

std::string Task313::getName() {
    return "Занятие № 3_1_3";
}

int Task313::getId() {
    return 313;
}


/*
Создать класс для объекта стек. Стек хранит целые числа. Имеет характеристики:
 наименование (строка, не более 10 символов) и размер (целое).
 Размер стека больше или равно 1.
 Функционал стека:
-    добавить элемент и вернуть признак успеха (логическое);
-    извлечь элемент (НЕ вывести!) и вернуть признак успеха (логическое);
-    получить имя стека (строка);
-    получить размер стека (целое);
-    получить текущее количество элементов в стеке (целое).

В классе определить параметризированный конструктор, которому передается имя стека и размер.
 При переполнении стека очередной элемент не добавлять и определяется соответствующий признак успеха.

В основной программе реализовать алгоритм:
1.    Ввести имя и размер для первого стека.
2.    Создать объект первого стека.
3.    Ввести имя и размер для второго стека.

4.    Создать объект второго стека.
5.    В цикле:
     5.1.   Считывать очередное значение элемента.
     5.2.   Добавлять элемент в первый стек, при переполнении завершить цикл.

     5.3.   Добавлять элемент во второй стек, при переполнении завершить цикл.

6.    Построчно вывести содержимое стеков.
 */
//int Task313::execute() {
//	string name;
//	int size;
//	cin >> name >> size; // 1
//	Stack *objStack1 = new Stack(name, size);
//	cin >> name >> size; // 2
//	Stack *objStack2 = new Stack(name, size);
//
//	int element;
//	do { //5.2. Добавлять элемент в первый стек, при переполнении завершить цикл.
//		cin >> element;
//		objStack1->push(element);
//	} while(!objStack1->isFull());
//	do { // 5.3. Добавлять элемент во второй стек, при переполнении завершить цикл.
//		cin >> element;
//		objStack2->push(element);
//	} while(!objStack2->isFull());
//
//	cout << objStack1->name << " " << objStack1->getSize() << endl;
//	cout << objStack2->name << " " << objStack2->getSize() << endl;
//
//	printf("%-15s %-15s\n", objStack1->name.c_str(), objStack2->name.c_str());
//
//	int maxSize = max(objStack1->getSize(), objStack2->getSize());
//	int diff = abs(objStack1->getSize()-objStack2->getSize());
//	if(diff>0)
//		maxSize -= diff-1;
//	for(int i=0; i<maxSize; i++) {
//		int el = 0;
//		if(i < objStack1->getSize() && i < objStack2->getSize()) {
//			objStack1->pop(el);
//			printf("%15d ", el);
//			objStack2->pop(el);
//			printf("%15d\n", el);
//		} else if(i < objStack2->getSize()) {
//			printf("%15c ", ' ');
//			objStack2->pop(el);
//			printf("%15d\n", el);
//		} else {
//			objStack1->pop(el);
//			printf("%15d\n", el);
//		}
//	}
//
//	delete objStack1;
//	delete objStack2;
//	return EXIT_SUCCESS;
//}


int Task313::execute() {
	string name;
	int size;
	cin >> name >> size; // 1
	Stack *objStack1 = new Stack(name, size);
	cin >> name >> size; // 2
	Stack *objStack2 = new Stack(name, size);

	int element;
	do {
		cin >> element;
		if(!objStack1->push(element))
			break;

		if(!objStack2->push(element))
			break;
	} while(true);

	cout << objStack1->name << " " << objStack1->getSize() << endl;
	cout << objStack2->name << " " << objStack2->getSize() << endl;

	printf("%-15s%-15s\n", objStack1->name.c_str(), objStack2->name.c_str());

	int el = 0;
	bool first = true;
	while(true) {
		if(!objStack1->pop(el)) {
			break;
		} else {
			if(!first) {
				cout << endl;
			}
			printf("%15d", el);
		}
		if(!objStack2->pop(el)) {
			break;
		} else {
			printf("%15d", el);
		}
		first = false;
	}

	delete objStack1;
	delete objStack2;
	return EXIT_SUCCESS;
}



