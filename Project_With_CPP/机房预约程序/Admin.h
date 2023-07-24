#pragma once
#include "Student.h"
#include "Teacher.h"

class Admin : public Identity
{
public:
	//初始化管理员类
	Admin(std::string account, std::string password);
	//管理员菜单
	virtual void showMenu();
	//打印学生账号
	void printAccount(const std::list<Student>& ls);
	//打印教师账号
	void printAccount(const std::list<Teacher>& lt);
	//打印管理员账号
	void printAccount(const std::list<Admin>& la);
	//检查是否账号，并将使用printAccount打印账号信息
	void checkAccount(const std::list<Student>& ls, const std::list<Teacher>& lt, const std::list<Admin>& la);
	//添加账号
	void addAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la);
	//删除账号
	void delAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la);
	//查看机房信息
	void checkComRoom(Order& ord);
	//更改机房容量
	void setComRoom(Order& ord);
	//重新设置密码
	virtual void setPword();
	//清空预约文件
	void clearRes(Order& ord);
	//重载==判断管理员用户名是否重复
	bool operator== (const Admin& a) const;
	//类外获取管理员用户名
	virtual std::string GetUname() const;
	//类外获取管理员密码
	virtual std::string GetPword() const;
};