#ifndef OOP_Class412_CLASS3_H
#define OOP_Class412_CLASS3_H

#include "Class2.h"

namespace Class412
{
	class Class3: protected Class2
	{
		protected:
			int classId = 3;
		public:
			Class3(string name, int par): Class2(name, par){}

			void show();
	};
}


#endif //OOP_Class412_CLASS3_H
