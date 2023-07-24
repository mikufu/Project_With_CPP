#include "Order.h"

Order::Order()
{
	ComRoom1 = 0; ComRoom2 = 0; ComRoom3 = 0;
	std::ifstream ifs;
	ifs.open("Order.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "û��Order.txt�ļ�������ӣ�" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//��ʼ��ԤԼ�б�
	int ID;
	std::string username;
	int room;
	int time1; int time2;
	int sta;
	std::string tmp;
	while (ifs >> tmp >> ID >> tmp >> username >> tmp >> time1
				>> tmp >> time2 >> tmp >> room >> tmp >> sta)
	{
		Reservation res;
		res.m_ID = ID;
		res.m_username = username;
		res.m_time1 = (Time1)time1;
		res.m_time2 = (Time2)time2;
		res.m_room = (ComRoom)room;
		res.m_sta = (Status)sta;
		olist.push_back(res);
	}
	ifs.close();
	//��ʼ��������Ϣ
	ifs.open("ComRoom.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "û��ComRoom.txt�ļ�������ӣ�" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	while (ifs >> ComRoom1 >> ComRoom2 >> ComRoom3)
		;
}

bool Order::AddOrder(int ID, std::string username, int time1, int time2, int room)
{
	//�������Ƿ�����
	if (CheckIsFull(time1, time2, room))
	{
		std::cout << "�û���������" << std::endl;
		return false;
	}
	//���ѧ���Ƿ��ڸ�ʱ���������ͬ�������гɹ���ԤԼ
	for (std::list<Reservation>::const_iterator it = olist.begin();
		it != olist.end(); it++)
	{
		if (it->m_ID == ID && it->m_time1 == time1 && (it->m_sta == Book_Succ
			|| it->m_sta == Booking) && it->m_time2 == time2 && it->m_room == room)
		{
			std::cout << "���ڸ�ʱ���" << 
				room << "�Ż�������ԤԼ��" << std::endl;
			return false;
		}
	}
	//��ԤԼ��Ϣ�����ԤԼ�б���
	Reservation res;
	res.m_ID = ID;
	res.m_username = username;
	res.m_time1 = (Time1)time1;
	res.m_time2 = (Time2)time2;
	res.m_room = (ComRoom)room;
	res.m_sta = Booking;
	olist.push_back(res);
	SaveOrder();
	std::cout << "��ӳɹ��������..." << std::endl;
	return true;
}

bool Order::CheckIsFull(int time1, int time2, int room)
{
	int count = 0;
	std::list<Reservation>::iterator it = olist.begin();
	while (it != olist.end())
	{
		//ֻ��¼ԤԼ�ɹ�����
		if (it->m_sta == Book_Succ && it->m_room == room
			&& it->m_time1 == time1 && it->m_time2 == time2)
			count++;
		it++;
	}
	//�Ա�ԤԼ�ɹ��������ͻ�������
	switch (room)
	{
	case 1:
		if (count == this->ComRoom1)
			return true;
		else
			break;
	case 2:
		if (count == this->ComRoom2)
			return true;
		else
			break;
	case 3:
		if (count == this->ComRoom3)
			return true;
		else
			break;
	}
	return false;
}

void Order::PrintOrder(const Reservation& res)
{
	//��ӡѧ�ź��û���
	std::cout << "ѧ��:> " << res.m_ID << "\t�û���:> " << res.m_username;
	//��ӡԤԼ����
	switch (res.m_time1)
	{
	case 1:
		std::cout << "\tԤԼ����:> ��һ";
		break;
	case 2:
		std::cout << "\tԤԼ����:> �ܶ�";
		break;
	case 3:
		std::cout << "\tԤԼ����:> ����";
		break;
	case 4:
		std::cout << "\tԤԼ����:> ����";
		break;
	case 5:
		std::cout << "\tԤԼ����:> ����";
		break;
	}
	//��ӡԤԼ��ʱ���
	if (res.m_time2 == Mor)
		std::cout << "\tԤԼʱ��:> ����";
	else
		std::cout << "\tԤԼʱ��:> ����";
	//��ӡԤԼ�Ļ�����
	std::cout << "\t����:> " << res.m_room;
	//��ӡԤԼ״̬
	switch (res.m_sta)
	{
	case 0:
		std::cout << "\tԤԼ״̬:> ԤԼ��...";
		break;
	case 1:
		std::cout << "\tԤԼ״̬:> ԤԼ�ɹ���";
		break;
	case 2:
		std::cout << "\tԤԼ״̬:> ԤԼ��ȡ����";
		break;
	case 3:
		std::cout << "\tԤԼ״̬:> ԤԼʧ�ܣ�";
		break;
	}
	std::cout << std::endl;
}

void Order::CheckOrder(int ID, std::string username)
{
	int index = 0;
	//��ֻ���������������ڴ�ӡ���������ԤԼ�б�����޸�
	std::list<Reservation>::const_iterator it = olist.begin();
	while (it != olist.end())
	{
		if (it->m_ID == ID && it->m_username == username)
		{
			std::cout << ++index << "��";
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "����ʱ��û��ԤԼ��" << std::endl;
}

void Order::CheckOrder()
{
	int index = 0;
	//��ֻ���������������ڴ�ӡ���������ԤԼ�б�����޸�
	std::list<Reservation>::const_iterator it = olist.begin();
	if (it == olist.end())
	{
		std::cout << "��δ���ԤԼ��" << std::endl;
		return;
	}
	while (it != olist.end())
	{
		std::cout << ++index << "��";
		PrintOrder(*it);
		it++;
	}
}

void Order::CheckOrder(int ID, std::string username, std::vector<std::list<Reservation>::iterator>& tmp)
{
	int index = 0;
	std::list<Reservation>::iterator it = olist.begin();
	while (it != olist.end())
	{
		if (it->m_ID == ID && it->m_username == username)
		{
			std::cout << ++index << "��";
			//��ԤԼ�б��еĵ���������tmp�У�����ѧ���޸ĺ�ȡ��ԤԼ
			tmp.push_back(it);
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "����ʱ��û��ԤԼ��" << std::endl;
}

void Order::CheckOrder(std::vector<std::list<Reservation>::iterator>& tmp)
{
	int index = 0;
	std::list<Reservation>::iterator it = olist.begin();
	while (it != olist.end())
	{
		if (it->m_sta == Booking)
		{
			std::cout << ++index << "��";
			//��ԤԼ�б��еĵ���������tmp�У����ڽ�ʦ���ԤԼ
			tmp.push_back(it);
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "��ʱ��û��ԤԼ��" << std::endl;
}

void Order::SetComRoom()
{
	std::cout << "1�Ż���\n2�Ż���\n3�Ż���" << std::endl;
	std::cout << "��ѡ����Ҫ�޸������Ļ���:> ";
	int choice = 0;
	checkInput(choice, 3);
	std::cout << "������Ϊ:> ";
	switch (choice)
	{
	case 1:
		checkInput(this->ComRoom1);
		break;
	case 2:
		checkInput(this->ComRoom2);
		break;
	case 3:
		checkInput(this->ComRoom3);
		break;
	}
	std::ofstream ofs;
	ofs.open("ComRoom.txt", std::ios::out);
	ofs << ComRoom1 << " " << ComRoom2 << " " << ComRoom3;
	std::cout << "�޸ĳɹ���" << std::endl;
}

void Order::ClearOrder()
{
	olist.clear();
	std::ofstream ofs;
	ofs.open("Order.txt", std::ios::trunc);
	ofs.close();
	std::cout << "����ɹ���" << std::endl;
}

void Order::SaveOrder()
{
	std::ofstream ofs;
	ofs.open("Order.txt", std::ios::out);
	std::list<Reservation>::iterator it = this->olist.begin();
	while (it != this->olist.end())
	{
		//������ԤԼ�к�ԤԼ�ɹ�����Ϣ
		if (it->m_sta == Booking || it->m_sta == Book_Succ)
		{
			ofs << "ѧ�ţ�" << " " << it->m_ID << " " << "������" << " " << it->m_username << " "
				<< "���ڣ�" << " " << it->m_time1 << " " << "ʱ�䣺" << " " << it->m_time2 << " "
				<< "������" << " " << it->m_room << " " << "ԤԼ״̬��" << " " << it->m_sta << std::endl;
		}
		it++;
	}
	ofs.close();
}

Order::~Order()
{
	//����ԤԼ�б������ԤԼ�б�
	SaveOrder();
	olist.clear();
}