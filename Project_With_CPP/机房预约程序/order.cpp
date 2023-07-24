#include "Order.h"

Order::Order()
{
	ComRoom1 = 0; ComRoom2 = 0; ComRoom3 = 0;
	std::ifstream ifs;
	ifs.open("Order.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "没有Order.txt文件，请添加！" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//初始化预约列表
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
	//初始化机房信息
	ifs.open("ComRoom.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "没有ComRoom.txt文件，请添加！" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	while (ifs >> ComRoom1 >> ComRoom2 >> ComRoom3)
		;
}

bool Order::AddOrder(int ID, std::string username, int time1, int time2, int room)
{
	//检查机房是否已满
	if (CheckIsFull(time1, time2, room))
	{
		std::cout << "该机房已满！" << std::endl;
		return false;
	}
	//检查学生是否在该时间段里在相同机房已有成功的预约
	for (std::list<Reservation>::const_iterator it = olist.begin();
		it != olist.end(); it++)
	{
		if (it->m_ID == ID && it->m_time1 == time1 && (it->m_sta == Book_Succ
			|| it->m_sta == Booking) && it->m_time2 == time2 && it->m_room == room)
		{
			std::cout << "你在该时间段" << 
				room << "号机房已有预约！" << std::endl;
			return false;
		}
	}
	//将预约信息添加至预约列表中
	Reservation res;
	res.m_ID = ID;
	res.m_username = username;
	res.m_time1 = (Time1)time1;
	res.m_time2 = (Time2)time2;
	res.m_room = (ComRoom)room;
	res.m_sta = Booking;
	olist.push_back(res);
	SaveOrder();
	std::cout << "添加成功！审核中..." << std::endl;
	return true;
}

bool Order::CheckIsFull(int time1, int time2, int room)
{
	int count = 0;
	std::list<Reservation>::iterator it = olist.begin();
	while (it != olist.end())
	{
		//只记录预约成功的人
		if (it->m_sta == Book_Succ && it->m_room == room
			&& it->m_time1 == time1 && it->m_time2 == time2)
			count++;
		it++;
	}
	//对比预约成功的人数和机房容量
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
	//打印学号和用户名
	std::cout << "学号:> " << res.m_ID << "\t用户名:> " << res.m_username;
	//打印预约日期
	switch (res.m_time1)
	{
	case 1:
		std::cout << "\t预约日期:> 周一";
		break;
	case 2:
		std::cout << "\t预约日期:> 周二";
		break;
	case 3:
		std::cout << "\t预约日期:> 周三";
		break;
	case 4:
		std::cout << "\t预约日期:> 周四";
		break;
	case 5:
		std::cout << "\t预约日期:> 周五";
		break;
	}
	//打印预约的时间段
	if (res.m_time2 == Mor)
		std::cout << "\t预约时间:> 上午";
	else
		std::cout << "\t预约时间:> 下午";
	//打印预约的机房号
	std::cout << "\t机房:> " << res.m_room;
	//打印预约状态
	switch (res.m_sta)
	{
	case 0:
		std::cout << "\t预约状态:> 预约中...";
		break;
	case 1:
		std::cout << "\t预约状态:> 预约成功！";
		break;
	case 2:
		std::cout << "\t预约状态:> 预约已取消！";
		break;
	case 3:
		std::cout << "\t预约状态:> 预约失败！";
		break;
	}
	std::cout << std::endl;
}

void Order::CheckOrder(int ID, std::string username)
{
	int index = 0;
	//用只读迭代器，仅用于打印输出，不对预约列表进行修改
	std::list<Reservation>::const_iterator it = olist.begin();
	while (it != olist.end())
	{
		if (it->m_ID == ID && it->m_username == username)
		{
			std::cout << ++index << "、";
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "你暂时还没有预约！" << std::endl;
}

void Order::CheckOrder()
{
	int index = 0;
	//用只读迭代器，仅用于打印输出，不对预约列表进行修改
	std::list<Reservation>::const_iterator it = olist.begin();
	if (it == olist.end())
	{
		std::cout << "还未添加预约！" << std::endl;
		return;
	}
	while (it != olist.end())
	{
		std::cout << ++index << "、";
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
			std::cout << ++index << "、";
			//将预约列表中的迭代器放入tmp中，用于学生修改和取消预约
			tmp.push_back(it);
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "你暂时还没有预约！" << std::endl;
}

void Order::CheckOrder(std::vector<std::list<Reservation>::iterator>& tmp)
{
	int index = 0;
	std::list<Reservation>::iterator it = olist.begin();
	while (it != olist.end())
	{
		if (it->m_sta == Booking)
		{
			std::cout << ++index << "、";
			//将预约列表中的迭代器放入tmp中，用于教师审核预约
			tmp.push_back(it);
			PrintOrder(*it);
		}
		it++;
	}
	if (index == 0)
		std::cout << "暂时还没有预约！" << std::endl;
}

void Order::SetComRoom()
{
	std::cout << "1号机房\n2号机房\n3号机房" << std::endl;
	std::cout << "请选择需要修改容量的机房:> ";
	int choice = 0;
	checkInput(choice, 3);
	std::cout << "新容量为:> ";
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
	std::cout << "修改成功！" << std::endl;
}

void Order::ClearOrder()
{
	olist.clear();
	std::ofstream ofs;
	ofs.open("Order.txt", std::ios::trunc);
	ofs.close();
	std::cout << "清除成功！" << std::endl;
}

void Order::SaveOrder()
{
	std::ofstream ofs;
	ofs.open("Order.txt", std::ios::out);
	std::list<Reservation>::iterator it = this->olist.begin();
	while (it != this->olist.end())
	{
		//仅保存预约中和预约成功的信息
		if (it->m_sta == Booking || it->m_sta == Book_Succ)
		{
			ofs << "学号：" << " " << it->m_ID << " " << "姓名：" << " " << it->m_username << " "
				<< "日期：" << " " << it->m_time1 << " " << "时间：" << " " << it->m_time2 << " "
				<< "机房：" << " " << it->m_room << " " << "预约状态：" << " " << it->m_sta << std::endl;
		}
		it++;
	}
	ofs.close();
}

Order::~Order()
{
	//保存预约列表，并清空预约列表
	SaveOrder();
	olist.clear();
}