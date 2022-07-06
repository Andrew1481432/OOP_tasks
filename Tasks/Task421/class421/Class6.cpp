#include "Class6.h"

using namespace Class421;

Class6::Class6(string name): Class2(name), Class3(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}