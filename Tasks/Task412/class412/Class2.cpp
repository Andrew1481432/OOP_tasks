#include "Class2.h"

using namespace Class412;

void Class2::show()
{
	cout << name+"_"+std::to_string(classId) << " " << pow(par, classId) << endl;
}