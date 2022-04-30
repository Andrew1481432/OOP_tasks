#include "Calc.h"

void Calc::operation(int x, char sign, int y) {
	switch(sign){
		case'+':
			result = x+y;
			break;
		case'-':
			result = x-y;
			break;
		case'*':
			result = x*y;
			break;
		case'%':
			result = x%y;
			break;
	}
}

void Calc::operation(char sign, int y) {
	operation(result, sign, y);
}

int Calc::getRes() {
	return result;
}
