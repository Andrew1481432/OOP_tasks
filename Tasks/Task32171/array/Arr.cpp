#include "Arr.h"

// в конструкторе считывает значение количества элементов массива, выводит значение количества элементов;
Arr_32171::Arr::Arr()
{
	cin >> N;
	this->arr = new int[N];
	for (int i=0;i<N;i++)
	{
		arr[i] = i*i;
	}
}

void Arr_32171::Arr::show()
{
	for (int i=N-1;i>=0;i--) printf("%5d", arr[i]);
}

Arr_32171::Arr::~Arr()
{
	delete[] this->arr;
}

