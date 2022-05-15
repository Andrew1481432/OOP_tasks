#include "cl_base.h"

using namespace class33;

cl_base::cl_base(cl_base *p_parent, string object_name)
{
	set_object_name(object_name);
	this->p_parent = p_parent;
	set_parent(p_parent);

	signalObj = [&](string &s) {
		s += " (class: "+std::to_string(getClassId())+")";
		cout << endl << "Signal from " << getAbsoluteDir();
	};
	handlerObj = [](cl_base* target, string &s) {
		cout << endl << "Signal to "<<target->getAbsoluteDir()<<" Text:  " << s;
	};
}

int cl_base::getClassId()
{
	return cl_base::ID;
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

void cl_base::setIdReady(int id) {
	if(id == 0)
	{
		if (children.size() > 0)
		{
			for (int i = 0; i < children.size(); i++)
			{
				cl_base *child = children[i];
				child->setIdReady(id);
			}
		}
		this->idReady = id;
	} else {
		bool flag = true;
		cl_base* parent = p_parent;
		while(parent != nullptr)
		{
			if(!parent->isReady())
			{
				flag = false;
				break;
			}
			parent = parent->p_parent;
		}
		if(flag)
		{
			this->idReady = id;
		}
	}
}

bool cl_base::isReady() {
	return this->idReady != 0;
}

void cl_base::setIdReadyAll(int id)
{
	if(id == 0) {
		this->idReady = id;
	} else {
		this->setIdReady(id);
	}
	if(children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			cl_base *child = children[i];
			child->setIdReadyAll(id);
		}
	}
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

string cl_base::getAbsoluteDir() {
	string resultDir = "";
	cl_base* parent = this;
	while(parent->p_parent != nullptr)
	{
		resultDir.insert(0, parent->get_object_name()+(!resultDir.empty() ?"/":""));
		parent = parent->p_parent;
	}
	return "/"+resultDir;
}

/**
 * Выдачи сигнала от текущего объекта с передачей строковой переменной.
 * Включенный объект может выдать или обработать сигнал.
 *
 * @param s_ignal передать указатель на метод сигнала
 * @param s_command строковую переменную
 */
void cl_base::emit_signal(std::function<void(string&)> s_ignal, string &s_command)
{
	void(*p_handler)(cl_base *p_ob, string &);

	//------------------------------------------------------------------
	if(connects.empty() || !isReady()) return;

	(s_ignal)(s_command);
	it_connects = connects.begin();
	while (it_connects != connects.end())
	{
		p_handler = (*it_connects)->p_handler;
		cl_base* clTarget = (*it_connects)->p_cl_base;
		if((*it_connects)->p_signal.target_type() == s_ignal.target_type())
		{
			if (clTarget->isReady())
			{
				(p_handler)(clTarget, s_command);
			}
		}
		it_connects++;
	}
}

/*
 Методу удаления (разрыва) связи передать:

 указатель на метод сигнала текущего объекта,
 указатель на целевой объект
 указатель на метод обработчика целевого объекта.
 */
void cl_base::delete_connect(std::function<void(string&)> s_ignal, cl_base *target)
{
	if(connects.empty()) return;
	it_connects = connects.begin();

	while (it_connects != connects.end())
	{
		if(s_ignal.target_type() == (*it_connects)->p_signal.target_type() && target == (*it_connects)->p_cl_base)
		{
			connects.erase(it_connects);
			return;
		}
		it_connects++;
	}
}


/**
 * Установления связи между сигналом текущего объекта и обработчиком целевого объекта;
 *
 * 	set_connect(SIGNAL_D(signal_to_ob_3), p_ob_3,
 *             HENDLER_D(p_ob_3->hendler_1));
 *
 * 	set_connect(
 *	((void (*) (string &)) (&(signal_to_ob_3)))
 *	,p_ob_3,
 *	((void(*)(cl_base *, string &))(&(p_ob_3->hendler_1)))
 *	);
 *
 * @param p_signal Указатель на метод сигнала
 * @param p_ob_handler указатель на целевой объект
 * @param p_handler указатель на метод обработчика целевого объекта
 */
void cl_base::set_connect(std::function<void(string&)> p_signal, cl_base *p_ob_handler,
                          void(*p_handler)(cl_base *p_pb, string &))
{
	//-------------------------------------------------------------------------
	// Цикл для исключения повторного установления связи
	if (connects.size() > 0) {
		it_connects = connects.begin();
		while (it_connects != connects.end()) {
			if(p_signal.target_type() == (*it_connects)->p_signal.target_type() &&
			   p_ob_handler == (*it_connects)->p_cl_base &&
			   p_handler == (*it_connects)->p_handler
					) {
				return;
			}
			it_connects++;
		}
	}

	c_handler *p_value = new c_handler();
	p_value->p_signal = p_signal;
	p_value->p_cl_base = p_ob_handler;
	p_value->p_handler = p_handler;
	connects.push_back(p_value);
}