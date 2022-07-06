#ifndef OOP_Class421_CLASS2_H
#define OOP_Class421_CLASS2_H

#include "Class1.h"

namespace Class421
{
	class Class2: public virtual Class1
	{
			string name;
			int classId = 2;
		public:
			Class2(string);
	};
}


#endif //OOP_Class421_CLASS2_H
