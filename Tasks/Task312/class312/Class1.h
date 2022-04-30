#ifndef OOP_CLASS1_H
#define OOP_CLASS1_H


#include "Class2.h"

class Class1 {
		int val;

		friend int getMaxValue(Class1 *obj1, class Class2 *obj2);
	public:
		Class1(int);
		// у которого одно целочисленное свойство.
		// Значение данного свойства определяется посредством параметризированного конструктора.
};


#endif //OOP_CLASS1_H
