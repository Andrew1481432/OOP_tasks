#ifndef OOP_CL_NODE4_33_H
#define OOP_CL_NODE4_33_H

#include "cl_base.h"

namespace class33
{
	class cl_node4 : public cl_base
	{
	public:
		const static int ID = 4;
		int getClassId();

		cl_node4(cl_base *p_parent = nullptr, string object_name = "Empty");
	};
}

#endif //OOP_CL_NODE4_33_H
