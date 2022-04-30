#ifndef OOP_CALC_H
#define OOP_CALC_H

#include <iostream>

using namespace std;

class Calc {
	private:
		int result;
	public:
		void operation(int x, char sign, int y);
		void operation(char sign, int y);
		int getRes();
};

#endif //OOP_CALC_H
