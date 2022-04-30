#include "Stack.h"

Stack::Stack(string name, int size)
{
	this->name = name;
	this->size = size;
	this->array = new int[size];

	count = 0;
}

bool Stack::isFull()
{
	return count>=size;
}

bool Stack::push(int element)
{
	if(count>=size) return false;
	array[count] = element;
	count++;
	return true;
}

bool Stack::pop(int& where)
{
	if (count-1<0) return false;
	count--;
	where = array[count];
	return true;
}

int Stack::getCount()
{
	return this->count;
}

int Stack::getSize()
{
	return this->size;
}