#ifndef OOP_Class421_CLASS7_H
#define OOP_Class421_CLASS7_H

#include "Class4.h"
#include "Class5.h"

namespace Class421
{
	class Class7: public Class4, public Class5
	{
			string name;
			int classId = 7;
		public:
			Class7(string);
	};
}


#endif //OOP_Class421_CLASS7_H
