#ifndef OOP_CL_NODE3_32_H
#define OOP_CL_NODE3_32_H

#include "cl_base.h"

namespace class32
{
	class cl_node3 : public cl_base
	{
	public:
		const static int ID = 3;
		cl_node3(cl_base *p_parent = nullptr, string object_name = "Empty");;
	};
}

#endif //OOP_CL_NODE3_32_H
