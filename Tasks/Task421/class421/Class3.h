#ifndef OOP_Class421_CLASS3_H
#define OOP_Class421_CLASS3_H

#include "Class1.h"

namespace Class421
{
	class Class3: public virtual Class1
	{
			string name;
			int classId = 3;
		public:
			Class3(string);
	};
}


#endif //OOP_Class421_CLASS3_H
