#ifndef OOP_CL_NODE3_33_H
#define OOP_CL_NODE3_33_H

#include "cl_base.h"

namespace class33
{
	class cl_node3 : public cl_base
	{
	public:
		const static int ID = 3;
		int getClassId();

		cl_node3(cl_base *p_parent = nullptr, string object_name = "Empty");;
	};
}

#endif //OOP_CL_NODE3_33_H
