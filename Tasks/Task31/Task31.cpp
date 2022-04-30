#include "Task31.h"

std::string Task31::getName()
{
	return "КЛ_3_1";
}

int Task31::getId()
{
	return 31;
}

int Task31::execute()
{
	cl_application ob_cl_application(nullptr);
	ob_cl_application.build_tree_objects(); // построение дерева объектов
	return ob_cl_application.exec_app(); // запуск системы
}