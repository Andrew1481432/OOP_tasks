#ifndef OOP_CL_NODE5_33_H
#define OOP_CL_NODE5_33_H

#include "cl_base.h"

namespace class33
{
	class cl_node5 : public cl_base
	{
	public:
		const static int ID = 5;
		int getClassId();

		cl_node5(cl_base *p_parent = nullptr, string object_name = "Empty");;
	};
}

#endif //OOP_CL_NODE5_33_H
