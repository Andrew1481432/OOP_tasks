#ifndef OOP_Class412_CLASS2_H
#define OOP_Class412_CLASS2_H

#include "Class1.h"

namespace Class412
{
	class Class2: protected Class1
	{
		protected:
			int classId = 2;
		public:
			Class2(string name, int par): Class1(name, par){}

			void show();
	};
}


#endif //OOP_Class412_CLASS2_H
