#include "Task33.h"

#include "class33/cl_base.h"


std::string Task33::getName()
{
	return "КЛ_3_3";
}

int Task33::getId()
{
	return 33;
}

int Task33::execute()
{
	cl_application ob_cl_application(nullptr);
	ob_cl_application.build_tree_objects(); // построение дерева объектов
	return ob_cl_application.exec_app(); // запуск системы
}