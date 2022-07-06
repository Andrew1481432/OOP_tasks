#include "Class3.h"

using namespace Class421;

Class3::Class3(string name): Class1(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}