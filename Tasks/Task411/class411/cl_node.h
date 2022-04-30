#ifndef OOP_CL_NODE_H
#define OOP_CL_NODE_H
#include "cl_base.h"

class cl_node: public cl_base
{
	public:
		cl_node(cl_base *p_parent = nullptr, string object_name = "Empty");
};

#endif //OOP_CL_NODE_H
