#include "Class1.h"

using namespace Class421;

vector<string> Class1::nasNames;
string Class1::staticName;

Class1::Class1(string name) {
	this->name = name;
	nasNames.push_back(name+"_"+std::to_string(classId));
}

Class1::Class1() {
	nasNames.push_back(staticName+"_"+std::to_string(classId));
}

void Class1::init(string name)
{
	staticName = name;
}
