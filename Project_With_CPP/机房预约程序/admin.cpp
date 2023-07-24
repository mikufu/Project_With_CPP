#include "Admin.h"

Admin::Admin(std::string username, std::string password)
{
	this->m_username = username;
	this->m_password = password;
}

void Admin::showMenu()
{
	//管理员菜单
	std::cout << "--------------------欢迎" << this->m_username << "使用机房预约系统!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.查看    账号       |" << std::endl;
	std::cout << "                |      2.添加    账号       |" << std::endl;
	std::cout << "                |      3.删除    账号       |" << std::endl;
	std::cout << "                |      4.查看机房信息       |" << std::endl;
	std::cout << "                |      5.更改机房容量       |" << std::endl;
	std::cout << "                |      6.重新设置密码       |" << std::endl;
	std::cout << "                |      7.清空    预约       |" << std::endl;
	std::cout << "                |      0.退出    登入       |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "请输入你的选择:> ";
}

void Admin::printAccount(const std::list<Student>& ls)
{
	std::list<Student>::const_iterator it = ls.begin();
	if (it == ls.end())
	{
		std::cout << "还未添加学生！" << std::endl;
		return;
	}
	int index = 0;
	while (it != ls.end())
	{
		std::cout << ++index << "、";
		std::cout << "学号:> " << it->GetID()
			<< "\t用户名:> " << it->GetUname()
			<< std::endl;		
		it++;
	}
}

void Admin::printAccount(const std::list<Teacher>& lt)
{
	std::list<Teacher>::const_iterator it = lt.begin();
	if (it == lt.end())
	{
		std::cout << "还未添加教师！" << std::endl;
		return;
	}
	int index = 0;
	while (it != lt.end())
	{
		std::cout << ++index << "、";
		std::cout << "工号:> " << it->GetID()
			<< "\t用户名:> " << it->GetUname()
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
		std::cout << ++index << "、";
		std::cout << "用户名:> " << it->GetUname() << std::endl;
		it++;
	}
}

void Admin::checkAccount(const std::list<Student>& ls, const std::list<Teacher>& lt, const std::list<Admin>& la)
{
	std::cout << "1、所有学生的账号" << std::endl;
	std::cout << "2、所有教师的账号" << std::endl;
	std::cout << "3、所有管理员的账号" << std::endl;
	std::cout << "请选择查看账号的类型:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, 3);
	if (choice == 1)
		printAccount(ls);		//打印所有学生账号信息
	else if (choice == 2)
		printAccount(lt);		//打印所有教师账号信息
	else
		printAccount(la);		//打印所有管理员账号信息
}

void Admin::addAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la)
{
	std::cout << "1、学生账号" << std::endl;
	std::cout << "2、教师账号" << std::endl;
	std::cout << "3、管理员账号" << std::endl;
	std::cout << "请选择要添加账号的类型:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, 3);
	//添加学生账号
	int ID = 0;
	std::string username;
	std::string password;
	if (choice == 1)
	{
		std::cout << "请输入学生的学号:> ";
		checkInput(ID);
		std::cout << "请输入学生的用户名:> ";
		std::cin >> username;
		std::cout << "请输入学生的密码:> ";
		std::cin >> password;
		//检测学号是否重复
		Student s(ID, username, password);
		if (find(ls.begin(), ls.end(), s) == ls.end())
		{	
			ls.push_back(s);		//将学生信息添加到学生列表
			std::cout << "添加成功！" << std::endl;
		}
		else
			std::cout << "学号重复！" << std:: endl;
	}
	else if(choice == 2)
	{
		std::cout << "请输入教师的工号:> ";
		checkInput(ID);
		std::cout << "请输入教师的用户名:> ";
		std::cin >> username;
		std::cout << "请输入教师的密码:> ";
		std::cin >> password;
		//检测工号是否重复
		Teacher t(ID, username, password);
		if (find(lt.begin(), lt.end(), t) == lt.end())
		{
			lt.push_back(t);		//将教师信息添加到教师列表
			std::cout << "添加成功！" << std::endl;
		}
		else
			std::cout << "工号重复！" << std::endl;
	}
	else
	{
		std::cout << "请输入管理员的用户名:> ";
		std::cin >> username;
		std::cout << "请输入管理员的密码:> ";
		std::cin >> password;
		//检测用户名是否重复
		Admin a(username, password);
		if (find(la.begin(), la.end(), a) == la.end())
		{
			la.push_back(a);		//将管理员信息添加到管理员列表
			std::cout << "添加成功！" << std::endl;
		}
		else
			std::cout << "用户名重复！" << std::endl;
	}
}

void Admin::delAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la)
{
	std::cout << "1、删除学生的账号" << std::endl;
	std::cout << "2、删除教师的账号" << std::endl;
	std::cout << "3、删除管理员的账号" << std::endl;
	std::cout << "请选择删除账号的类型:> ";
	int choice = 0;
	//判断输入是否合法
	checkInput(choice, 3);
	int index = 0;
	if (choice == 1)
	{
		printAccount(ls);		//打印学生信息
		//选择要删除的学生
		int i = 0;
		std::cout << "请选择需要删除的账号:> ";
		checkInput(i, (const int)ls.size());
		std::list<Student>::iterator it = ls.begin();
		while (--i) { it++; }
		ls.remove(*it);
		std::cout << "删除成功！" << std::endl;
	}
	else if (choice == 2)
	{
		printAccount(lt);		//打印教师信息
		//选择要删除的教师
		int i = 0;
		std::cout << "请选择需要删除的账号:> ";
		checkInput(i, (const int)lt.size());
		std::list<Teacher>::iterator it = lt.begin();
		while (--i) { it++; }
		lt.remove(*it);
		std::cout << "删除成功！" << std::endl;
	}
	else
	{
		printAccount(la);		//打印管理员信息
		//选择要删除的管理员
		int i = 0;
		std::cout << "请选择需要删除的账号:> ";
		checkInput(i, (const int)la.size());
		std::list<Admin>::iterator it = la.begin();
		while (--i) { it++; }
		if (it->GetUname() == this->m_username)
		{
			std::cout << "不能删除自己的账号！" << std::endl;
			return;
		}
		la.remove(*it);
		std::cout << "删除成功！" << std::endl;
	}
}

void Admin::checkComRoom(Order& ord)
{
	std::cout << "1号机房容量:> " << ord.ComRoom1 << std::endl;
	std::cout << "2号机房容量:> " << ord.ComRoom2 << std::endl;
	std::cout << "3号机房容量:> " << ord.ComRoom3 << std::endl;
	std::cout << "请选择需要查看的机房:> ";
	int room = 0;
	checkInput(room, 3);		//检查输入是否正确
	int time1 = 0;
	std::cout << "1、周一" << std::endl;
	std::cout << "2、周二" << std::endl;
	std::cout << "3、周三" << std::endl;
	std::cout << "4、周四" << std::endl;
	std::cout << "5、周五" << std::endl;
	std::cout << "请选择需要查看的日期:> ";
	checkInput(time1, 5);		//检查输入是否正确
	std::cout << "1、上午" << std::endl;
	std::cout << "2、下午" << std::endl;
	std::cout << "请选择需要查看的时间:> ";
	int time2 = 0;
	checkInput(time2, 2);		//检查输入是否正确
	if (ord.CheckIsFull(time1, time2, room))
		std::cout << "机房已满！" << std::endl;
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
		std::cout << room << "号机房已有" << count << "人！" << std::endl;
	}
}

void Admin::setComRoom(Order& ord)
{
	ord.SetComRoom();
}

void Admin::setPword()
{
	std::cout << "1、忘记密码" << std::endl;
	std::cout << "2、返回" << std::endl;
	std::cout << "请输入选择:> ";
	int choice = 0;
	checkInput(choice, 2);		//判断输入是否合法
	//输入新密码并设置
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

void Admin::clearRes(Order& ord)
{
	int choice = 0;
	std::cout << "1、确认" << std::endl;
	std::cout << "2、返回" << std::endl;
	std::cout << "确认是否清空预约？:>";
	checkInput(choice, 2);
	//清空预约文件或返回
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