#include "cl_base.h"

cl_base::cl_base(cl_base *p_parent, string object_name)
{
	set_object_name(object_name);
	this->p_parent = p_parent;
	set_parent(p_parent);
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

/*

 void cl_base::show_object_tree()
{
	int i_level = 0;
	show_object_next(this, i_level);
}

void cl_base::show_object_next(cl_base *ob_parent, int i_level)
{

	string s_space;

	if(i_level > 0)
	{
		cout << endl;
		s_space.append(4 * i_level, ' '); // табуляция
	}
	cout << s_space << ob_parent->get_object_name();
	if(ob_parent->children.size() == 0) return;

	ob_parent->it_child = ob_parent->children.begin();
	while(ob_parent->it_child != ob_parent->children.end())
	{
		show_object_next((cl_base*)(*(ob_parent->it_child)), i_level+1); // рекурсивная функция :))
		ob_parent->it_child++;
	}
*/

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

void cl_base::delete_child(string object_name)
{
	cl_base *p_child = this->get_child(object_name);
	if(p_child != nullptr)
	{
		//p_child->p_parent->children
		children.erase(it_child);
	}
}

// region вывод дерева иерархии обьектов
void cl_base::show_object_tree()
{
	if(p_parent==nullptr)
	{
		cout<<object_name;
	}
	if(children.size()>0)
	{
		cout<<endl<<object_name;
		for(int i=0;i < children.size(); i++)
		{
			cl_base *child = children[i];
			cout<<"  "<<child->get_object_name();
		}
		for(int i=0;i<children.size();i++)
		{
			cl_base *child = children[i];
			child->show_object_tree();
		}
	}
}
// endregion