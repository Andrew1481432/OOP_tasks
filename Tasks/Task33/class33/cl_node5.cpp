#include "cl_node5.h"

using namespace class33;

cl_node5::cl_node5(cl_base *p_parent, string object_name): cl_base(p_parent, object_name)
{}

int cl_node5::getClassId()
{
	return cl_node5::ID;
}