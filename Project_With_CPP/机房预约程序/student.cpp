#include "Student.h"

Student::Student(int ID, std::string username, std::string password)
{
	//用于管理员创建新的学生
	this->m_ID = ID;
	this->m_username = username;
	this->m_password = password;
}

void Student::showMenu()
{
	//学生页面的菜单
	std::cout << "--------------------欢迎" << this->m_username << "使用机房预约系统!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.申请使用机房       |" << std::endl;
	std::cout << "                |      2.查看我的预约       |" << std::endl;
	std::cout << "                |      3.查看所有预约       |" << std::endl;
	std::cout << "                |      4.修改    预约       |" << std::endl;
	std::cout << "                |      5.取消    预约       |" << std::endl;
	std::cout << "                |      6.重新设置密码       |" << std::endl;
	std::cout << "                |      0.退出    登入       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "请输入你的选择:> ";
}

void Student::applyRes(Order& ord)
{
	//选择预约日期
	int time1 = 0;
	std::cout << "机房开放时间为周一至周五" << std::endl;
	std::cout << "1、周一" << std::endl;
	std::cout << "2、周二" << std::endl;
	std::cout << "3、周三" << std::endl;
	std::cout << "4、周四" << std::endl;
	std::cout << "5、周五" << std::endl;
	std::cout << "请输入申请的日期:> ";
	//判断输入是否合法
	checkInput(time1, 5);
	//选择预约时段
	int time2 = 0;
	std::cout << "1、上午" << std::endl;
	std::cout << "2、下午" << std::endl;
	std::cout << "请输入申请的时间:> ";
	//判断输入是否合法
	checkInput(time2, 2);
	//选择预约机房
	int room = 0;
	std::cout << "1号机房容量:> " << ord.ComRoom1 << std::endl;
	std::cout << "2号机房容量:> " << ord.ComRoom2 << std::endl;
	std::cout << "3号机房容量:> " << ord.ComRoom3 << std::endl;
	std::cout << "请输入申请的机房:> ";
	//判断输入是否合法
	checkInput(room, 3);
	//添加预约信息
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
	//获取自身所有预约信息
	std::vector<std::list<Reservation>::iterator> tmp;
	ord.CheckOrder(this->GetID(), this->GetUname(), tmp);
	if (tmp.empty())
		return;
	//选择需要取消的预约
	std::cout << "请选择需要修改的预约:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, (const int)tmp.size());
	choice--;	//找到需要修改的预约在vector中对应的位置
	if (tmp[choice]->m_sta == Booking)	//仅能修改预约中的预约
	{
		//修改日期
		int time1 = 0;
		std::cout << "1、周一" << std::endl;
		std::cout << "2、周二" << std::endl;
		std::cout << "3、周三" << std::endl;
		std::cout << "4、周四" << std::endl;
		std::cout << "5、周五" << std::endl;
		std::cout << "请输入修改的日期:> ";
		checkInput(time1, 5);		//判断输入是否合法
		//修改时间
		int time2 = 0;
		std::cout << "1、上午" << std::endl;
		std::cout << "2、下午" << std::endl;
		std::cout << "请输入修改的时间:> ";
		checkInput(time2, 2);		//判断输入是否合法
		//修改机房
		int room = 0;
		std::cout << "1号机房容量:> " << ord.ComRoom1 << std::endl;
		std::cout << "2号机房容量:> " << ord.ComRoom2 << std::endl;
		std::cout << "3号机房容量:> " << ord.ComRoom3 << std::endl;
		std::cout << "请输入修改的机房:> ";
		checkInput(room, 3);		//判断输入是否合法
		tmp[choice]->m_sta = Book_Fail;	//将要修改的预约设置为Book_Fail，防止误判
		if (ord.AddOrder(this->GetID(), this->GetUname(), time1, time2, room))
			ord.olist.erase(tmp[choice]);	//若修改的预约添加成功，把旧的预约删除
		else
		{
			tmp[choice]->m_sta = Booking;	//若修改的预约添加失败，把旧的预约装填还原为Booking
			std::cout << "修改失败！" << std::endl;
			return;
		}
		ord.SaveOrder();
		std::cout << "预约修改成功！" << std::endl;
	}
	else if (tmp[choice]->m_sta == Book_Succ)
		std::cout << "预约已成功，无法修改！" << std::endl;
	else
		std::cout << "预约已取消或预约失败，无法修改！" << std::endl;
}

void Student::cancelRes(Order& ord)
{
	//获取自身所有预约信息
	std::vector<std::list<Reservation>::iterator> tmp;
	ord.CheckOrder(this->GetID(), this->GetUname(), tmp);
	if (tmp.empty())
		return;
	//选择需要取消的预约
	std::cout << "请选择需要取消的预约:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, (const int)tmp.size());
	int i = 0;
	std::cout << "1、确认\n2、返回" << std::endl;
	std::cout << "确认是否取消?:> ";
	checkInput(i, 2);
	if (i == 1)
	{
		choice--;	//找到需要取消的预约在vector中对应的位置
		if (tmp[choice]->m_sta == Booking || tmp[choice]->m_sta == Book_Succ)
		{
			//仅能取消预约成功和预约中的预约
			tmp[choice]->m_sta = Book_Canc;
			ord.SaveOrder();
			std::cout << "预约取消成功！" << std::endl;
		}
		else
			std::cout << "预约已取消或预约失败！" << std::endl;
	}
	else
		return;
}

void Student::setPword()
{
	std::cout << "1、忘记密码" << std::endl;
	std::cout << "2、返回" << std::endl;
	std::cout << "请输入选择:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, 2);
	if (choice == 1)
	{
		std::string password;
		std::cout << "请输入新的密码:> ";
		std::cin >> password;
		this->m_password.swap(password);
		std::cout << "更改成功！" << std::endl;
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
