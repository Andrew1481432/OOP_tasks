#ifndef OOP_CL_APPLICATION_33_H
#define OOP_CL_APPLICATION_33_H

#include <map>
#include "cl_base.h"

namespace class33
{
class cl_application: public cl_base
{
	void createConnections();
	void executeCmds();
	public:
		const static int ID = 1;
		int getClassId();

		cl_application(cl_base *p_parent);
		void build_tree_objects();
		int exec_app();
	};
}


#endif //OOP_CL_APPLICATION_33_H
