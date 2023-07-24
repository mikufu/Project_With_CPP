#pragma once
#include "workermanagement.h"

#define FILENAME "WorkerManager.txt"
#define NULL 0

WorkerManage::WorkerManage()
{
	if (m_FileisEmpty())
	{
		return;
	}
	else
	{
		int ID;
		string name;
		int dID;
		ifstream ifs;
		ifs.open(FILENAME, ios::in);
		while (ifs >> ID && ifs >> name && ifs >> dID)
		{
			switch (dID)
			{
			case 1:
				wlist.push_back(new Employee(ID, name, dID));
				break;
			case 2:
				wlist.push_back(new Manager(ID, name, dID));
				break;
			case 3:
				wlist.push_back(new Boss(ID, name, dID));
				break;
			default:
				break;
			}
		}
	}
}

void WorkerManage::showmenu()
{
	cout << "******************************" << endl;
	cout << "***  欢迎使用职工管理系统  ***" << endl;
	cout << "***     0.退出管理系统     ***" << endl;
	cout << "***     1.增加职工信息     ***" << endl;
	cout << "***     2.显示职工信息     ***" << endl;
	cout << "***     3.删除离职职工     ***" << endl;
	cout << "***     4.修改职工信息     ***" << endl;
	cout << "***     5.查找职工信息     ***" << endl;
	cout << "***     6.按照编号排序     ***" << endl;
	cout << "***     7.清空所有文档     ***" << endl;
	cout << "******************************" << endl;
}

bool WorkerManage::m_FileisEmpty()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		ifs.close();
		return true;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		ifs.close();
		return true;
	}
	ifs.close();
	return false;
}

bool WorkerManage::is_repete(int ID)
{
	list<Worker*>::iterator p1 = wlist.begin();
	list<Worker*>::iterator tail = wlist.end();
	while (p1 != tail)
	{
		if ((*p1)->m_ID == ID)
			return true;
		p1++;
	}
	return false;
}

void WorkerManage::Add_Emp()
{
	int ID = 0;
	cout << "请输入新增职工的编号:> ";
	while (true)
	{
		while (!(cin >> ID))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		if (!is_repete(ID))
			break;
		else
			cout << "职工编号重复，请重新输入职工编号:> ";
	}
	cin.clear();		//清除多输入的字符
	while (cin.get() != '\n')
		;

	string name;

	cout << "请输入职工的姓名:> ";
	cin >> name;

	Worker* newnode = NULL;
	while (true)
	{
		int dID = 0;
		cout << "1. 员工\n2. 经理\n3. 老板" << endl;
		cout << "请输入新增职工的职位:> ";
		while (!(cin >> dID))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		switch (dID)
		{
		case 1:
			newnode = new Employee(ID, name, dID);
			break;
		case 2:
			newnode = new Manager(ID, name, dID);
			break;
		case 3:
			newnode = new Boss(ID, name, dID);
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		if (dID == 1 || dID == 2 || dID == 3)
			break;
	}

	wlist.push_back(newnode);
	cout << "添加成功!" << endl;

	system("pause");
	system("cls");

}

void WorkerManage::save()
{
	list<Worker*>::iterator p1 = wlist.begin();
	list<Worker*>::iterator tail = wlist.end();
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	while (p1 != tail)
	{
		ofs << (*p1)->m_ID << " "
			<< (*p1)->m_name << " "
			<< (*p1)->m_dID << endl;
		p1++;
	}
	ofs.close();
}

void WorkerManage::showInfo()
{
	if (wlist.empty())
	{
		cout << "暂无职工信息!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "职工信息如下:" << endl;
	list<Worker*>::iterator p1 = wlist.begin();
	list<Worker*>::iterator tail = wlist.end();
	while (p1 != tail)
	{
		(*p1)->ShowInfo();
		p1++;
	}
	system("pause");
	system("cls");
}

list<Worker*>::iterator WorkerManage::Find()
{
	while (true)
	{
		cout << "1. 按职工编号查找\n2. 按职工姓名查找" << endl;
		cout << "请选择查找方式:> ";
		int choice = 0;
		while (!(cin >> choice))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		if (choice == 1)
		{
			int ID;
			cout << "请输入需要查找职工的编号:> ";
			while (!(cin >> ID))	//防止输入格式错误
			{
				cout << "输入错误，请重新输入!" << endl;
				cin.clear();
				while (cin.get() != '\n')
					;
			}
			cin.clear();		//清除多输入的字符
			while (cin.get() != '\n')
				;

			int flag = 0;
			list<Worker*>::iterator p1 = wlist.begin();
			list<Worker*>::iterator tail = wlist.end();
			while (p1 != tail)
			{
				if ((*p1)->m_ID == ID)
				{
					flag = 1;
					break;
				}
				p1++;
			}
			if (flag)
				return p1;
			else
				return tail;
		}

		if (choice == 2)
		{
			string name;
			cout << "请输入要查找职工的姓名:> ";
			cin >> name;

			int count = 0;
			list<Worker*>::iterator p1 = wlist.begin();
			list<Worker*>::iterator tail = wlist.end();
			while (p1 != tail)
			{
				if ((*p1)->m_name == name)
				{
					count++;
					(*p1)->ShowInfo();
				}
				p1++;
			}
			if (count)
			{
				cout << "共找到" << count << "个职工" << endl;
				cout << "请输入需要查找的职工的编号:> ";
				int ID = 0;
				while (!(cin >> ID))	//防止输入格式错误
				{
					cout << "输入错误，请重新输入!" << endl;
					cin.clear();
					while (cin.get() != '\n')
						;
				}
				cin.clear();		//清除多输入的字符
				while (cin.get() != '\n')
					;

				int flag = 0;
				list<Worker*>::iterator p1 = wlist.begin();
				list<Worker*>::iterator tail = wlist.end();
				while (p1 != tail)
				{
					if ((*p1)->m_ID == ID)
					{
						flag = 1;
						break;
					}
					p1++;
				}
				if (flag)
					return p1;
				else
					return tail;
			}
			else
				return tail;
		}
		cout << "输入指令有误，请重新输入!" << endl;
	}
}

void WorkerManage::del_Emp()
{
	cout << "请查找需要删除的职工信息" << endl;
	list<Worker*>::iterator target = Find();

	if (target != wlist.end())
	{
		delete (*target);
		wlist.remove((*target));
		cout << "删除成功" << endl;
	}
	else
		cout << "未找到该职工" << endl;

	system("pause");
	system("cls");
}

void WorkerManage::modify()
{
	cout << "请查找需要修改的职工信息" << endl;
	list<Worker*>::iterator target = Find();
	if (target == wlist.end())
	{
		cout << "未找到该职工" << endl;
		system("pause");
		system("cls");
		return;
	}
	(*target)->ShowInfo();

	int ID = 0;
	cout << "请输入修改后职工的编号:> ";
	while (true)
	{
		while (!(cin >> ID))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		if (!is_repete(ID))
			break;
		else
			cout << "职工编号重复，请重新输入:> ";
	}

	string name;
	cout << "请输入修改后职工的姓名:> ";
	cin >> name;

	Worker* newnode = NULL;
	while (true)
	{
		int dID = 0;
		cout << "1. 员工\n2. 经理\n3. 老板" << endl;
		cout << "请输入修改后职工的职位:> ";
		while (!(cin >> dID))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		switch (dID)
		{
		case 1:
			newnode = new Employee(ID, name, dID);
			break;
		case 2:
			newnode = new Manager(ID, name, dID);
			break;
		case 3:
			newnode = new Boss(ID, name, dID);
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		if (dID == 1 || dID == 2 || dID == 3)
			break;
	}

	wlist.insert(target, newnode);
	wlist.remove(*target);
	cout << "添加成功!" << endl;

	system("pause");
	system("cls");
}

void WorkerManage::search_Emp()
{
	list<Worker*>::iterator target = Find();
	if (target == wlist.end())
	{
		cout << "未找到该职工" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "找到了该职工，该职工信息为:" << endl;
		(*target)->ShowInfo();
		system("pause");
		system("cls");
	}
}

bool compare(const Worker* first, const Worker* second)
{
	return first->m_ID < second->m_ID;
}

void WorkerManage::sort_Emp()
{
	if (wlist.empty())
	{
		cout << "没有职工信息，无法排序" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "1. 按编号升序\n2. 按编号降序" << endl;
	cout << "请选择排序方式:> ";
	while (true)
	{
		int choice = 0;
		while (!(cin >> choice))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		if (choice == 1)
		{
			wlist.sort(compare);
			break;
		}
		else if (choice == 2)
		{
			wlist.sort(compare);
			wlist.reverse();
			break;
		}
		else
			cout << "错误指令，请重新输入:> ";
	}
	system("pause");
	system("cls");
}

void WorkerManage::clear_File()
{
	while (true)
	{
		cout << "1. 确认\n2. 返回\n请确认是否清空?:> ";
		int choice = 0;
		while (!(cin >> choice))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;


		if (choice == 1)
		{
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);
			ofs.close();
			list<Worker*>::iterator it = wlist.begin();
			list<Worker*>::iterator tail = wlist.end();
			while (it != tail)
			{
				delete (*it);
				it++;
			}
			wlist.clear();
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (choice == 2)
		{
			cout << "按任意键返回" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "选择错误，请重新选择!" << endl;
		}
	}
}

WorkerManage::~WorkerManage()
{
	list<Worker*>::iterator it = wlist.begin();
	list<Worker*>::iterator tail = wlist.end();
	while (it != tail)
	{
		delete (*it);
		it++;
	}
	wlist.clear();
}