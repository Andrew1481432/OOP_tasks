#include "Class7.h"

using namespace Class421;

Class7::Class7(string name): Class4(name), Class5(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}