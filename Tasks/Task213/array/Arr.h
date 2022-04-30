#ifndef OOP_ARR_H
#define OOP_ARR_H

#include <iostream>

using namespace std;

class Arr {
	int* arr;

	int N;
public:
	Arr(int);
	void setArr();
	void show();
	void reverse();
	~Arr();
};

#endif //OOP_ARR_H
