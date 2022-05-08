#include "cl_node2.h"

using namespace class33;

cl_node2::cl_node2(cl_base *p_parent, string object_name): cl_base(p_parent, object_name)
{}

int cl_node2::getClassId()
{
	return cl_node2::ID;
}