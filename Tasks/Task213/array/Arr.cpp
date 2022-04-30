#include "Arr.h"

// в конструкторе считывает значение количества элементов массива, выводит значение количества элементов;
Arr::Arr(int size) {
	this->N = size;
	this->arr = new int[size];
	cout << "N = " << size << endl; // вывод длины массива
}

// считывает значения элементов массива;
void Arr::setArr(){
	for (int i=0;i<N;i++) cin>>arr[i];
}

//выводит значения элементов массива;
void Arr::show(){
	for (int i=0;i<N;i++) printf("%5d", arr[i]);
}

void Arr::reverse(){
	for(int i = 0; i < N/2; i++) {
		std::swap(arr[i], arr[N-1-i]);
	}
}

// hack ;(
/*void Arr::reverse(){
	std::reverse(arr, arr+N);
}*/

Arr::~Arr() {
	delete[] this->arr;
}

