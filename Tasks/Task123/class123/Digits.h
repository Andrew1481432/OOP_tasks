#ifndef OOP_DIGITS_H
#define OOP_DIGITS_H

class Digits {

private:
	long long int n;
	int countN;

public:
	//задает значение свойства n;
	void setN(long long int n);

	long long int getN();

	//вычисляет количество цифр значения свойства n;
	void calcN();

	//возвращает количество цифр значения свойства n.
	int getCountN();
};

#endif //OOP_DIGITS_H
