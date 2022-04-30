#ifndef OOP_CLASS2_H
#define OOP_CLASS2_H

#include "Class1.h"

class Class2 {
		int val1;
		int val2;
		//у которого две целочисленных свойства.

		friend int getMaxValue(class Class1 *obj1, class Class2 *obj2);
	public:
		//Значение данных свойств определяется посредством метода объекта.
		void setValue(int, int);
	//Реализовать дружественную функцию, которая находит максимальное
	//значение полей объекта первого типа и полей объекта второго типа.
};


#endif //OOP_CLASS2_H
