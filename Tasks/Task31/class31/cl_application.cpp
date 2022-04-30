#include "cl_application.h"
#include "cl_node2.h"
#include "cl_node3.h"
#include "cl_node4.h"
#include "cl_node5.h"
#include "cl_node6.h"

using namespace class31;

cl_application::cl_application(cl_base *p_parent): cl_base(p_parent)
{}

void cl_application::build_tree_objects()
{
	string headObjName; //Наименование головного объекта
	string nextObjName; //Наименование очередного объекта
	int id; // Номер класса принадлежности очередного объекта

	cin >> headObjName;
	this->set_object_name(headObjName);

	cl_base* headObj;
	cl_base* nextObj;
	do
	{
		cin >> headObjName;
		if (headObjName == "endtree") break;
		cin >> nextObjName >> id;

		headObj = get_child(headObjName);
		if (headObj == nullptr) {
			cerr << "Error::Head object not found!" << endl;
			return;
		}
		try {
			switch(id) {
				case cl_node2::ID:
					nextObj = new cl_node2();
					break;
				case cl_node3::ID:
					nextObj = new cl_node3();
					break;
				case cl_node4::ID:
					nextObj = new cl_node4();
					break;
				case cl_node5::ID:
					nextObj = new cl_node5();
					break;
				case cl_node6::ID:
					nextObj = new cl_node6();
					break;
				default:
					throw std::invalid_argument("getClassById dont found class with id "+ to_string(id));
			}
			nextObj->set_object_name(nextObjName);
			nextObj->set_parent(headObj);
		} catch (std::invalid_argument& e) {
			cerr << e.what() << endl;
			return;
		}
	}while(true);

	int idReady = 0;
	while(cin >> nextObjName >> idReady) {
		nextObj = get_child(nextObjName);
		if (nextObj == nullptr) {
			cout << "Error::Object not found!" << endl;
			return;
		} else {
			nextObj->setIdReady(idReady);
		}
	}
}

int cl_application::exec_app()
{
	cout << "Object tree" << endl;

	show_object_tree();
	cout << endl;

	cout << "The tree of objects and their readiness" << endl;
	show_object_tree(true);

	return EXIT_SUCCESS;
}