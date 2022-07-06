#ifndef OOP_Class421_CLASS8_H
#define OOP_Class421_CLASS8_H

#include "Class6.h"
#include "Class7.h"

namespace Class421
{
	class Class8: public Class6, public Class7
	{
			string name;
			int classId = 8;
		public:
			Class8(string);
	};
}


#endif //OOP_Class421_CLASS8_H
