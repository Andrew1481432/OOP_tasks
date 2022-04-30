#ifndef OOP_Class412_CLASS4_H
#define OOP_Class412_CLASS4_H

#include "Class3.h"

namespace Class412
{
	class Class4: protected Class3
	{
		protected:
			int classId = 4;
		public:
			Class4(string name, int par): Class3(name, par){};

			void show();
	};
}


#endif //OOP_Class412_CLASS4_H
