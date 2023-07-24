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
	cout << "***  ��ӭʹ��ְ������ϵͳ  ***" << endl;
	cout << "***     0.�˳�����ϵͳ     ***" << endl;
	cout << "***     1.����ְ����Ϣ     ***" << endl;
	cout << "***     2.��ʾְ����Ϣ     ***" << endl;
	cout << "***     3.ɾ����ְְ��     ***" << endl;
	cout << "***     4.�޸�ְ����Ϣ     ***" << endl;
	cout << "***     5.����ְ����Ϣ     ***" << endl;
	cout << "***     6.���ձ������     ***" << endl;
	cout << "***     7.��������ĵ�     ***" << endl;
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
	cout << "����������ְ���ı��:> ";
	while (true)
	{
		while (!(cin >> ID))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		if (!is_repete(ID))
			break;
		else
			cout << "ְ������ظ�������������ְ�����:> ";
	}
	cin.clear();		//�����������ַ�
	while (cin.get() != '\n')
		;

	string name;

	cout << "������ְ��������:> ";
	cin >> name;

	Worker* newnode = NULL;
	while (true)
	{
		int dID = 0;
		cout << "1. Ա��\n2. ����\n3. �ϰ�" << endl;
		cout << "����������ְ����ְλ:> ";
		while (!(cin >> dID))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
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
			cout << "����������������룡" << endl;
			break;
		}
		if (dID == 1 || dID == 2 || dID == 3)
			break;
	}

	wlist.push_back(newnode);
	cout << "��ӳɹ�!" << endl;

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
		cout << "����ְ����Ϣ!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "ְ����Ϣ����:" << endl;
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
		cout << "1. ��ְ����Ų���\n2. ��ְ����������" << endl;
		cout << "��ѡ����ҷ�ʽ:> ";
		int choice = 0;
		while (!(cin >> choice))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
		while (cin.get() != '\n')
			;

		if (choice == 1)
		{
			int ID;
			cout << "��������Ҫ����ְ���ı��:> ";
			while (!(cin >> ID))	//��ֹ�����ʽ����
			{
				cout << "�����������������!" << endl;
				cin.clear();
				while (cin.get() != '\n')
					;
			}
			cin.clear();		//�����������ַ�
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
			cout << "������Ҫ����ְ��������:> ";
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
				cout << "���ҵ�" << count << "��ְ��" << endl;
				cout << "��������Ҫ���ҵ�ְ���ı��:> ";
				int ID = 0;
				while (!(cin >> ID))	//��ֹ�����ʽ����
				{
					cout << "�����������������!" << endl;
					cin.clear();
					while (cin.get() != '\n')
						;
				}
				cin.clear();		//�����������ַ�
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
		cout << "����ָ����������������!" << endl;
	}
}

void WorkerManage::del_Emp()
{
	cout << "�������Ҫɾ����ְ����Ϣ" << endl;
	list<Worker*>::iterator target = Find();

	if (target != wlist.end())
	{
		delete (*target);
		wlist.remove((*target));
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "δ�ҵ���ְ��" << endl;

	system("pause");
	system("cls");
}

void WorkerManage::modify()
{
	cout << "�������Ҫ�޸ĵ�ְ����Ϣ" << endl;
	list<Worker*>::iterator target = Find();
	if (target == wlist.end())
	{
		cout << "δ�ҵ���ְ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	(*target)->ShowInfo();

	int ID = 0;
	cout << "�������޸ĺ�ְ���ı��:> ";
	while (true)
	{
		while (!(cin >> ID))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
		while (cin.get() != '\n')
			;

		if (!is_repete(ID))
			break;
		else
			cout << "ְ������ظ�������������:> ";
	}

	string name;
	cout << "�������޸ĺ�ְ��������:> ";
	cin >> name;

	Worker* newnode = NULL;
	while (true)
	{
		int dID = 0;
		cout << "1. Ա��\n2. ����\n3. �ϰ�" << endl;
		cout << "�������޸ĺ�ְ����ְλ:> ";
		while (!(cin >> dID))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
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
			cout << "����������������룡" << endl;
			break;
		}
		if (dID == 1 || dID == 2 || dID == 3)
			break;
	}

	wlist.insert(target, newnode);
	wlist.remove(*target);
	cout << "��ӳɹ�!" << endl;

	system("pause");
	system("cls");
}

void WorkerManage::search_Emp()
{
	list<Worker*>::iterator target = Find();
	if (target == wlist.end())
	{
		cout << "δ�ҵ���ְ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "�ҵ��˸�ְ������ְ����ϢΪ:" << endl;
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
		cout << "û��ְ����Ϣ���޷�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "1. ���������\n2. ����Ž���" << endl;
	cout << "��ѡ������ʽ:> ";
	while (true)
	{
		int choice = 0;
		while (!(cin >> choice))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
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
			cout << "����ָ�����������:> ";
	}
	system("pause");
	system("cls");
}

void WorkerManage::clear_File()
{
	while (true)
	{
		cout << "1. ȷ��\n2. ����\n��ȷ���Ƿ����?:> ";
		int choice = 0;
		while (!(cin >> choice))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
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
			cout << "ɾ���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (choice == 2)
		{
			cout << "�����������" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "ѡ�����������ѡ��!" << endl;
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