#include "cl_node3.h"

using namespace class33;

cl_node3::cl_node3(cl_base *p_parent, string object_name): cl_base(p_parent, object_name)
{}

int cl_node3::getClassId()
{
	return cl_node3::ID;
}