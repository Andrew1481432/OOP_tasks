#ifndef OOP_Class412_CLASS1_H
#define OOP_Class412_CLASS1_H

#include <iostream>
#include <cmath>

using namespace std;

namespace Class412
{
	class Class1
	{
		protected:
			string name;
			int par;

			int classId = 1;
		public:
			Class1(string, int);

			void show();
	};
}


#endif //OOP_Class412_CLASS1_H
