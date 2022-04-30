#include "Task411.h"
#include "class411/cl_application.h"

std::string Task411::getName()
{
	return "Занятие № 4_1_1";
}

int Task411::getId()
{
	return 411;
}

/*

 */
int Task411::execute()
{
	cl_application ob_cl_application(nullptr);
	ob_cl_application.build_tree_objects(); // построение дерева объектов
	return ob_cl_application.exec_app(); // запуск системы
}