#ifndef OOP_CL_NODE2_32_H
#define OOP_CL_NODE2_32_H

#include "cl_base.h"

namespace class32
{
	class cl_node2 : public cl_base
	{
	public:
		const static int ID = 2;
		cl_node2(cl_base *p_parent = nullptr, string object_name = "Empty");
	};
}

#endif //OOP_CL_NODE2_32_H
