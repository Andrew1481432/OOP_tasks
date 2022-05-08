#ifndef OOP_CL_NODE6_33_H
#define OOP_CL_NODE6_33_H

#include "cl_base.h"

namespace class33
{
	class cl_node6 : public cl_base
	{
	public:
		const static int ID = 6;
		int getClassId();

		cl_node6(cl_base *p_parent = nullptr, string object_name = "Empty");
	};
}

#endif //OOP_CL_NODE6_33_H
