#ifndef OOP_Class421_CLASS1_H
#define OOP_Class421_CLASS1_H

#include <iostream>
#include <vector>

using namespace std;

namespace Class421
{
	class Class1
	{
			string name;
			int classId = 1;
			static string staticName;
	public:
			static vector<string> nasNames;
			Class1(string);
			Class1();

			static void init(string);
	};
}


#endif //OOP_Class421_CLASS1_H
