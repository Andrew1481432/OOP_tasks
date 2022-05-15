#include "cl_application.h"
#include "cl_node2.h"
#include "cl_node3.h"
#include "cl_node4.h"
#include "cl_node5.h"
#include "cl_node6.h"

using namespace class33;

cl_application::cl_application(cl_base *p_parent): cl_base(p_parent)
{}

int cl_application::getClassId()
{
	return cl_application::ID;
}

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
			cout << "The head object "<<headObjDir<<" is not found";
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
}

void cl_application::createConnections()
{
	string absoluteDirSource;
	string absoluteDirTarget;

	cl_base* sourceObj;
	cl_base* targetObj;
	while(cin >> absoluteDirSource && absoluteDirSource != "end_of_connections") {
		sourceObj = this->get_object_by_path(absoluteDirSource);
		if (sourceObj == nullptr) {
			cout << endl << "Object "<<absoluteDirSource<<" not found";
			continue;
		}
		cin >> absoluteDirTarget;
		targetObj = this->get_object_by_path(absoluteDirTarget);
		if (targetObj == nullptr) {
			cout << endl << "Handler object "<<absoluteDirTarget<<" not found";
			continue;
		}
		sourceObj->set_connect(sourceObj->signalObj, targetObj, targetObj->handlerObj);
	}
}


void cl_application::executeCmds()
{
	string cmd;
	cl_base* sourceObj;
	cl_base* targetObj;
	while(cin >> cmd && cmd != "END") {
		if(cmd == "EMIT") { // выдать сигнал от заданного по координате объекта
			/** координата объекта, текст**/
			string dirObj, msg;
			cin >> dirObj;
			getline(cin, msg);
			msg.erase(0,1);

			sourceObj = this->get_object_by_path(dirObj);
			if (sourceObj == nullptr) {
				cout << endl << "Object "<<dirObj<<" not found";
				continue;
			}
			sourceObj->emit_signal(sourceObj->signalObj,msg);
		} else if(cmd == "DELETE_CONNECT" || cmd == "SET_CONNECT") { // удаление связи, установка связи
			string absoluteDirSource, absoluteDirTarget;
			cin >> absoluteDirSource;
			sourceObj = this->get_object_by_path(absoluteDirSource);
			if (sourceObj == nullptr) {
				cout << endl << "Object "<<absoluteDirSource<<" not found";
				continue;
			}
			cin >> absoluteDirTarget;
			targetObj = this->get_object_by_path(absoluteDirTarget);
			if (targetObj == nullptr) {
				cout << endl <<"Handler object "<<absoluteDirTarget<<" not found";
				continue;
			}
			if(cmd == "SET_CONNECT") {
				sourceObj->set_connect(sourceObj->signalObj, targetObj, targetObj->handlerObj);
			} else {
				sourceObj->delete_connect(sourceObj->signalObj, targetObj);
			}
		} else if(cmd == "SET_CONDITION") { // установка состояния объекта
			string dirObj;
			cin >> dirObj;
			int idReady;
			cin >> idReady;
			sourceObj = this->get_object_by_path(dirObj);
			if (sourceObj == nullptr) {
				cout << endl << "Object "<<dirObj<<" not found";
				continue;
			}
			sourceObj->setIdReady(idReady);
		} else {
			cout << endl << "Error::CMD " << cmd << " not found!";
			return;
		}
	}
}

int cl_application::exec_app()
{
	/*string test;
	while(getline(cin, test)) {
		cout << test << endl;
	}*/
	cout << "Object tree" << endl;
	show_object_tree();
	createConnections();
	this->setIdReadyAll(1);
	executeCmds();

	return EXIT_SUCCESS;
}