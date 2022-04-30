#include "Class1.h"

using namespace Class412;

Class1::Class1(string name, int par) {
	this->name = name;
	this->par = par;
}

void Class1::show()
{
	cout << name+"_"+std::to_string(classId) << " " << pow(par, classId) << endl;
}