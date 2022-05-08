#include "cl_node4.h"

using namespace class33;

cl_node4::cl_node4(cl_base *p_parent, string object_name): cl_base(p_parent, object_name)
{}

int cl_node4::getClassId()
{
	return cl_node4::ID;
}