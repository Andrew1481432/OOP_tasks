#include "cl_application.h"
#include "cl_node.h"

cl_application::cl_application(cl_base *p_parent): cl_base(p_parent)
{}

void cl_application::build_tree_objects()
{
	string tempParentName;
	string tempObjName;

	cl_base* temp_p_parent;
	cin >> tempParentName;

	this->set_object_name(tempParentName);
	do
	{
		cin >> tempParentName >> tempObjName;
		if(tempParentName == tempObjName) break;

		temp_p_parent = get_child(tempParentName);
		//cout << "debug temp_p_parent name: " << temp_p_parent->get_object_name() << endl;
		if(temp_p_parent!=nullptr)
		{
			new cl_node(temp_p_parent, tempObjName);
		}
	}while(true);
}

int cl_application::exec_app()
{
	show_object_tree();
	return EXIT_SUCCESS;
}