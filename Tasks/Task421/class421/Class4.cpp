#include "Class4.h"

using namespace Class421;

Class4::Class4(string name): Class1(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}