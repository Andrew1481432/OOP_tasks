#include "Class5.h"

using namespace Class421;

Class5::Class5(string name): Class1(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}