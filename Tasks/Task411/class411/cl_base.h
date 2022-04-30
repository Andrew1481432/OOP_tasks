#ifndef OOP_CL_BASE_H
#define OOP_CL_BASE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class cl_base
{
	private:
		string object_name;
		cl_base *p_parent; // ссылка на головной обьект
	public:
		vector<cl_base*> children; // ссылка на потомков
		vector<cl_base*>::iterator it_child;

		cl_base(cl_base *p_parent = nullptr, string object_name = "Empty");

		void set_object_name(string object_name);
		string get_object_name();

		void set_parent(cl_base *p_parent); //Set_Root_Ptr
		void add_child(cl_base *p_child); //Add_To_Slave
		cl_base* get_child(string object_name); //Find_Object_By_Name
		void delete_child(string object_name); //Remove_From_Slave

		// region вывод дерева иерархии обьектов
		void show_object_tree();
		// endregion
};

#endif //OOP_CL_BASE_H
