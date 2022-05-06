#include "cl_application.h"
#include "cl_node2.h"
#include "cl_node3.h"
#include "cl_node4.h"
#include "cl_node5.h"
#include "cl_node6.h"

using namespace class32;

cl_application::cl_application(cl_base *p_parent): cl_base(p_parent)
{}

void cl_application::build_tree_objects()
{
	string headObjName; //Наименование головного объекта
	string headObjDir; //абсолютный путь к головному обьекту

	string nextObjName; //Наименование очередного объекта
	int id; // Номер класса принадлежности очередного объекта

	cin >> headObjName;
	this->set_object_name(headObjName);

	cl_base* headObj;
	cl_base* nextObj;
	while(cin >> headObjDir && headObjDir != "endtree") {
		cin >> nextObjName >> id;

		headObj = this->get_object_by_path(headObjDir); // абсолютный путь к обьекту
		if (headObj == nullptr) {
			cmds << "The head object "<<headObjDir<<" is not found";
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
	}

	string cmd;
	headObjDir = "";
	cl_base* headObjSet = nullptr;
	while(cin >> cmd && cmd != "END") {
		cin >> headObjDir;
		if(cmds.tellp() != 0) {
			cmds << endl;
		}

		if((!headObjDir.empty() && headObjDir[0] == '/') || headObjSet == nullptr) {
			headObj = this; // абсолютная координата от корневого объекта.
		} else {
			headObj = headObjSet; // относительная координата от текущего объекта
		}

		if(cmd == "SET") {
			cl_base* headTempObj = headObj->get_object_by_path(headObjDir);
			if(headTempObj != nullptr) {
				cmds << "Object is set: " << headTempObj->get_object_name();
				headObjSet = headTempObj;
			} else {
				cmds << "Object is not found: " << headObj->get_object_name() << " " << headObjDir;
			}
		} else if(cmd == "FIND") {
			nextObj = headObj->get_object_by_path(headObjDir);
			cmds << headObjDir<<std::string(5, ' ')<< "Object "<<(nextObj!=nullptr ?"name: "+nextObj->get_object_name():"is not found");
		} else {
			cmds << "Error::CMD " << cmd << " not found!";
			return;
		}
	}
}

int cl_application::exec_app()
{
	cout << "Object tree" << endl;
	show_object_tree();
	cout << endl;
    showCmds();

	return EXIT_SUCCESS;
}