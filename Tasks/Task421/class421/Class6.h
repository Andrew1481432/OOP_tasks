#ifndef OOP_Class421_CLASS6_H
#define OOP_Class421_CLASS6_H

#include "Class2.h"
#include "Class3.h"

namespace Class421
{
	class Class6: public Class2, public Class3
	{
			string name;
			int classId = 6;
		public:
			Class6(string);
	};
}


#endif //OOP_Class421_CLASS6_H
