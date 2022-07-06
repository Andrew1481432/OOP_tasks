#include "Class8.h"

using namespace Class421;

Class8::Class8(string name): Class6(name), Class7(name)
{
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}