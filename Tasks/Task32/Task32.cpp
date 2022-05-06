#include "Task32.h"

#include "class32/cl_base.h"


std::string Task32::getName()
{
	return "КЛ_3_2";
}

int Task32::getId()
{
	return 32;
}


/**

Иметь возможность доступа из текущего объекта к любому объекту системы,
 «мечта» разработчика программы.
В составе базового класса реализовать метод получения указателя
 на любой объект в составе дерева иерархии объектов согласно пути (координаты).
 В качестве параметра методу передать путь (координату) объекта. Координата задается
 в следующем виде:


 */
int Task32::execute()
{
	cl_application ob_cl_application(nullptr);
	ob_cl_application.build_tree_objects(); // построение дерева объектов
	return ob_cl_application.exec_app(); // запуск системы
}