#include "Task421.h"
#include "class421/Class2.h"
#include "class421/Class8.h"

using namespace Class421;

std::string Task421::getName()
{
	return "Занятие № 4_2_1";
}

int Task421::getId()
{
	return 421;
}

int Task421::execute()
{
	Class2* x;
	string name;
	cin >> name;

	Class8::init(name);
	Class8 obj(name);
	x = &obj;
	sort(x->nasNames.begin(), x->nasNames.end());
	for (auto it = x->nasNames.begin(); it != x->nasNames.end(); ++it){
		cout << *it;
		if (*it != name+"_8") cout << endl;
	}
	return EXIT_SUCCESS;
}