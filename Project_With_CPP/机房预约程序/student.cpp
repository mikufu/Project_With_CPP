#include "Student.h"

Student::Student(int ID, std::string username, std::string password)
{
	//���ڹ���Ա�����µ�ѧ��
	this->m_ID = ID;
	this->m_username = username;
	this->m_password = password;
}

void Student::showMenu()
{
	//ѧ��ҳ��Ĳ˵�
	std::cout << "--------------------��ӭ" << this->m_username << "ʹ�û���ԤԼϵͳ!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.����ʹ�û���       |" << std::endl;
	std::cout << "                |      2.�鿴�ҵ�ԤԼ       |" << std::endl;
	std::cout << "                |      3.�鿴����ԤԼ       |" << std::endl;
	std::cout << "                |      4.�޸�    ԤԼ       |" << std::endl;
	std::cout << "                |      5.ȡ��    ԤԼ       |" << std::endl;
	std::cout << "                |      6.������������       |" << std::endl;
	std::cout << "                |      0.�˳�    ����       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "���������ѡ��:> ";
}

void Student::applyRes(Order& ord)
{
	//ѡ��ԤԼ����
	int time1 = 0;
	std::cout << "��������ʱ��Ϊ��һ������" << std::endl;
	std::cout << "1����һ" << std::endl;
	std::cout << "2���ܶ�" << std::endl;
	std::cout << "3������" << std::endl;
	std::cout << "4������" << std::endl;
	std::cout << "5������" << std::endl;
	std::cout << "���������������:> ";
	//�ж������Ƿ�Ϸ�
	checkInput(time1, 5);
	//ѡ��ԤԼʱ��
	int time2 = 0;
	std::cout << "1������" << std::endl;
	std::cout << "2������" << std::endl;
	std::cout << "�����������ʱ��:> ";
	//�ж������Ƿ�Ϸ�
	checkInput(time2, 2);
	//ѡ��ԤԼ����
	int room = 0;
	std::cout << "1�Ż�������:> " << ord.ComRoom1 << std::endl;
	std::cout << "2�Ż�������:> " << ord.ComRoom2 << std::endl;
	std::cout << "3�Ż�������:> " << ord.ComRoom3 << std::endl;
	std::cout << "����������Ļ���:> ";
	//�ж������Ƿ�Ϸ�
	checkInput(room, 3);
	//���ԤԼ��Ϣ
	ord.AddOrder(this->GetID(),this->GetUname(), time1, time2, room);
}

void Student::checkM_Res(Order& ord)
{
	ord.CheckOrder(this->GetID(), this->GetUname());
}

void Student::checkAllRes(Order& ord)
{
	ord.CheckOrder();
}

void Student::modifyRes(Order& ord)
{
	//��ȡ��������ԤԼ��Ϣ
	std::vector<std::list<Reservation>::iterator> tmp;
	ord.CheckOrder(this->GetID(), this->GetUname(), tmp);
	if (tmp.empty())
		return;
	//ѡ����Ҫȡ����ԤԼ
	std::cout << "��ѡ����Ҫ�޸ĵ�ԤԼ:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, (const int)tmp.size());
	choice--;	//�ҵ���Ҫ�޸ĵ�ԤԼ��vector�ж�Ӧ��λ��
	if (tmp[choice]->m_sta == Booking)	//�����޸�ԤԼ�е�ԤԼ
	{
		//�޸�����
		int time1 = 0;
		std::cout << "1����һ" << std::endl;
		std::cout << "2���ܶ�" << std::endl;
		std::cout << "3������" << std::endl;
		std::cout << "4������" << std::endl;
		std::cout << "5������" << std::endl;
		std::cout << "�������޸ĵ�����:> ";
		checkInput(time1, 5);		//�ж������Ƿ�Ϸ�
		//�޸�ʱ��
		int time2 = 0;
		std::cout << "1������" << std::endl;
		std::cout << "2������" << std::endl;
		std::cout << "�������޸ĵ�ʱ��:> ";
		checkInput(time2, 2);		//�ж������Ƿ�Ϸ�
		//�޸Ļ���
		int room = 0;
		std::cout << "1�Ż�������:> " << ord.ComRoom1 << std::endl;
		std::cout << "2�Ż�������:> " << ord.ComRoom2 << std::endl;
		std::cout << "3�Ż�������:> " << ord.ComRoom3 << std::endl;
		std::cout << "�������޸ĵĻ���:> ";
		checkInput(room, 3);		//�ж������Ƿ�Ϸ�
		tmp[choice]->m_sta = Book_Fail;	//��Ҫ�޸ĵ�ԤԼ����ΪBook_Fail����ֹ����
		if (ord.AddOrder(this->GetID(), this->GetUname(), time1, time2, room))
			ord.olist.erase(tmp[choice]);	//���޸ĵ�ԤԼ��ӳɹ����Ѿɵ�ԤԼɾ��
		else
		{
			tmp[choice]->m_sta = Booking;	//���޸ĵ�ԤԼ���ʧ�ܣ��Ѿɵ�ԤԼװ�ԭΪBooking
			std::cout << "�޸�ʧ�ܣ�" << std::endl;
			return;
		}
		ord.SaveOrder();
		std::cout << "ԤԼ�޸ĳɹ���" << std::endl;
	}
	else if (tmp[choice]->m_sta == Book_Succ)
		std::cout << "ԤԼ�ѳɹ����޷��޸ģ�" << std::endl;
	else
		std::cout << "ԤԼ��ȡ����ԤԼʧ�ܣ��޷��޸ģ�" << std::endl;
}

void Student::cancelRes(Order& ord)
{
	//��ȡ��������ԤԼ��Ϣ
	std::vector<std::list<Reservation>::iterator> tmp;
	ord.CheckOrder(this->GetID(), this->GetUname(), tmp);
	if (tmp.empty())
		return;
	//ѡ����Ҫȡ����ԤԼ
	std::cout << "��ѡ����Ҫȡ����ԤԼ:> ";
	int choice = 0;
	//�ж������Ƿ�Ϸ�
	checkInput(choice, (const int)tmp.size());
	int i = 0;
	std::cout << "1��ȷ��\n2������" << std::endl;
	std::cout << "ȷ���Ƿ�ȡ��?:> ";
	checkInput(i, 2);
	if (i == 1)
	{
		choice--;	//�ҵ���Ҫȡ����ԤԼ��vector�ж�Ӧ��λ��
		if (tmp[choice]->m_sta == Booking || tmp[choice]->m_sta == Book_Succ)
		{
			//����ȡ��ԤԼ�ɹ���ԤԼ�е�ԤԼ
			tmp[choice]->m_sta = Book_Canc;
			ord.SaveOrder();
			std::cout << "ԤԼȡ���ɹ���" << std::endl;
		}
		else
			std::cout << "ԤԼ��ȡ����ԤԼʧ�ܣ�" << std::endl;
	}
	else
		return;
}

void Student::setPword()
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

bool Student::operator==(const Student& s) const
{
	if (this->m_ID == s.m_ID)
		return true;
	else
		return false;
}

std::string Student::GetUname() const
{
	return this->m_username;
}

std::string Student::GetPword() const 
{
	return this->m_password;
}

int Student::GetID() const
{
	return this->m_ID;
}
