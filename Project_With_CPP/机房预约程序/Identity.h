#pragma once
#include "Order.h"
//抽象的身份类
class Identity
{
protected:
	std::string m_username;
	std::string m_password;

public:
	virtual void showMenu() = 0;

	virtual void setPword() = 0;

	virtual std::string GetUname() const = 0;

	virtual std::string GetPword() const = 0;
};