#ifndef OOP_CL_APPLICATION_31_H
#define OOP_CL_APPLICATION_31_H

#include <map>
#include "cl_base.h"

namespace class31
{
	//using MapType = std::function<cl_base*()>;

class cl_application : public cl_base
{
	    //std::map<int, MapType> classes;
        cl_base* getClassById(int);
	public:
		const static int ID = 1;
		cl_application(cl_base *p_parent);

		void build_tree_objects();

		int exec_app();

		static int getId();
	};
}


#endif //OOP_CL_APPLICATION_31_H
