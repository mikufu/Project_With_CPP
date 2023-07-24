#pragma once
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "checkInput.h"
//ԤԼ����
enum Time1
{
	Mon = 1, Tue, Wed, Thu, Fri
};
//ԤԼʱ��
enum Time2
{
	Mor = 1, Aft
};
//ԤԼ״̬
enum Status
{
	Booking, Book_Succ,
	Book_Canc, Book_Fail
};
//����
enum ComRoom
{
	Room1 = 1, Room2, Room3
};
//���˵�ԤԼ��Ϣ
typedef struct Reservation
{
	int m_ID = 0;
	std::string m_username;
	Time1 m_time1 = Mon;
	Time2 m_time2 = Mor;
	ComRoom m_room = Room1;
	Status m_sta = Booking;
}Reservation;
//ԤԼϵͳ
class Order
{
public:
	std::list<Reservation> olist;	// ԤԼ�б�
	int ComRoom1;					//��������
	int ComRoom2;
	int ComRoom3;

public:
	//��ʼ��ԤԼ�б�ͻ�����Ϣ
	Order();
	//���ԤԼ
	bool AddOrder(int ID, std::string username, int time1, int time2, int room);
	//�������Ƿ�����
	bool CheckIsFull(int time1, int time2, int room);
	//������Ҫ��ӡԤԼ�б�
	void PrintOrder(const Reservation& res);
	//���ָ��ѧ�������ԤԼ����checkM_Res����
	void CheckOrder();
	//�������ѧ����ԤԼ����checkAllRes��checkRes����
	void CheckOrder(int ID, std::string username);
	//���ָ��ѧ���Լ���ԤԼ����cancelRes���ã�����ȡ��ԤԼ
	void CheckOrder(int ID, std::string username, std::vector<std::list<Reservation>::iterator>& tmp);
	//�������ѧ��ԤԼ����auditRes���ã����ڽ�ʦ���ԤԼ
	void CheckOrder(std::vector<std::list<Reservation>::iterator>& tmp);
	//�޸Ļ�������
	void SetComRoom();
	//���ԤԼ
	void ClearOrder();
	//����ԤԼ�б�
	void SaveOrder();
	//����ԤԼϵͳ
	~Order();
};