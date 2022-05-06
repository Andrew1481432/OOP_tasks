#include "cl_base.h"

using namespace class32;

cl_base::cl_base(cl_base *p_parent, string object_name)
{
	set_object_name(object_name);
	this->p_parent = p_parent;
	set_parent(p_parent);
}

vector<string> cl_base::split(const string &s, char delim)
{
	vector<string> res;
	string item;
	for (auto &sym: s)
	{
		if (delim == sym)
		{
			if (!item.empty())
			{
				res.push_back(item);
				item.clear();
			}
		}
		else
		{
			item.push_back(sym);
		}
	}
	if (!item.empty())
	{
		res.push_back(item);
		item.clear();
	}
	return res;
}

void cl_base::set_object_name(string object_name)
{
	this->object_name = object_name;
}

string cl_base::get_object_name()
{
	return this->object_name;
}

void cl_base::set_parent(cl_base *parent)
{
	if(parent != nullptr)
	{
		this->p_parent = parent;
		p_parent->add_child(this);
	}
}

void cl_base::add_child(cl_base *p_child)
{
	if(p_child != nullptr)
	{
		children.push_back(p_child);
	}
}

cl_base* cl_base::get_child(string object_name)
{
	cl_base *resultObj;
	if(this->object_name==object_name) return this;
	if(children.size() == 0) return nullptr;
	it_child = children.begin();
	while(it_child != children.end())
	{
		resultObj = (*it_child)->get_child(object_name);
		if(resultObj != nullptr) return resultObj;
		it_child++;
	}
	return nullptr;
}

cl_base* cl_base::get_child_local(string object_name)
{
	if(this->object_name==object_name) return this;
	if(children.size() == 0) return nullptr;
	it_child = children.begin();
	while(it_child != children.end())
	{
		if((*it_child)->get_object_name() == object_name)
		{
			return (*it_child);
		}
		it_child++;
	}
	return nullptr;
}

void cl_base::delete_child(string object_name)
{
	cl_base *p_child = this->get_child(object_name);
	if(p_child != nullptr)
	{
		children.erase(it_child);
	}
}

// region вывод дерева иерархии обьектов

void cl_base::show_object_tree()
{
	int i_level = 0;
	show_object_next(this, i_level);
}

void cl_base::show_object_next(cl_base *ob_parent, int i_level)
{
	string s_space;

	if (i_level > 0)
	{
		cout << endl;
		s_space.append(4 * i_level, ' '); // табуляция
	}
	cout << s_space << ob_parent->get_object_name();
	if (ob_parent->children.size() == 0) return;

	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end())
	{
		show_object_next((cl_base *) (*(ob_parent->it_child)), i_level + 1); // рекурсивная функция :))
		ob_parent->it_child++;
	}
}
// endregion

cl_base *cl_base::get_object_by_path(string object_path)
{
	cl_base *p_parent_next = this; // указатель на очередной головной объект
	cl_base *p_child;       // указатель на очередной подчиненный объект
	//------------------------------------------------------------------
	if (object_path == "." || object_path == "/")
	{
		return this;
	}
	else if (object_path.substr(0, 2) == "//")
	{
		return get_child(object_path.substr(2));
	}
	else
	{
		vector<string> dirObjects = this->split(object_path, '/');
		for (auto &obj: dirObjects)
		{
			p_child = p_parent_next->get_child_local(obj);
			if (p_child)
			{
				p_parent_next = p_child;
			}
			else
			{
				return nullptr;
			}
		}
	}
	return p_parent_next;
}

void cl_base::showCmds()
{
	cout << cmds.str();
}
