#include "Class4.h"

using namespace Class412;

void Class4::show()
{
	cout << name+"_"+std::to_string(classId) << " " << pow(par, classId) << endl;
}