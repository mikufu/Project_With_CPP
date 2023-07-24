#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
//总系统
class System
{
public:
	std::list<Student> ls;	//学生列表
	std::list<Teacher> lt;	//教师列表
	std::list<Admin> la;	//管理员列表
	Order ord;				//预约系统

public:
	//初始化系统
	System();
	//主菜单
	void MainMenu();
	//检测学生登入信息
	std::list<Student>::iterator checkStu(int ID, std::string username, std::string password);
	//学生系统
	void StuSystem();
	//检测教师登入信息
	std::list<Teacher>::iterator checkTea(int ID, std::string username, std::string password);
	//教师系统
	void TeaSystem();
	//检测管理员登入信息
	std::list<Admin>::iterator checkAdm(std::string username, std::string password);
	//管理员系统
	void AdmSystem();
	//保存系统信息
	void save();
	//析构总系统
	~System();
};