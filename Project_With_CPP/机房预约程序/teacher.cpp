#include "Teacher.h"

Teacher::Teacher(int ID, std::string username, std::string password)
{
	//���ڹ���Ա������ʦ��
	this->m_ID = ID;
	this->m_username = username;
	this->m_password = password;
}

void Teacher::showMenu()
{
	//��ʦҳ��˵�
	std::cout << "--------------------��ӭ" << this->m_username << "ʹ�û���ԤԼϵͳ!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.�鿴    ԤԼ       |" << std::endl;
	std::cout << "                |      2.���    ԤԼ       |" << std::endl;
	std::cout << "                |      3.������������       |" << std::endl;
	std::cout << "                |      0.�˳�    ����       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "���������ѡ��:> ";
}

void Teacher::checkRes(Order& ord)
{
	ord.CheckOrder();
}

void Teacher::auditRes(Order& ord)
{
	std::vector<std::list<Reservation>::iterator> tmp;
	ord.CheckOrder(tmp);
	if (tmp.empty())
		return;
	//���ԤԼ
	std::cout << "��ѡ����Ҫ��˵�ԤԼ:> ";
	int choice = 0;
	//��������Ƿ�Ϸ�
	checkInput(choice, (const int)tmp.size());
	choice--;	//�ҵ���Ҫ��˵�ԤԼ��vector�ж�Ӧ��λ��
	int input = 0;
	std::cout << "1��ͨ��" << std::endl;
	std::cout << "2����ͨ��" << std::endl;
	std::cout << "��˽��:> ";
	//��������Ƿ�Ϸ�
	checkInput(input, 2);
	if (input == 1)
	{
		//�жϻ����Ƿ�����
		if (ord.CheckIsFull(tmp[choice]->m_time1, tmp[choice]->m_time2, tmp[choice]->m_room))
		{
			std::cout << tmp[choice]->m_room << "�Ż���������" << std::endl;
			return;
		}
		//�ж����ʱ��θ�ѧ���Ƿ�����ͨ����ԤԼ
		for (std::list<Reservation>::const_iterator it = ord.olist.begin();
			it != ord.olist.end(); it++)
		{
				if (it->m_ID == tmp[choice]->m_ID && it->m_sta == Book_Succ && 
					it->m_time1 == tmp[choice]->m_time1 && it->m_time2 == tmp[choice]->m_time2)
				{
					std::cout << "��ѧ���ڸ�ʱ�������ԤԼ�ɹ���" << std::endl;
					return;
				}
		}
		tmp[choice]->m_sta = Book_Succ;
	}
	else
		tmp[choice]->m_sta = Book_Fail;
	ord.SaveOrder();
	std::cout << "ԤԼ�����ɣ�" << std::endl;
}

void Teacher::setPword()
{
	std::cout << "1����������" << std::endl;
	std::cout << "2������" << std::endl;
	std::cout << "������ѡ��:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, 2);
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

bool Teacher::operator==(const Teacher& t) const
{
	if (this->m_ID == t.m_ID)
		return true;
	else
		return false;
}

std::string Teacher::GetUname() const
{
	return this->m_username;
}

std::string Teacher::GetPword() const
{
	return this->m_password;
}

int Teacher::GetID() const
{
	return this->m_ID;
}