#include "Admin.h"

Admin::Admin(std::string username, std::string password)
{
	this->m_username = username;
	this->m_password = password;
}

void Admin::showMenu()
{
	//����Ա�˵�
	std::cout << "--------------------��ӭ" << this->m_username << "ʹ�û���ԤԼϵͳ!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.�鿴    �˺�       |" << std::endl;
	std::cout << "                |      2.���    �˺�       |" << std::endl;
	std::cout << "                |      3.ɾ��    �˺�       |" << std::endl;
	std::cout << "                |      4.�鿴������Ϣ       |" << std::endl;
	std::cout << "                |      5.���Ļ�������       |" << std::endl;
	std::cout << "                |      6.������������       |" << std::endl;
	std::cout << "                |      7.���    ԤԼ       |" << std::endl;
	std::cout << "                |      0.�˳�    ����       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "���������ѡ��:> ";
}

void Admin::printAccount(const std::list<Student>& ls)
{
	std::list<Student>::const_iterator it = ls.begin();
	if (it == ls.end())
	{
		std::cout << "��δ���ѧ����" << std::endl;
		return;
	}
	int index = 0;
	while (it != ls.end())
	{
		std::cout << ++index << "��";
		std::cout << "ѧ��:> " << it->GetID()
			<< "\t�û���:> " << it->GetUname()
			<< std::endl;		
		it++;
	}
}

void Admin::printAccount(const std::list<Teacher>& lt)
{
	std::list<Teacher>::const_iterator it = lt.begin();
	if (it == lt.end())
	{
		std::cout << "��δ��ӽ�ʦ��" << std::endl;
		return;
	}
	int index = 0;
	while (it != lt.end())
	{
		std::cout << ++index << "��";
		std::cout << "����:> " << it->GetID()
			<< "\t�û���:> " << it->GetUname()
			<< std::endl;
		it++;
	}
}

void Admin::printAccount(const std::list<Admin>& la)
{
	std::list<Admin>::const_iterator it = la.begin();
	int index = 0;
	while (it != la.end())
	{
		std::cout << ++index << "��";
		std::cout << "�û���:> " << it->GetUname() << std::endl;
		it++;
	}
}

void Admin::checkAccount(const std::list<Student>& ls, const std::list<Teacher>& lt, const std::list<Admin>& la)
{
	std::cout << "1������ѧ�����˺�" << std::endl;
	std::cout << "2�����н�ʦ���˺�" << std::endl;
	std::cout << "3�����й���Ա���˺�" << std::endl;
	std::cout << "��ѡ��鿴�˺ŵ�����:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, 3);
	if (choice == 1)
		printAccount(ls);		//��ӡ����ѧ���˺���Ϣ
	else if (choice == 2)
		printAccount(lt);		//��ӡ���н�ʦ�˺���Ϣ
	else
		printAccount(la);		//��ӡ���й���Ա�˺���Ϣ
}

void Admin::addAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la)
{
	std::cout << "1��ѧ���˺�" << std::endl;
	std::cout << "2����ʦ�˺�" << std::endl;
	std::cout << "3������Ա�˺�" << std::endl;
	std::cout << "��ѡ��Ҫ����˺ŵ�����:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, 3);
	//���ѧ���˺�
	int ID = 0;
	std::string username;
	std::string password;
	if (choice == 1)
	{
		std::cout << "������ѧ����ѧ��:> ";
		checkInput(ID);
		std::cout << "������ѧ�����û���:> ";
		std::cin >> username;
		std::cout << "������ѧ��������:> ";
		std::cin >> password;
		//���ѧ���Ƿ��ظ�
		Student s(ID, username, password);
		if (find(ls.begin(), ls.end(), s) == ls.end())
		{	
			ls.push_back(s);		//��ѧ����Ϣ��ӵ�ѧ���б�
			std::cout << "��ӳɹ���" << std::endl;
		}
		else
			std::cout << "ѧ���ظ���" << std:: endl;
	}
	else if(choice == 2)
	{
		std::cout << "�������ʦ�Ĺ���:> ";
		checkInput(ID);
		std::cout << "�������ʦ���û���:> ";
		std::cin >> username;
		std::cout << "�������ʦ������:> ";
		std::cin >> password;
		//��⹤���Ƿ��ظ�
		Teacher t(ID, username, password);
		if (find(lt.begin(), lt.end(), t) == lt.end())
		{
			lt.push_back(t);		//����ʦ��Ϣ��ӵ���ʦ�б�
			std::cout << "��ӳɹ���" << std::endl;
		}
		else
			std::cout << "�����ظ���" << std::endl;
	}
	else
	{
		std::cout << "���������Ա���û���:> ";
		std::cin >> username;
		std::cout << "���������Ա������:> ";
		std::cin >> password;
		//����û����Ƿ��ظ�
		Admin a(username, password);
		if (find(la.begin(), la.end(), a) == la.end())
		{
			la.push_back(a);		//������Ա��Ϣ��ӵ�����Ա�б�
			std::cout << "��ӳɹ���" << std::endl;
		}
		else
			std::cout << "�û����ظ���" << std::endl;
	}
}

void Admin::delAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la)
{
	std::cout << "1��ɾ��ѧ�����˺�" << std::endl;
	std::cout << "2��ɾ����ʦ���˺�" << std::endl;
	std::cout << "3��ɾ������Ա���˺�" << std::endl;
	std::cout << "��ѡ��ɾ���˺ŵ�����:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, 3);
	int index = 0;
	if (choice == 1)
	{
		printAccount(ls);		//��ӡѧ����Ϣ
		//ѡ��Ҫɾ����ѧ��
		int i = 0;
		std::cout << "��ѡ����Ҫɾ�����˺�:> ";
		checkInput(i, (const int)ls.size());
		std::list<Student>::iterator it = ls.begin();
		while (--i) { it++; }
		ls.remove(*it);
		std::cout << "ɾ���ɹ���" << std::endl;
	}
	else if (choice == 2)
	{
		printAccount(lt);		//��ӡ��ʦ��Ϣ
		//ѡ��Ҫɾ���Ľ�ʦ
		int i = 0;
		std::cout << "��ѡ����Ҫɾ�����˺�:> ";
		checkInput(i, (const int)lt.size());
		std::list<Teacher>::iterator it = lt.begin();
		while (--i) { it++; }
		lt.remove(*it);
		std::cout << "ɾ���ɹ���" << std::endl;
	}
	else
	{
		printAccount(la);		//��ӡ����Ա��Ϣ
		//ѡ��Ҫɾ���Ĺ���Ա
		int i = 0;
		std::cout << "��ѡ����Ҫɾ�����˺�:> ";
		checkInput(i, (const int)la.size());
		std::list<Admin>::iterator it = la.begin();
		while (--i) { it++; }
		if (it->GetUname() == this->m_username)
		{
			std::cout << "����ɾ���Լ����˺ţ�" << std::endl;
			return;
		}
		la.remove(*it);
		std::cout << "ɾ���ɹ���" << std::endl;
	}
}

void Admin::checkComRoom(Order& ord)
{
	std::cout << "1�Ż�������:> " << ord.ComRoom1 << std::endl;
	std::cout << "2�Ż�������:> " << ord.ComRoom2 << std::endl;
	std::cout << "3�Ż�������:> " << ord.ComRoom3 << std::endl;
	std::cout << "��ѡ����Ҫ�鿴�Ļ���:> ";
	int room = 0;
	checkInput(room, 3);		//��������Ƿ���ȷ
	int time1 = 0;
	std::cout << "1����һ" << std::endl;
	std::cout << "2���ܶ�" << std::endl;
	std::cout << "3������" << std::endl;
	std::cout << "4������" << std::endl;
	std::cout << "5������" << std::endl;
	std::cout << "��ѡ����Ҫ�鿴������:> ";
	checkInput(time1, 5);		//��������Ƿ���ȷ
	std::cout << "1������" << std::endl;
	std::cout << "2������" << std::endl;
	std::cout << "��ѡ����Ҫ�鿴��ʱ��:> ";
	int time2 = 0;
	checkInput(time2, 2);		//��������Ƿ���ȷ
	if (ord.CheckIsFull(time1, time2, room))
		std::cout << "����������" << std::endl;
	else
	{
		int count = 0;
		for (std::list<Reservation>::const_iterator it = ord.olist.begin();
			it != ord.olist.end(); it++)
		{
			if (it->m_room == room && it->m_time1 == time1
				&& it->m_time2 == time2 && it->m_sta == Book_Succ)
				count++;
		}
		std::cout << room << "�Ż�������" << count << "�ˣ�" << std::endl;
	}
}

void Admin::setComRoom(Order& ord)
{
	ord.SetComRoom();
}

void Admin::setPword()
{
	std::cout << "1����������" << std::endl;
	std::cout << "2������" << std::endl;
	std::cout << "������ѡ��:> ";
	int choice = 0;
	checkInput(choice, 2);		//�ж������Ƿ�Ϸ�
	//���������벢����
	if (choice == 1)
	{
		std::string password;
		std::cout << "�������µ�����:> ";
		std::cin >> password;
		this->m_password.swap(password);
		std::cout << "���ĳɹ���" << std::endl;
	}
	else
		return;
}

void Admin::clearRes(Order& ord)
{
	int choice = 0;
	std::cout << "1��ȷ��" << std::endl;
	std::cout << "2������" << std::endl;
	std::cout << "ȷ���Ƿ����ԤԼ��:>";
	checkInput(choice, 2);
	//���ԤԼ�ļ��򷵻�
	if (choice == 1)
		ord.ClearOrder();
	else
		return;
}

bool Admin::operator== (const Admin& a) const
{
	if (this->m_username == a.GetUname())
		return true;
	else
		return false;
}

std::string Admin::GetUname() const
{
	return this->m_username;
}

std::string Admin::GetPword() const
{
	return this->m_password;
}