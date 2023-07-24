#include "Teacher.h"

Teacher::Teacher(int ID, std::string username, std::string password)
{
	//用于管理员创建教师类
	this->m_ID = ID;
	this->m_username = username;
	this->m_password = password;
}

void Teacher::showMenu()
{
	//教师页面菜单
	std::cout << "--------------------欢迎" << this->m_username << "使用机房预约系统!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.查看    预约       |" << std::endl;
	std::cout << "                |      2.审核    预约       |" << std::endl;
	std::cout << "                |      3.重新设置密码       |" << std::endl;
	std::cout << "                |      0.退出    登入       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "请输入你的选择:> ";
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
	//审核预约
	std::cout << "请选择需要审核的预约:> ";
	int choice = 0;
	//检查输入是否合法
	checkInput(choice, (const int)tmp.size());
	choice--;	//找到需要审核的预约在vector中对应的位置
	int input = 0;
	std::cout << "1、通过" << std::endl;
	std::cout << "2、不通过" << std::endl;
	std::cout << "审核结果:> ";
	//检查输入是否合法
	checkInput(input, 2);
	if (input == 1)
	{
		//判断机房是否已满
		if (ord.CheckIsFull(tmp[choice]->m_time1, tmp[choice]->m_time2, tmp[choice]->m_room))
		{
			std::cout << tmp[choice]->m_room << "号机房已满！" << std::endl;
			return;
		}
		//判断这个时间段该学生是否已有通过的预约
		for (std::list<Reservation>::const_iterator it = ord.olist.begin();
			it != ord.olist.end(); it++)
		{
				if (it->m_ID == tmp[choice]->m_ID && it->m_sta == Book_Succ && 
					it->m_time1 == tmp[choice]->m_time1 && it->m_time2 == tmp[choice]->m_time2)
				{
					std::cout << "该学生在该时间段已有预约成功！" << std::endl;
					return;
				}
		}
		tmp[choice]->m_sta = Book_Succ;
	}
	else
		tmp[choice]->m_sta = Book_Fail;
	ord.SaveOrder();
	std::cout << "预约审核完成！" << std::endl;
}

void Teacher::setPword()
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