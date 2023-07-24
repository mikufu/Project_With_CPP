#include "System.h"

System::System()
{
	std::ifstream ifs;
	//从Student.txt文件中读取学生信息
	ifs.open("Student.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "没有Student.txt文件，请添加！" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	int ID = 0;
	std::string username;
	std::string password;
	//初始化学生列表
	while (ifs >> ID >> username >> password)
	{
		this->ls.push_back(Student(ID, username, password));
	}
	ifs.close();
	//从Teacher.txt文件中读取教师信息
	ifs.open("Teacher.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "没有Teacher.txt文件，请添加！" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//初始化教师列表
	while (ifs >> ID >> username >> password)
	{
		lt.push_back(Teacher(ID, username, password));
	}
	ifs.close();
	//从Adimn.txt文件中读取管理员信息
	ifs.open("Admin.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "没有Order.txt文件，请添加！" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//初始化管理员列表
	while (ifs >> username >> password)
	{
		la.push_back(Admin(username, password));
	}
	ifs.close();
}

void System::MainMenu()
{
	//打印主菜单
	std::cout << "--------------------欢迎使用机房预约系统!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.学       生        |" << std::endl;
	std::cout << "                |      2.教       师        |" << std::endl;
	std::cout << "                |      3.管       理        |" << std::endl;
	std::cout << "                |      0.退       出        |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "请输入你的选择:> ";
}

std::list<Student>::iterator System::checkStu(int ID, std::string username, std::string password)
{
	//遍历学生列表并将对应登入的学生的迭代器返回
	for (std::list<Student>::iterator it = ls.begin();
		it != ls.end(); it++)
	{
		if (it->GetID() == ID
			&& it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return ls.end();
}

void System::StuSystem()
{
	int ID = 0;
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "请输入学号:> ";
		checkInput(ID);
		std::cout << "请输入用户名:> ";
		std::cin >> username;
		std::cout << "请输入密码:> ";
		std::cin >> password;
		//检测登入学生的信息是否存在
		std::list<Student>::iterator it = checkStu(ID, username, password);
		if (it != ls.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->applyRes(this->ord);				//申请预约
					break;
				case 2:
					it->checkM_Res(this->ord);				//查看预约
					break;
				case 3:
					it->checkAllRes(this->ord);				//查看所有预约
					break;
				case 4:
					it->modifyRes(this->ord);				//修改预约
					break;
				case 5:
					it->cancelRes(this->ord);				//取消预约
					break;
				case 6:
					it->setPword();							//重新设置密码
					this->save();
					break;
				case 0:
					break;
				default:
					std::cout << "输入错误！" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "用户名或密码错误，请重新登录！" << std::endl;
	}
}

std::list<Teacher>::iterator System::checkTea(int ID, std::string username, std::string password)
{
	//遍历教师列表并将对应登入的教师的迭代器返回
	for (std::list<Teacher>::iterator it = lt.begin();
		it != lt.end(); it++)
	{
		if (it->GetID() == ID
			&& it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return lt.end();
}

void System::TeaSystem()
{
	int ID;
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "请输入工号:> ";
		checkInput(ID);
		std::cout << "请输入用户名:> ";
		std::cin >> username;
		std::cout << "请输入密码:> ";
		std::cin >> password;
		//检测登入教师的信息是否存在
		std::list<Teacher>::iterator it = checkTea(ID, username, password);
		if (it != lt.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->checkRes(this->ord);				//查看预约
					break;
				case 2:
					it->auditRes(this->ord);				//审核预约
					break;
				case 3:
					it->setPword();							//重新设置密码
					this->save();
					break;
				case 0:
					break;
				default:
					std::cout << "输入错误！" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "用户名或密码错误，请重新登录！" << std::endl;
	}
}

std::list<Admin>::iterator System::checkAdm(std::string username, std::string password)
{
	//遍历管理员列表并将对应登入的管理员的迭代器返回
	for (std::list<Admin>::iterator it = la.begin();
		it != la.end(); it++)
	{
		if (it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return la.end();
}

void System::AdmSystem()
{
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "请输入用户名:> ";
		std::cin >> username;
		std::cout << "请输入密码:> ";
		std::cin >> password;
		//检测登入管理员的信息是否存在
		std::list<Admin>::iterator it = checkAdm(username, password);
		if (it != la.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->checkAccount(ls, lt, la);			//查看账号
					break;
				case 2:
					it->addAccount(ls, lt, la);				//添加账号
					this->save();
					break;
				case 3:
					it->delAccount(ls, lt, la);				//删除账号
					this->save();
					break;
				case 4:
					it->checkComRoom(this->ord);			//查看机房信息
					break;
				case 5:
					it->setComRoom(this->ord);				//更改机房容量
					break;
				case 6:
					it->setPword();							//重新设置密码
					this->save();
					break;
				case 7:
					it->clearRes(this->ord);				//清空预约
					break;
				case 0:
					break;
				default:
					std::cout << "输入错误！" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "用户名或密码错误，请重新登录！" << std::endl;
	}
}

void System::save()
{
	std::ofstream ofs;
	//将学生列表中的信息写入Student.txt文件
	ofs.open("Student.txt", std::ios::out);
	std::list<Student>::iterator it1 = ls.begin();
	while (it1 != ls.end())
	{
		ofs << it1->GetID() << " "
			<< it1->GetUname() << " "
			<< it1->GetPword() << " " << std::endl;
		it1++;
	}
	ofs.close();
	//将教师列表中的信息写入Teacher.txt文件
	ofs.open("Teacher.txt", std::ios::out);
	std::list<Teacher>::iterator it2 = lt.begin();
	while (it2 != lt.end())
	{
		ofs << it2->GetID() << " "
			<< it2->GetUname() << " "
			<< it2->GetPword() << " " << std::endl;
		it2++;
	}
	ofs.close();
	//将管理员列表中的信息写入Admin.txt文件
	ofs.open("Admin.txt", std::ios::out);
	std::list<Admin>::iterator it3 = la.begin();
	while (it3 != la.end())
	{
		ofs << it3->GetUname() << " "
			<< it3->GetPword() << " " << std::endl;
		it3++;
	}
	ofs.close();
}

System::~System()
{
	//保存系统信息并释放内存
	save();
	ls.clear();
	lt.clear();
	la.clear();
}
