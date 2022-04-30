#include "Class3.h"

using namespace Class412;

void Class3::show()
{
	cout << name+"_"+std::to_string(classId) << " " << pow(par, classId) << endl;
}