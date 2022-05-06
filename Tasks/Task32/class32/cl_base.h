#ifndef OOP_CL_BASE_32_H
#define OOP_CL_BASE_32_H

#include <string>
#include <vector>
#include <iostream>

#include <sstream>

using namespace std;

namespace class32
{
	class cl_base
	{
	private:
		string object_name;
		cl_base *p_parent; // ссылка на головной обьект

		void show_object_next(cl_base *, int);
		vector<string> split(const string&, char);
	protected:
		ostringstream cmds;
	public:
		const static int ID = 0;
		vector<cl_base *> children; // ссылка на потомков
		vector<cl_base *>::iterator it_child;

		cl_base(cl_base *p_parent = nullptr, string object_name = "Empty");

		void set_object_name(string object_name);

		string get_object_name();

		void set_parent(cl_base *p_parent);
		void add_child(cl_base *p_child);
		cl_base *get_child(string object_name);
		cl_base *get_child_local(string object_name);
		void delete_child(string object_name);
		cl_base* get_object_by_path(string);
		void showCmds();

		// region вывод дерева иерархии обьектов
		void show_object_tree();
		// endregion
	};
}

#endif //OOP_CL_BASE_32_H
