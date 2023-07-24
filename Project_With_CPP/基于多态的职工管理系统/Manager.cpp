#include "Manager.h"

Manager::Manager(int m_ID, string m_name, int m_dID)
{
	this->m_ID = m_ID;
	this->m_name = m_name;
	this->m_dID = m_dID;
}

void Manager::ShowInfo()
{
	cout << "职工编号: " << m_ID
		<< "\t职工姓名: " << m_name
		<< "\t职工职位: " << "经理"
		<< "\t职工职责: " << "将老板布置的任务分配给员工"
		<< endl;
}