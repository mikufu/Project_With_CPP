#pragma once
#include "Identity.h"

class Teacher : public Identity
{
private:
	int m_ID;

public:
	//初始化教师类
	Teacher(int ID, std::string account, std::string password);
	//教师菜单
	virtual void showMenu();
	//查看预约
	void checkRes(Order& ord);
	//审核预约
	void auditRes(Order& ord);
	//重新设置密码
	virtual void setPword();
	//重载==判断教师工号是否重复
	bool operator==(const Teacher& t) const;
	//类外获取教师的用户名
	virtual std::string GetUname() const;
	//类外获取教师密码
	virtual std::string GetPword() const;
	//类外获取教师工号
	int GetID() const;
};