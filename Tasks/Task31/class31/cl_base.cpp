#include "cl_base.h"

using namespace class31;

cl_base::cl_base(cl_base *p_parent, string object_name)
{
	set_object_name(object_name);
	set_parent(p_parent);
}

//Готовность для каждого объекта устанавливается индивидуально.
//которое присваивается свойству состояния объекта.



void cl_base::setIdReady(int id) {
	if(id == 0) //Готовность задается посредством любого отличного от нуля целого числового значени
	{
//		if (children.size() > 0)
//		{
//			for (int i = 0; i < children.size(); i++) //При отключении головного, отключаются все объекты от него по иерархии вниз по ветке
//			{
//				//Свойству состояния объекта присваивается значение нуль.
//				cl_base *child = children[i];
//
//				//При отключении головного, отключаются все объекты от него по иерархии вниз по ветке.
//				//Свойству состояния объекта присваивается значение нуль.
//				child->idReady = id;
//				//child->setIdReady(id);
//			}
//		}
//		this->idReady = id;
	} else {
		//bool flag = true;
		//cl_base* parent = p_parent;
		if (p_parent != nullptr && p_parent->isReady())
		{
			this->idReady = id;
		}
//		while(parent != nullptr)
//		{
//			cout << parent->get_object_name() << endl;
//			if(!parent->isReady()) // Объект переводится в состояние готовности, если все объекты вверх по иерархии до корневого включены
//			{
//				flag = false;
//				break;
//			}
//			parent = parent->p_parent;
//		}
//		if(flag) //иначе установка готовности игнорируется.
//		{
//			this->idReady = id;
//		}
	}
}

bool cl_base::isReady() {
	return this->idReady != 0;
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
	this->p_parent = parent;
	if(parent != nullptr)
	{
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

void cl_base::delete_child(string object_name)
{
	cl_base *p_child = this->get_child(object_name);
	if(p_child != nullptr)
	{
		children.erase(it_child);
	}
}

// region вывод дерева иерархии обьектов

void cl_base::show_object_tree(bool isShowReady)
{
	int i_level = 0;
	show_object_next(this, i_level, isShowReady);
}

void cl_base::show_object_next(cl_base *ob_parent, int i_level, bool isShowReady)
{
	string s_space;

	if (i_level > 0)
	{
		cout << endl;
		s_space.append(4 * i_level, ' '); // табуляция
	}
	cout << s_space << ob_parent->get_object_name();
	if(isShowReady) {
		cout << " is "<< (!ob_parent->isReady() ? "not " : "") << "ready";
	}
	if (ob_parent->children.size() == 0) return;

	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end())
	{
		show_object_next((cl_base *) (*(ob_parent->it_child)), i_level + 1, isShowReady); // рекурсивная функция :))
		ob_parent->it_child++;
	}
}

/*void cl_base::show_object_tree()
//{
//	if(p_parent==nullptr)
//	{
//		cout<<object_name;
//	}
//	if(children.size()>0)
//	{
//		cout<<endl<<object_name;
//		for(int i=0;i < children.size(); i++)
//		{
//			cl_base *child = children[i];
//			cout<<"  "<<child->get_object_name();
//		}
//		for(int i=0;i<children.size();i++)
//		{
//			cl_base *child = children[i];
//			child->show_object_tree();
//		}
//	}
 }*/

// endregion