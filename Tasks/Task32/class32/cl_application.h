#ifndef OOP_CL_APPLICATION_32_H
#define OOP_CL_APPLICATION_32_H

#include <map>
#include "cl_base.h"

namespace class32
{
class cl_application: public cl_base
{
	public:
		const static int ID = 1;

		cl_application(cl_base *p_parent);

		void build_tree_objects();

		int exec_app();
	};
}


#endif //OOP_CL_APPLICATION_32_H
