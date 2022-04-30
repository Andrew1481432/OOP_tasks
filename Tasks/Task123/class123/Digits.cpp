#include "Digits.h"

void Digits::setN(long long int n) {
	this->n = n;
}

long long int Digits::getN() {
	return this->n;
}

void Digits::calcN() {
	this->countN = 0;
	long long int n = this->n;
	if(n == 0) {
		this->countN++;
		return;
	}
	while(n != 0) {
		n /= 10;
		this->countN++;
	}
}

int Digits::getCountN() {
	return this->countN;
}