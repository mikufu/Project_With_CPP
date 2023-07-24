#pragma once
#include "Identity.h"

class Student : public Identity
{
private:
	int m_ID;

public:
	//初始化学生类
	Student(int ID, std::string username, std::string password);
	// 学生菜单
	virtual void showMenu();
	//申请预约
	void applyRes(Order& ord);
	//查看自身的预约
	void checkM_Res(Order& ord);
	//查看所有人的预约
	void checkAllRes(Order& ord);
	//修改预约
	void modifyRes(Order& ord);
	//取消预约
	void cancelRes(Order& ord);
	//重新设置密码
	virtual void setPword();
	//重载==判断学生学号是否重复
	bool operator==(const Student& s) const;
	//类外获取学生的用户名
	virtual std::string GetUname() const;
	//类外获取学生密码
	virtual std::string GetPword() const;
	//类外获取学生学号
	int GetID() const;
};