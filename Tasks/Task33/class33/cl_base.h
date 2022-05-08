#ifndef OOP_CL_BASE_33_H
#define OOP_CL_BASE_33_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <functional>

using namespace std;

namespace class33
{
	class cl_base
	{
		bool idReady;

		struct c_handler {
			cl_base *p_cl_base;
			void(*p_handler)(cl_base *p_ob, string &);
		};

		std::vector<c_handler*> connects;
		std::vector<c_handler*>::iterator it_connects;

		string object_name;
		cl_base *p_parent; // ссылка на головной обьект

		void show_object_next(cl_base *, int);
		vector<string> split(const string&, char);
	public:
		// region ID
		const static int ID = 0;
		virtual int getClassId();
		// endregion

		vector<cl_base *> children; // ссылка на потомков
		vector<cl_base *>::iterator it_child;

		// region connections
		void set_connect(cl_base *, void(*)(cl_base *, string &));
		void emit_signal(std::function<void(string&)>, string &);
		void delete_connect(cl_base *);
		// endregion

		cl_base(cl_base *p_parent = nullptr, string object_name = "Empty");

		void set_object_name(string object_name);

		string get_object_name();

		void set_parent(cl_base *p_parent);
		void add_child(cl_base *p_child);
		cl_base *get_child(string object_name);
		cl_base *get_child_local(string object_name);
		void delete_child(string object_name);
		cl_base* get_object_by_path(string);

		// region ready status
		void setIdReady(int);
		void setIdReadyAll(int);
		bool isReady();
		// endregion

		string getAbsoluteDir();

		// region вывод дерева иерархии обьектов
		void show_object_tree();
		// endregion
	};
}

#endif //OOP_CL_BASE_33_H
