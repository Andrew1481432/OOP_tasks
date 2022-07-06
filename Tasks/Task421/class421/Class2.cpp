#include "Class2.h"

using namespace Class421;

Class2::Class2(string name): Class1(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}