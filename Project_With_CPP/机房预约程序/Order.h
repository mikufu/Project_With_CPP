#pragma once
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "checkInput.h"
//预约日期
enum Time1
{
	Mon = 1, Tue, Wed, Thu, Fri
};
//预约时段
enum Time2
{
	Mor = 1, Aft
};
//预约状态
enum Status
{
	Booking, Book_Succ,
	Book_Canc, Book_Fail
};
//机房
enum ComRoom
{
	Room1 = 1, Room2, Room3
};
//个人的预约信息
typedef struct Reservation
{
	int m_ID = 0;
	std::string m_username;
	Time1 m_time1 = Mon;
	Time2 m_time2 = Mor;
	ComRoom m_room = Room1;
	Status m_sta = Booking;
}Reservation;
//预约系统
class Order
{
public:
	std::list<Reservation> olist;	// 预约列表
	int ComRoom1;					//机房容量
	int ComRoom2;
	int ComRoom3;

public:
	//初始化预约列表和机房信息
	Order();
	//添加预约
	bool AddOrder(int ID, std::string username, int time1, int time2, int room);
	//检查机房是否已满
	bool CheckIsFull(int time1, int time2, int room);
	//根据需要打印预约列表
	void PrintOrder(const Reservation& res);
	//检查指定学生自身的预约，由checkM_Res调用
	void CheckOrder();
	//检查所有学生的预约，由checkAllRes和checkRes调用
	void CheckOrder(int ID, std::string username);
	//检查指定学生自己的预约，由cancelRes调用，用于取消预约
	void CheckOrder(int ID, std::string username, std::vector<std::list<Reservation>::iterator>& tmp);
	//检查所有学生预约，由auditRes调用，用于教师审核预约
	void CheckOrder(std::vector<std::list<Reservation>::iterator>& tmp);
	//修改机房容量
	void SetComRoom();
	//清空预约
	void ClearOrder();
	//保存预约列表
	void SaveOrder();
	//析构预约系统
	~Order();
};