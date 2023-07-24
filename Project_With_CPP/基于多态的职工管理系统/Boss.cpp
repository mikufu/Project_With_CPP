#include "Boss.h"

Boss::Boss(int m_ID, string m_name, int m_dID)
{
	this->m_ID = m_ID;
	this->m_name = m_name;
	this->m_dID = m_dID;
}

void Boss::ShowInfo()
{
	cout << "职工编号: " << m_ID
		<< "\t职工姓名: " << m_name
		<< "\t职工职位: " << "老板"
		<< "\t职工职责: " << "管理公司所有事务"
		<< endl;
}