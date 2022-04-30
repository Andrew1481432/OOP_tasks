#include "cl_application.h"
#include "cl_node2.h"
#include "cl_node3.h"
#include "cl_node4.h"
#include "cl_node5.h"
#include "cl_node6.h"

using namespace class31;

cl_application::cl_application(cl_base *p_parent): cl_base(p_parent)
{
	/*classes[cl_node2::getId()] = []() { return new cl_node2();};
	classes[cl_node3::getId()] = []() { return new cl_node3();};
	classes[cl_node4::getId()] = []() { return new cl_node4();};
	classes[cl_node5::getId()] = []() { return new cl_node5();};
	classes[cl_node6::getId()] = []() { return new cl_node6();};*/
}

// потом описать алгоритм ready
cl_base* cl_application::getClassById(int id)
{
	switch(id) {
		case cl_node2::ID:
			return new cl_node2();
		case cl_node3::ID:
			return new cl_node3();
		case cl_node4::ID:
			return new cl_node4();
		case cl_node5::ID:
			return new cl_node5();
		case cl_node6::ID:
			return new cl_node6();
		default:
			throw std::invalid_argument("getClassById dont found class with id "+ to_string(id));
	}
}

/*cl_base* cl_application::getClassById(int id)
{
	if(classes.count(id)) {
		return classes[id]();
	} else {
		throw std::invalid_argument("getClassById dont found class with id "+ to_string(id));
	}
}*/

int cl_application::getId()
{
	return 1;
}

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
		//cout << "debug temp_p_parent name: " << temp_p_parent->get_object_name() << endl;
		try {
			nextObj = getClassById(id);
			nextObj->set_object_name(nextObjName);
			nextObj->set_parent(headObj);
		} catch (std::invalid_argument& e) {
			cerr << e.what() << endl;
			return;
		}
	}while(true);

	int idReady = 0;
	do
	{
		cin >> nextObjName >> idReady;
		if (std::cin.eof()) break;

		nextObj = get_child(nextObjName);
		if (nextObj == nullptr) {
			cerr << "Error::Object not found!" << endl;
			return;
		} else {
			nextObj->setIdReady(idReady);
		}
	}while(true);
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